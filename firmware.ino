// ======================================================
// XIAO ML KIT (OR XIAO ESP32S3 SENSE)
// FULL VISION ML  — v44
//
//
// Small Image collection, training, inference for education and proof of concept
//
// SD card stores: images in class folders
// SD card stores: headers in bin and .h text char array format
// Serial monitor and OLED output
// By Jeremy Ellis
// With free tier assistance from: Claude (code overview), ChatGPT (Critique), Gemini (Research) and Copilot (Alternate)
// Use at your own risk!
// MIT license
//
// Github Profile https://github.com/hpssjellis
// LinkedIn https://www.linkedin.com/in/jeremy-ellis-4237a9bb/
//
// For platformio you need the U8g2 library declared in the platformio.ini file and OPI PSRAM set
// lib_deps =  olikraus/U8g2 @ ^2.35.30
// ; Overriding defaults to enable OPI PSRAM
// build_flags = 
//    -DBOARD_HAS_PSRAM
//    -DARDUINO_USB_CDC_ON_BOOT=1
// board_build.arduino.memory_type = qio_opi
// board_build.flash_mode = qio
// board_upload.flash_size = 8MB
//


// ██████████████████████████████████████████████████████████████████████████████
// ██                                                                          ██
// ██  PART 0: CORE SYSTEM (ALWAYS INCLUDED)                                   ██
// ██  Headers, Defines, Pins, Globals, Memory, Weights, Setup, Loop           ██
// ██                                                                          ██
// ██████████████████████████████████████████████████████████████████████████████


// optional Uncomment AFTER copying myWeights.h from SD to your sketch folder:
// Priority order: SD weights > baked-in weights > random He-init
//////////////////////////////////////IMPORTANT/////////////////////////////////////////////////
//#define USE_BAKED_WEIGHTS

#ifdef USE_BAKED_WEIGHTS
  #include "myWeights.h"
#endif

#include "esp_camera.h"
#include "img_converters.h"
#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include <vector>
#include <algorithm>
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_72X40_ER_1_HW_I2C u8g2(U8G2_R2, U8X8_PIN_NONE);

// ======================================================
// CONFIGURATION & ML HYPERPARAMETERS (MOVED UP)
// ======================================================


#define NUM_CLASSES 3

String myClassLabels[NUM_CLASSES] = {"0Blank", "1Cup", "2Pen"};

const int myTotalItems = NUM_CLASSES + 2;      // NUM_CLASSES + 2 for menu training and inference

float LEARNING_RATE = 0.0003;
int BATCH_SIZE = 6;
int TARGET_EPOCHS = 20;
int VALIDATION_IMAGES = 3;  // v44: last N images per class held out for validation (0 = disabled)

const int myThresholdPress = 1100;
const int myThresholdRelease = 900;
//const unsigned long myScreenTimeout = 300000; // not used presently





// ======================================================
// UNIFIED TOUCH INPUT SYSTEM - IMPROVED FOR COMPUTATION
// ======================================================
struct TouchState {
  bool isTouching = false;
  int tapCount = 0;
  unsigned long firstTapTime = 0;
  unsigned long lastReleaseTime = 0;
  unsigned long lastCheckTime = 0;  // NEW: track when we last checked
  const unsigned long tapWindow = 800;        // INCREASED from 450ms for slow contexts
  const int longPressTaps = 3;                // 3+ taps = long press
  const unsigned long debounceDelay = 50;     // debounce time
};


TouchState myTouch;








// SYSTEM LOGIC VARIABLES
unsigned long myLastActivityTime = 0; 
unsigned long myLastTapTime = 0;
const int myTapCooldown = 250;
int myMenuIndex = 1;
bool myIsSelected = false;
bool myWeightsTrained = false; 

// XIAO ESP32-S3 Camera Pins
#define PWDN_GPIO_NUM     -1
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM     10
#define SIOD_GPIO_NUM     40
#define SIOC_GPIO_NUM     39
#define Y9_GPIO_NUM       48
#define Y8_GPIO_NUM       11
#define Y7_GPIO_NUM       12
#define Y6_GPIO_NUM       14
#define Y5_GPIO_NUM       16
#define Y4_GPIO_NUM       18
#define Y3_GPIO_NUM       17
#define Y2_GPIO_NUM       15
#define VSYNC_GPIO_NUM    38
#define HREF_GPIO_NUM     47
#define PCLK_GPIO_NUM     13

// ======================================================
// CONFIGURABLE INPUT RESOLUTION
// ======================================================
#define INPUT_SIZE 64

// ======================================================
// CNN ARCHITECTURE CONSTANTS
// ======================================================
#define CONV1_KERNEL_SIZE 3
#define CONV1_FILTERS 4
#define CONV1_WEIGHTS (CONV1_KERNEL_SIZE * CONV1_KERNEL_SIZE * 3 * CONV1_FILTERS)

#define CONV2_KERNEL_SIZE 3
#define CONV2_FILTERS 8
#define CONV2_WEIGHTS (CONV2_KERNEL_SIZE * CONV2_KERNEL_SIZE * 4 * CONV2_FILTERS)

#define CONV1_OUTPUT_SIZE (INPUT_SIZE - 2)
#define POOL1_OUTPUT_SIZE (CONV1_OUTPUT_SIZE / 2)
#define CONV2_OUTPUT_SIZE (POOL1_OUTPUT_SIZE - 2)
#define FLATTENED_SIZE (CONV2_OUTPUT_SIZE * CONV2_OUTPUT_SIZE * CONV2_FILTERS)

#define OUTPUT_WEIGHTS (FLATTENED_SIZE * NUM_CLASSES)

// ======================================================
// GLOBAL VARIABLE DEFINITIONS
// ======================================================

// Add near line 150 with other global buffers:
uint8_t* myRgbBuffer = nullptr;  // Reusable RGB buffer for inference

bool mySDavailable = false;  // set true in setup() if SD mounts ok

// ML Buffers (PSRAM)
float* myInputBuffer = nullptr;
float* myConv1_w = nullptr;
float* myConv1_b = nullptr;
float* myConv2_w = nullptr;
float* myConv2_b = nullptr;
float* myOutput_w = nullptr;
float* myOutput_b = nullptr;

// Gradient buffers
float* myConv1_w_grad = nullptr;
float* myConv1_b_grad = nullptr;
float* myConv2_w_grad = nullptr;
float* myConv2_b_grad = nullptr;
float* myOutput_w_grad = nullptr;
float* myOutput_b_grad = nullptr;

// Adam optimizer momentum buffers
float* myConv1_w_m = nullptr;
float* myConv1_w_v = nullptr;
float* myConv1_b_m = nullptr;
float* myConv1_b_v = nullptr;
float* myConv2_w_m = nullptr;
float* myConv2_w_v = nullptr;
float* myConv2_b_m = nullptr;
float* myConv2_b_v = nullptr;
float* myOutput_w_m = nullptr;
float* myOutput_w_v = nullptr;
float* myOutput_b_m = nullptr;
float* myOutput_b_v = nullptr;

// Forward pass buffers
float* myConv1_output = nullptr;
float* myPool1_output = nullptr;
float* myConv2_output = nullptr;
float* myDense_output = nullptr;

// Backward pass buffers
float* myDense_grad = nullptr;
float* myConv2_grad = nullptr;
float* myPool1_grad = nullptr;
float* myConv1_grad = nullptr;

struct TrainingItem {
  String path;
  int label;
};
std::vector<TrainingItem> myTrainingData;

// ======================================================
// UTILITY FUNCTIONS
// ======================================================
inline float clip_value(float v, float mn=-100, float mx=100) {
  if(isnan(v)||isinf(v)) return 0;
  return constrain(v,mn,mx);
}

inline float leaky_relu(float x) { return x>0 ? x : 0.1f*x; }
inline float leaky_relu_deriv(float x) { return x>0 ? 1.0f : 0.1f; }

// ======================================================
// UNIFIED TOUCH INPUT FUNCTIONS - NEW!
// ======================================================
int myReadTouch() {
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    sum += analogRead(A0);
    delayMicroseconds(100);
  }
  return sum / 3;
}

void myResetTouchState() {
  myTouch.isTouching = false;
  myTouch.tapCount = 0;
  myTouch.firstTapTime = 0;
  myTouch.lastReleaseTime = 0;
  myTouch.lastCheckTime = 0;
}

// NEW: Background touch monitor that can be called less frequently
void myUpdateTouchState() {
  unsigned long now = millis();
  
  // Only check every 20ms to avoid overwhelming analogRead
  if (now - myTouch.lastCheckTime < 20) return;
  myTouch.lastCheckTime = now;
  
  int val = myReadTouch();
  bool touchActive = myTouch.isTouching 
                      ? (val > myThresholdRelease) 
                      : (val > myThresholdPress);

  // Touch just started
  if (touchActive && !myTouch.isTouching) {
    if (now - myTouch.lastReleaseTime < myTouch.debounceDelay) {
      return; // Debounce
    }
    
    myTouch.isTouching = true;
    
    // First tap or within tap window?
    if (myTouch.tapCount == 0 || (now - myTouch.firstTapTime < myTouch.tapWindow)) {
      if (myTouch.tapCount == 0) {
        myTouch.firstTapTime = now;
      }
      myTouch.tapCount++;
      Serial.printf("Tap #%d\n", myTouch.tapCount);
    } else {
      // Window expired, reset
      myTouch.tapCount = 1;
      myTouch.firstTapTime = now;
      Serial.println("Tap #1 (new window)");
    }
  }
  
  // Touch released
  if (!touchActive && myTouch.isTouching) {
    myTouch.isTouching = false;
    myTouch.lastReleaseTime = now;
  }
}

// Returns: 0=no action, 1=tap, 2=long press (3+ taps)
// NOTE: Always call myUpdateTouchState() before this in tight loops
int myCheckTouchInput() {
  myUpdateTouchState();  // Update state first
  
  unsigned long now = millis();
  
  // Check if tap window expired and we have taps
  if (myTouch.tapCount > 0 && !myTouch.isTouching) {
    if (now - myTouch.firstTapTime > myTouch.tapWindow) {
      int result = (myTouch.tapCount >= myTouch.longPressTaps) ? 2 : 1;
      int count = myTouch.tapCount;
      myResetTouchState();
      
      if (result == 2) {
        Serial.printf("LONG PRESS detected (%d taps)\n", count);
      } else {
        Serial.printf("TAP detected (%d tap%s)\n", count, count > 1 ? "s" : "");
      }
      return result;
    }
  }
  
  return 0;
}

// NEW: Non-blocking check - just updates state without consuming events
// Use this in heavy computation loops
void myCheckTouchBackground() {
  myUpdateTouchState();
}

// NEW: Check if we have a pending action without consuming it
int myPeekTouchAction() {
  myUpdateTouchState();
  unsigned long now = millis();
  
  if (myTouch.tapCount > 0 && !myTouch.isTouching) {
    if (now - myTouch.firstTapTime > myTouch.tapWindow) {
      return (myTouch.tapCount >= myTouch.longPressTaps) ? 2 : 1;
    }
  }
  return 0;
}




// ======================================================
// MEMORY ALLOCATION
// ======================================================
void myAllocateMemory() {
  if (myInputBuffer != nullptr) return;
  
  Serial.println("\n=== Allocating Memory ===");
  
  myInputBuffer = (float*)ps_malloc(INPUT_SIZE * INPUT_SIZE * 3 * sizeof(float));
  myConv1_w = (float*)ps_malloc(CONV1_WEIGHTS * sizeof(float));
  myConv1_b = (float*)ps_malloc(CONV1_FILTERS * sizeof(float));
  myConv2_w = (float*)ps_malloc(CONV2_WEIGHTS * sizeof(float));
  myConv2_b = (float*)ps_malloc(CONV2_FILTERS * sizeof(float));
  myOutput_w = (float*)ps_malloc(OUTPUT_WEIGHTS * sizeof(float));
  myOutput_b = (float*)ps_malloc(NUM_CLASSES * sizeof(float));

  myConv1_w_grad = (float*)ps_malloc(CONV1_WEIGHTS * sizeof(float));
  myConv1_b_grad = (float*)ps_malloc(CONV1_FILTERS * sizeof(float));
  myConv2_w_grad = (float*)ps_malloc(CONV2_WEIGHTS * sizeof(float));
  myConv2_b_grad = (float*)ps_malloc(CONV2_FILTERS * sizeof(float));
  myOutput_w_grad = (float*)ps_malloc(OUTPUT_WEIGHTS * sizeof(float));
  myOutput_b_grad = (float*)ps_malloc(NUM_CLASSES * sizeof(float));

  myConv1_w_m = (float*)ps_calloc(CONV1_WEIGHTS, sizeof(float));
  myConv1_w_v = (float*)ps_calloc(CONV1_WEIGHTS, sizeof(float));
  myConv1_b_m = (float*)ps_calloc(CONV1_FILTERS, sizeof(float));
  myConv1_b_v = (float*)ps_calloc(CONV1_FILTERS, sizeof(float));
  myConv2_w_m = (float*)ps_calloc(CONV2_WEIGHTS, sizeof(float));
  myConv2_w_v = (float*)ps_calloc(CONV2_WEIGHTS, sizeof(float));
  myConv2_b_m = (float*)ps_calloc(CONV2_FILTERS, sizeof(float));
  myConv2_b_v = (float*)ps_calloc(CONV2_FILTERS, sizeof(float));
  myOutput_w_m = (float*)ps_calloc(OUTPUT_WEIGHTS, sizeof(float));
  myOutput_w_v = (float*)ps_calloc(OUTPUT_WEIGHTS, sizeof(float));
  myOutput_b_m = (float*)ps_calloc(NUM_CLASSES, sizeof(float));
  myOutput_b_v = (float*)ps_calloc(NUM_CLASSES, sizeof(float));

  myConv1_output = (float*)ps_malloc(CONV1_OUTPUT_SIZE*CONV1_OUTPUT_SIZE*CONV1_FILTERS*sizeof(float));
  myPool1_output = (float*)ps_malloc(POOL1_OUTPUT_SIZE*POOL1_OUTPUT_SIZE*CONV1_FILTERS*sizeof(float));
  myConv2_output = (float*)ps_malloc(CONV2_OUTPUT_SIZE*CONV2_OUTPUT_SIZE*CONV2_FILTERS*sizeof(float));
  myDense_output = (float*)ps_malloc(NUM_CLASSES*sizeof(float));

  myDense_grad = (float*)ps_malloc(FLATTENED_SIZE*sizeof(float));
  myConv2_grad = (float*)ps_malloc(CONV2_OUTPUT_SIZE*CONV2_OUTPUT_SIZE*CONV2_FILTERS*sizeof(float));
  myPool1_grad = (float*)ps_malloc(POOL1_OUTPUT_SIZE*POOL1_OUTPUT_SIZE*CONV1_FILTERS*sizeof(float));
  myConv1_grad = (float*)ps_malloc(CONV1_OUTPUT_SIZE*CONV1_OUTPUT_SIZE*CONV1_FILTERS*sizeof(float));

  if (!myInputBuffer || !myConv1_w || !myConv2_w || !myOutput_w || 
      !myConv1_output || !myPool1_output || !myConv2_output) {
    Serial.println("FATAL: PSRAM allocation failed!");
    u8g2.firstPage();
    do { u8g2.drawStr(0, 15, "PSRAM ERROR!"); } while (u8g2.nextPage());
    while(1) { delay(1000); }
  }

  Serial.printf("Free PSRAM after allocation: %d bytes\n", ESP.getFreePsram());

  // Initialize weights with He initialization
  float c1std = sqrt(2.0/(9.0*3));
  for(int i=0; i<CONV1_WEIGHTS; i++) myConv1_w[i] = ((float)rand()/RAND_MAX - 0.5f) * 2.0f * c1std;
  for(int i=0; i<CONV1_FILTERS; i++) myConv1_b[i] = 0;
  
  float c2std = sqrt(2.0/36.0);
  for(int i=0; i<CONV2_WEIGHTS; i++) myConv2_w[i] = ((float)rand()/RAND_MAX - 0.5f) * 2.0f * c2std;
  for(int i=0; i<CONV2_FILTERS; i++) myConv2_b[i] = 0;
  
  float dstd = sqrt(2.0/FLATTENED_SIZE);
  for(int i=0; i<OUTPUT_WEIGHTS; i++) myOutput_w[i] = ((float)rand()/RAND_MAX - 0.5f) * 2.0f * dstd;
  for(int i=0; i<NUM_CLASSES; i++) myOutput_b[i] = 0;
  Serial.println("He-init random weights set");
}

// ======================================================
// WEIGHT SAVE/LOAD
// ======================================================
void myExportHeader() {
  if (!mySDavailable) {
    Serial.println("No SD card - cannot export header");
    return;
  }
  if (!SD.exists("/header")) SD.mkdir("/header");
  File file = SD.open("/header/myWeights.h", FILE_WRITE);
  if (!file) return;
  file.println("#ifndef MY_MODEL_H\n#define MY_MODEL_H");
  file.println("// ======================================================");
  file.println("// IMPORTANT: After copying this file to your sketch folder,");
  file.println("// update BOTH of the following lines in your main sketch");
  file.println("// to match the number of classes and labels used during training:");
  file.println("//");
  file.printf( "//   #define NUM_CLASSES %d\n", NUM_CLASSES);

  file.print("//   String myClassLabels[NUM_CLASSES] = {");
  for (int i = 0; i < NUM_CLASSES; i++) {
    file.printf("\"%s\"", myClassLabels[i].c_str());
    if (i < NUM_CLASSES - 1) file.print(", ");
  }
  file.println("};");

 // file.println("//   String myClassLabels[NUM_CLASSES] = {\"0Blank\", \"1Cup\", \"2Pen\", ...};");
  file.println("//");
  file.println("// Then uncomment:  #define USE_BAKED_WEIGHTS");
  file.println("// ======================================================");
  auto myDump = [&](const char* name, float* data, int size) {
    file.printf("const float %s[] = { ", name);
    for(int i=0; i<size; i++) {
      file.print(data[i], 6); file.print("f");
      if(i < size-1) file.print(", ");
      if((i+1)%8 == 0) file.println();
    }
    file.println(" };");
  };
  myDump("myModel_conv1_w",  myConv1_w,  CONV1_WEIGHTS);
  myDump("myModel_conv1_b",  myConv1_b,  CONV1_FILTERS);
  myDump("myModel_conv2_w",  myConv2_w,  CONV2_WEIGHTS);
  myDump("myModel_conv2_b",  myConv2_b,  CONV2_FILTERS);
  myDump("myModel_output_w", myOutput_w, OUTPUT_WEIGHTS);
  myDump("myModel_output_b", myOutput_b, NUM_CLASSES);
  file.println("#endif");
  Serial.println("You can copy /header/myWeights.h to the sketch folder, then uncomment #define USE_BAKED_WEIGHTS");
  file.close();
}

bool myLoadWeights() {
  if (!mySDavailable) {
    Serial.println("No SD card - skipping weight load");
    return false;
  }
  if (!SD.exists("/header/myWeights.bin")) {
    Serial.println("No SD weights file found");
    return false;
  }
  Serial.println("Loading weights from SD...");
  File f = SD.open("/header/myWeights.bin", FILE_READ);
  if (!f) return false;
  f.read((uint8_t*)myConv1_w, CONV1_WEIGHTS*4); 
  f.read((uint8_t*)myConv1_b, CONV1_FILTERS*4);
  f.read((uint8_t*)myConv2_w, CONV2_WEIGHTS*4); 
  f.read((uint8_t*)myConv2_b, CONV2_FILTERS*4);
  f.read((uint8_t*)myOutput_w, OUTPUT_WEIGHTS*4); 
  f.read((uint8_t*)myOutput_b, NUM_CLASSES*4);
  f.close();
  Serial.println("Weights loaded successfully");
  myWeightsTrained = true;
  return true;
}

void mySaveWeights() {
  if (!mySDavailable) {
    Serial.println("No SD card - cannot save weights");
    return;
  }
  if (!SD.exists("/header")) SD.mkdir("/header");
  File f = SD.open("/header/myWeights.bin", FILE_WRITE);
  if (f) {
    f.write((uint8_t*)myConv1_w, CONV1_WEIGHTS*4); 
    f.write((uint8_t*)myConv1_b, CONV1_FILTERS*4);
    f.write((uint8_t*)myConv2_w, CONV2_WEIGHTS*4); 
    f.write((uint8_t*)myConv2_b, CONV2_FILTERS*4);
    f.write((uint8_t*)myOutput_w, OUTPUT_WEIGHTS*4); 
    f.write((uint8_t*)myOutput_b, NUM_CLASSES*4);
    f.close();
    Serial.println("Weights saved to SD");
  }
  myExportHeader();
}

// ======================================================
// IMAGE LOADING FROM SD
// ======================================================
bool myLoadImageFromFile(const char* path, float* buf) {
  File f = SD.open(path);
  if(!f) return false;
  
  size_t sz = f.size();
  uint8_t* jpg = (uint8_t*)ps_malloc(sz);
  if(!jpg) { f.close(); return false; }
  f.read(jpg, sz);
  f.close();
  
  // v43 FIX 3: Use the pre-allocated global myRgbBuffer instead of allocating
  // 172KB of PSRAM on every single image load. The old code did ps_malloc(240*240*3)
  // here which was slow, fragmented PSRAM, and is why touch/serial felt unresponsive.
  if(!myRgbBuffer) { free(jpg); return false; }
  
  bool ok = fmt2rgb888(jpg, sz, PIXFORMAT_JPEG, myRgbBuffer);
  free(jpg);
  if(!ok) return false;
  
  for(int y=0; y<INPUT_SIZE; y++) {
    for(int x=0; x<INPUT_SIZE; x++) {
      int sy = (int)((y+0.5)*240.0/INPUT_SIZE);
      int sx = (int)((x+0.5)*240.0/INPUT_SIZE);
      if(sy>239) sy=239;
      if(sx>239) sx=239;
      int srcIdx = (sy*240 + sx)*3;
      int dstIdx = (y*INPUT_SIZE + x)*3;
      buf[dstIdx]   = myRgbBuffer[srcIdx]   / 255.0f;
      buf[dstIdx+1] = myRgbBuffer[srcIdx+1] / 255.0f;
      buf[dstIdx+2] = myRgbBuffer[srcIdx+2] / 255.0f;
    }
  }
  return true;
}

// ======================================================
// PART 0: SETUP AND LOOP
// ======================================================

// Forward declarations for functions defined in other parts
void myActionCollect(int classIdx);
void myActionTrain();
void myActionInfer();
void myResetMenuState();
void myHandleMenuNavigation();
void myDrawMenu();

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 3000); 
  delay(1000);  // slow down the startup
  
  Serial.println("\n=== XIAO ESP32-S3 ML System Starting ===");
  Serial.printf("Free heap: %d bytes\n", ESP.getFreeHeap());
  Serial.printf("Free PSRAM: %d bytes\n", ESP.getFreePsram());
  
// Add in setup() function:
myRgbBuffer = (uint8_t*)ps_malloc(240*240*3);
if (!myRgbBuffer) {
  Serial.println("Failed to allocate RGB buffer!");
}

  pinMode(A0, INPUT);
  u8g2.begin();
  
// Manual SPI init with timeout to prevent hang when no SD card present
  pinMode(21, OUTPUT);
  digitalWrite(21, HIGH);
  delay(100);

  Serial.println("Checking SD card...");
  SPI.begin();
  SPI.setFrequency(400000);  // slow speed for init
  
  mySDavailable = SD.begin(21, SPI, 400000, "/sd", 5, false);
  
  if (!mySDavailable) {
      SD.end();   // instead of SPI.end()
    Serial.println("No SD card - continuing without it");
    u8g2.firstPage();
    do { u8g2.drawStr(0, 15, "No SD card"); } while (u8g2.nextPage());
    delay(2000);
  } else {
    Serial.println("SD card mounted successfully");
  }

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM; config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM; config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM; config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM; config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM; config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM; config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM; config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM; config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000; config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_240X240; config.jpeg_quality = 12;
  config.fb_count = 1;     // 2
  esp_camera_init(&config);
  Serial.println("Camera initialized");
  sensor_t * s = esp_camera_sensor_get();
    if (s != NULL) {
     // s->set_vflip(s, 1);    // 1 = Flip vertically (Upside Down)
      s->set_hmirror(s, 1);  // 1 = Mirror horizontally
    }

  // ESP-IDF Log Levels (ordered least to most verbose):
  //   ESP_LOG_NONE    (0) — no output at all
  //   ESP_LOG_WARN    (2) — errors + W(...) warnings
  //   ESP_LOG_VERBOSE (5) — + V(...) everything

  // Set globally first, then override specific tags as needed:
  esp_log_level_set("*", ESP_LOG_WARN);           // suppress INFO spam globally
  esp_log_level_set("esp_camera", ESP_LOG_ERROR); // suppress FB_OVF (WARN level)

  myAllocateMemory();  // allocates PSRAM and sets random He-init weights

#ifdef USE_BAKED_WEIGHTS
  memcpy(myConv1_w,  myModel_conv1_w,  CONV1_WEIGHTS  * sizeof(float));
  memcpy(myConv1_b,  myModel_conv1_b,  CONV1_FILTERS  * sizeof(float));
  memcpy(myConv2_w,  myModel_conv2_w,  CONV2_WEIGHTS  * sizeof(float));
  memcpy(myConv2_b,  myModel_conv2_b,  CONV2_FILTERS  * sizeof(float));
  memcpy(myOutput_w, myModel_output_w, OUTPUT_WEIGHTS * sizeof(float));
  memcpy(myOutput_b, myModel_output_b, NUM_CLASSES    * sizeof(float));
  Serial.println("Baked-in weights loaded from myModel.h");
  myWeightsTrained = true; 
#endif

  if (myLoadWeights()) {
    Serial.println("SD weights loaded - overriding baked-in weights");
  }


  myLastActivityTime = millis();
  myResetMenuState();
  delay(2000);  // time to get things started like the serial monitor

  Serial.println("System ready - Tap A0 to navigate, 3+ taps to select");
  myDrawMenu();

}

void loop() {
  
  myHandleMenuNavigation();
}



// ██████████████████████████████████████████████████████████████████████████████
// ██                                                                          ██
// ██  PART 1: IMAGE COLLECTION FUNCTIONS                                      ██
// ██                                                                          ██
// ██  DEPENDENCIES (functions called from Part 0):                            ██
// ██  - myResetMenuState()                     [Part 4]                       ██
// ██  - myReadTouch()                          [Part 4]                       ██
// ██                                                                          ██
// ██  VARIABLES USED (defined in Part 0):                                     ██
// ██  - myClassLabels[NUM_CLASSES], myThresholdPress, myLongPressTime                   ██
// ██  - u8g2 (OLED display object)                                            ██
// ██                                                                          ██
// ██████████████████████████████████████████████████████████████████████████████


// ======================================================
// SHARED OLED RENDER HELPER
// Renders myRgbBuffer (must already be filled) to OLED.
// imageCount >= 0  -> show count badge (post-capture mode)
// imageCount == -1 -> show LIVE badge (preview mode)
// ======================================================
void myRenderRgbToOLED(int imageCount) {
  int myOledWidth  = u8g2.getDisplayWidth();
  int myOledHeight = u8g2.getDisplayHeight();
  int myScaleX = 240 / myOledWidth;
  int myScaleY = 240 / myOledHeight;

  u8g2.firstPage();
  do {
    for (int myOledX = 0; myOledX < myOledWidth; myOledX++) {
      for (int myOledY = 0; myOledY < myOledHeight; myOledY++) {
        size_t myPixelIndex = ((myOledY * myScaleY) * 240 + (myOledX * myScaleX)) * 3;
        uint8_t myBrightness = (myRgbBuffer[myPixelIndex]     +
                                myRgbBuffer[myPixelIndex + 1] +
                                myRgbBuffer[myPixelIndex + 2]) / 3;
        if (myBrightness > 100) u8g2.drawPixel(myOledX, myOledY);
      }
    }
    if (imageCount >= 0) {
      // Post-capture: count badge top-left
      u8g2.setFont(u8g2_font_ncenB10_tr);
      u8g2.setColorIndex(0);
      u8g2.drawBox(0, 0, 20, 15);
      u8g2.setColorIndex(1);
      u8g2.setCursor(3, 10);
      u8g2.print(String(imageCount));
    } else {
      // Live preview: LIVE badge top-right
      u8g2.setFont(u8g2_font_5x7_tf);
      u8g2.setColorIndex(0);
      u8g2.drawBox(50, 0, 22, 8);
      u8g2.setColorIndex(1);
      u8g2.drawStr(52, 7, "LIVE");
    }
  } while (u8g2.nextPage());
}

// Post-capture snapshot: convert fb -> myRgbBuffer then render with count badge
void myDisplayImageOnOLED(camera_fb_t* fb, int imageCount) {
  if (!myRgbBuffer) {
    Serial.println("RGB buffer not allocated - skipping OLED preview");
    return;
  }
  if (!fmt2rgb888(fb->buf, fb->len, fb->format, myRgbBuffer)) {
    Serial.println("Failed to convert JPEG to RGB888 for OLED");
    return;
  }
  myRenderRgbToOLED(imageCount);
}


void myActionCollect(int classIdx) {
  if (!mySDavailable) {
    Serial.println("No SD card - cannot collect images");
    u8g2.firstPage();
    do { u8g2.drawStr(0, 15, "No SD card"); } while (u8g2.nextPage());
    delay(2000);
    myResetMenuState();
    return;
  }

  Serial.printf("\n>>> Collection mode: %s\n", myClassLabels[classIdx].c_str());
  Serial.println("Instructions:");
  Serial.println("  TAP (1-2 taps) = Capture image");
  Serial.println("  LONG PRESS (3+ taps) = Exit to menu");
  Serial.println("  Serial: 'T'=capture, 'L'=exit");
  
  myResetTouchState();  // Clear touch state when entering
  
  String path = "/images/" + myClassLabels[classIdx];
  if (!SD.exists("/images")) SD.mkdir("/images");
  if (!SD.exists(path)) SD.mkdir(path);


  // Count only the active class — no need to scan all folders on menu entry
  int counts[NUM_CLASSES] = {};
  File root = SD.open("/images/" + myClassLabels[classIdx]);
  if(root) {
    while(File file = root.openNextFile()) {
      if(!file.isDirectory() && (String(file.name()).endsWith(".jpg") || 
        String(file.name()).endsWith(".JPG"))) {
        counts[classIdx]++;
      }
      file.close();
    }
    root.close();
  }

  unsigned long lastCameraDrain = 0;  // how often we service the camera buffer
  unsigned long lastOLED = 0;         // how often we actually update the OLED
  bool oledNeedsUpdate = false;
  bool shouldCapture = false;

  while (true) {
    unsigned long now = millis();

    // --- FAST LOOP: drain camera buffer every 50ms to prevent FB-OVF ---
    if (now - lastCameraDrain > 50) {
      lastCameraDrain = now;

      if (!shouldCapture) {  // don't grab preview frames if a capture is pending
        camera_fb_t* fb = esp_camera_fb_get();
        if (fb) {
          // Only pay for RGB conversion when the OLED is due for a refresh (250ms)
          if (now - lastOLED > 250 && myRgbBuffer) {
            if (fmt2rgb888(fb->buf, fb->len, fb->format, myRgbBuffer)) {
              oledNeedsUpdate = true;
              lastOLED = now;
            }
          }
          esp_camera_fb_return(fb);
        }
      }
    }

    // --- SLOW LOOP: render to OLED only when fresh RGB is ready ---
    if (oledNeedsUpdate) {
      oledNeedsUpdate = false;
      myRenderRgbToOLED(-1);  // -1 = show LIVE badge
    }

    // --- SERIAL INPUT ---
    if (Serial.available()) {
      char c = Serial.read();
      if (c == 'l' || c == 'L') {
        myResetMenuState();
        return;
      } else if (c == 't' || c == 'T') {
        shouldCapture = true;
      }
    }

    // --- TOUCH INPUT - unified system ---
    int touchAction = myCheckTouchInput();
    if (touchAction == 2) {
      // Long press (3+ taps) - exit
      Serial.println("Exiting collection mode");
      myResetMenuState();
      return;
    } else if (touchAction == 1) {
      // Tap (1-2 taps) - capture
      shouldCapture = true;
    }

    // --- CAPTURE ---
    if (shouldCapture) {
      shouldCapture = false;
      camera_fb_t* fb = esp_camera_fb_get();
      if (fb) {
        String fileName = path + "/img_" + String(millis()) + ".jpg";
        File file = SD.open(fileName, FILE_WRITE);
        if (file) {
          file.write(fb->buf, fb->len);
          file.close();
          counts[classIdx]++;
          Serial.printf("Saved: %s (Total: %d)\n", fileName.c_str(), counts[classIdx]);
          myDisplayImageOnOLED(fb, counts[classIdx]);  // shows count badge
          delay(300);
          lastOLED = millis();  // don't immediately overwrite the snapshot with LIVE
        }
        esp_camera_fb_return(fb);
      }
    }

    delay(5);
  }
}

// ██████████████████████████████████████████████████████████████████████████████
// ██                                                                          ██
// ██  PART 2: TRAINING FUNCTIONS (FORWARD/BACKWARD PASS, OPTIMIZER)           ██
// ██                                                                          ██
// ██  DEPENDENCIES (functions called from Part 0):                            ██
// ██  - myAllocateMemory()                     [Part 0]                       ██
// ██  - myLoadWeights()                        [Part 0]                       ██
// ██  - mySaveWeights()                        [Part 0]                       ██
// ██  - myLoadImageFromFile()                  [Part 0]                       ██
// ██                                                                          ██
// ██  VARIABLES USED (defined in Part 0):                                     ██
// ██  - All neural network weight/gradient buffers                            ██
// ██  - myClassLabels[NUM_CLASSES], LEARNING_RATE, BATCH_SIZE, TARGET_EPOCHS            ██
// ██  - myTrainingData vector, myInputBuffer                                  ██
// ██  - u8g2 (OLED display object)                                            ██
// ██                                                                          ██
// ██████████████████████████████████████████████████████████████████████████████


// ======================================================
// FORWARD PASS
// ======================================================
void myForwardPass(float* input, float* logits) {
  // Conv1: INPUT_SIZE x INPUT_SIZE x 3 -> CONV1_OUTPUT_SIZE x CONV1_OUTPUT_SIZE x CONV1_FILTERS
  for(int f=0; f<CONV1_FILTERS; f++) {
    int ob = f*CONV1_OUTPUT_SIZE*CONV1_OUTPUT_SIZE;
    for(int y=0; y<CONV1_OUTPUT_SIZE; y++) {
      for(int x=0; x<CONV1_OUTPUT_SIZE; x++) {
        float sum = 0;
        for(int ky=0; ky<3; ky++) {
          for(int kx=0; kx<3; kx++) {
            int inPos = ((y+ky)*INPUT_SIZE+(x+kx))*3;
            int wPos = f*27 + ky*9 + kx*3;
            sum += input[inPos]*myConv1_w[wPos] + 
                   input[inPos+1]*myConv1_w[wPos+1] + 
                   input[inPos+2]*myConv1_w[wPos+2];
          }
        }
        myConv1_output[ob + y*CONV1_OUTPUT_SIZE + x] = leaky_relu(clip_value(sum + myConv1_b[f]));
      }
    }
  }
  
  // Pool1: CONV1_OUTPUT_SIZE x CONV1_OUTPUT_SIZE -> POOL1_OUTPUT_SIZE x POOL1_OUTPUT_SIZE
  for(int f=0; f<CONV1_FILTERS; f++) {
    int ib=f*CONV1_OUTPUT_SIZE*CONV1_OUTPUT_SIZE, ob=f*POOL1_OUTPUT_SIZE*POOL1_OUTPUT_SIZE;
    for(int y=0; y<POOL1_OUTPUT_SIZE; y++) {
      for(int x=0; x<POOL1_OUTPUT_SIZE; x++) {
        int iy=y*2, ix=x*2;
        float maxVal = myConv1_output[ib + iy*CONV1_OUTPUT_SIZE + ix];
        maxVal = max(maxVal, myConv1_output[ib + iy*CONV1_OUTPUT_SIZE + ix+1]);
        maxVal = max(maxVal, myConv1_output[ib + (iy+1)*CONV1_OUTPUT_SIZE + ix]);
        maxVal = max(maxVal, myConv1_output[ib + (iy+1)*CONV1_OUTPUT_SIZE + ix+1]);
        myPool1_output[ob + y*POOL1_OUTPUT_SIZE + x] = maxVal;
      }
    }
  }
  
  // Conv2: POOL1_OUTPUT_SIZE x POOL1_OUTPUT_SIZE x CONV1_FILTERS -> CONV2_OUTPUT_SIZE x CONV2_OUTPUT_SIZE x CONV2_FILTERS
  for(int f=0; f<CONV2_FILTERS; f++) {
    int ob=f*CONV2_OUTPUT_SIZE*CONV2_OUTPUT_SIZE;
    for(int y=0; y<CONV2_OUTPUT_SIZE; y++) {
      for(int x=0; x<CONV2_OUTPUT_SIZE; x++) {
        float sum = 0;
        for(int c=0; c<CONV1_FILTERS; c++) {
          int ib=c*POOL1_OUTPUT_SIZE*POOL1_OUTPUT_SIZE;
          for(int ky=0; ky<3; ky++) {
            for(int kx=0; kx<3; kx++) {
              sum += myPool1_output[ib + (y+ky)*POOL1_OUTPUT_SIZE + (x+kx)] * 
                     myConv2_w[f*36 + c*9 + ky*3 + kx];
            }
          }
        }
        myConv2_output[ob + y*CONV2_OUTPUT_SIZE + x] = leaky_relu(clip_value(sum + myConv2_b[f]));
      }
    }
  }
  
  // Dense layer
  for(int c=0; c<NUM_CLASSES; c++) {
    double sum = 0, comp = 0;
    for(int i=0; i<FLATTENED_SIZE; i++) {
      double term = myConv2_output[i] * myOutput_w[c*FLATTENED_SIZE + i];
      double y = term - comp;
      double t = sum + y;
      comp = (t - sum) - y;
      sum = t;
    }
    myDense_output[c] = clip_value((float)sum + myOutput_b[c], -50, 50);
  }
  
  // Softmax
  float mx = myDense_output[0];
  for(int i=1; i<NUM_CLASSES; i++) mx = max(mx, myDense_output[i]);
  float expSum = 0;
  for(int i=0; i<NUM_CLASSES; i++) expSum += exp(myDense_output[i]-mx);
  for(int i=0; i<NUM_CLASSES; i++) {
    logits[i] = myDense_output[i];
    myDense_output[i] = exp(myDense_output[i]-mx) / expSum;
  }
}

// ======================================================
// BACKWARD PASS
// ======================================================
void myBackwardDense(int label) {
  // v43 FIX 1: myDense_grad is a per-image propagation signal — zero it fresh each image.
  // myOutput_w_grad and myOutput_b_grad use += so all images in the batch accumulate.
  // (Batch-level zeroing of those buffers is done once at the start of each batch loop.)
  memset(myDense_grad, 0, FLATTENED_SIZE * sizeof(float));
  for(int c=0; c<NUM_CLASSES; c++) {
    float error = myDense_output[c] - (c==label ? 1.0f : 0.0f);
    for(int i=0; i<FLATTENED_SIZE; i++) {
      myOutput_w_grad[c*FLATTENED_SIZE+i] += error * myConv2_output[i];  // v43: += accumulates
      myDense_grad[i] += error * myOutput_w[c*FLATTENED_SIZE+i];
    }
    myOutput_b_grad[c] += error;  // v43: += accumulates
  }
}

void myBackwardConv2() {
  for(int i=0; i<FLATTENED_SIZE; i++) {
    myConv2_grad[i] = myDense_grad[i] * leaky_relu_deriv(myConv2_output[i]);
  }
  
  // v43 FIX 1: myConv2_w_grad and myConv2_b_grad are weight accumulators — do NOT zero
  // them here; the batch-level memset at the start of the batch loop handles that.
  // myPool1_grad IS zeroed here because it is a per-image propagation signal.
  memset(myPool1_grad, 0, POOL1_OUTPUT_SIZE*POOL1_OUTPUT_SIZE*CONV1_FILTERS*sizeof(float));
  
  for(int f=0; f<CONV2_FILTERS; f++) {
    int ob=f*CONV2_OUTPUT_SIZE*CONV2_OUTPUT_SIZE;
    for(int y=0; y<CONV2_OUTPUT_SIZE; y++) {
      for(int x=0; x<CONV2_OUTPUT_SIZE; x++) {
        float grad = myConv2_grad[ob+y*CONV2_OUTPUT_SIZE+x];
        myConv2_b_grad[f] += grad;
        for(int c=0; c<CONV1_FILTERS; c++) {
          int ib=c*POOL1_OUTPUT_SIZE*POOL1_OUTPUT_SIZE;
          for(int ky=0; ky<3; ky++) {
            for(int kx=0; kx<3; kx++) {
              int pi = ib+(y+ky)*POOL1_OUTPUT_SIZE+(x+kx);
              int wi = f*36+c*9+ky*3+kx;
              myConv2_w_grad[wi] += grad * myPool1_output[pi];
              myPool1_grad[pi] += grad * myConv2_w[wi];
            }
          }
        }
      }
    }
  }
}

void myBackwardPool1() {
  memset(myConv1_grad, 0, CONV1_OUTPUT_SIZE*CONV1_OUTPUT_SIZE*CONV1_FILTERS*sizeof(float));
  for(int f=0; f<CONV1_FILTERS; f++) {
    int ib=f*CONV1_OUTPUT_SIZE*CONV1_OUTPUT_SIZE, ob=f*POOL1_OUTPUT_SIZE*POOL1_OUTPUT_SIZE;
    for(int y=0; y<POOL1_OUTPUT_SIZE; y++) {
      for(int x=0; x<POOL1_OUTPUT_SIZE; x++) {
        int iy=y*2, ix=x*2;
        float poolVal = myPool1_output[ob+y*POOL1_OUTPUT_SIZE+x];
        float grad = myPool1_grad[ob+y*POOL1_OUTPUT_SIZE+x];
        if(myConv1_output[ib+iy*CONV1_OUTPUT_SIZE+ix] == poolVal) myConv1_grad[ib+iy*CONV1_OUTPUT_SIZE+ix] += grad;
        if(myConv1_output[ib+iy*CONV1_OUTPUT_SIZE+ix+1] == poolVal) myConv1_grad[ib+iy*CONV1_OUTPUT_SIZE+ix+1] += grad;
        if(myConv1_output[ib+(iy+1)*CONV1_OUTPUT_SIZE+ix] == poolVal) myConv1_grad[ib+(iy+1)*CONV1_OUTPUT_SIZE+ix] += grad;
        if(myConv1_output[ib+(iy+1)*CONV1_OUTPUT_SIZE+ix+1] == poolVal) myConv1_grad[ib+(iy+1)*CONV1_OUTPUT_SIZE+ix+1] += grad;
      }
    }
  }
}

void myBackwardConv1() {
  for(int i=0; i<CONV1_OUTPUT_SIZE*CONV1_OUTPUT_SIZE*CONV1_FILTERS; i++) {
    myConv1_grad[i] *= leaky_relu_deriv(myConv1_output[i]);
  }
  
  // v43 FIX 1: myConv1_w_grad and myConv1_b_grad are weight accumulators — do NOT zero
  // them here; the batch-level memset at the start of the batch loop handles that.
  
  for(int f=0; f<CONV1_FILTERS; f++) {
    int ob=f*CONV1_OUTPUT_SIZE*CONV1_OUTPUT_SIZE;
    for(int y=0; y<CONV1_OUTPUT_SIZE; y++) {
      for(int x=0; x<CONV1_OUTPUT_SIZE; x++) {
        float grad = myConv1_grad[ob+y*CONV1_OUTPUT_SIZE+x];
        myConv1_b_grad[f] += grad;
        
        for(int ky=0; ky<3; ky++) {
          for(int kx=0; kx<3; kx++) {
            int inPos = ((y+ky)*INPUT_SIZE+(x+kx))*3;
            int wPos = f*27 + ky*9 + kx*3;
            myConv1_w_grad[wPos] += grad * myInputBuffer[inPos];
            myConv1_w_grad[wPos+1] += grad * myInputBuffer[inPos+1];
            myConv1_w_grad[wPos+2] += grad * myInputBuffer[inPos+2];
          }
        }
      }
    }
  }
}

// ======================================================
// OPTIMIZER
// ======================================================
void myAdamUpdate(float* w, float* g, float* m, float* v, int size, int step) {
  float b1=0.9f, b2=0.999f, eps=1e-6f;  // v43 FIX 2: eps 1e-8->1e-6f (float32 NaN prevention)
  float lr_t = LEARNING_RATE * sqrt(1-pow(b2,step)) / (1-pow(b1,step));
  for(int i=0; i<size; i++) {
    m[i] = b1*m[i] + (1-b1)*g[i];
    v[i] = b2*v[i] + (1-b2)*g[i]*g[i];
    w[i] -= lr_t*m[i]/(sqrt(v[i])+eps);
    w[i] = clip_value(w[i], -10, 10);
  }
}

void myUpdateWeights(int step) {
  myAdamUpdate(myConv1_w, myConv1_w_grad, myConv1_w_m, myConv1_w_v, CONV1_WEIGHTS, step);
  myAdamUpdate(myConv1_b, myConv1_b_grad, myConv1_b_m, myConv1_b_v, CONV1_FILTERS, step);
  myAdamUpdate(myConv2_w, myConv2_w_grad, myConv2_w_m, myConv2_w_v, CONV2_WEIGHTS, step);
  myAdamUpdate(myConv2_b, myConv2_b_grad, myConv2_b_m, myConv2_b_v, CONV2_FILTERS, step);
  myAdamUpdate(myOutput_w, myOutput_w_grad, myOutput_w_m, myOutput_w_v, OUTPUT_WEIGHTS, step);
  myAdamUpdate(myOutput_b, myOutput_b_grad, myOutput_b_m, myOutput_b_v, NUM_CLASSES, step);
}

// ======================================================
// TRAINING FUNCTION
// ======================================================


void myActionTrain() {
  if (!mySDavailable) {
    Serial.println("No SD card - cannot train");
    u8g2.firstPage();
    do { u8g2.drawStr(0, 15, "No SD card"); } while (u8g2.nextPage());
    delay(2000);
    myResetMenuState();
    return;
  }

  Serial.println("\n>>> Training mode");
  Serial.println("Instructions:");
  Serial.println("  During training: 3+ taps = Save and exit");
  Serial.println("  After completion: TAP = Train again, 3+ taps = Exit");
  Serial.println("  Serial: 'T'=train again, 'L'=exit");
  
  myResetTouchState();  // Clear touch state when entering

  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(0, 12, "TRAINING MODE");
    u8g2.drawStr(0, 24, "Loading...");
  } while (u8g2.nextPage());
  
  if (myLoadWeights()) {
    Serial.println("Continuing from saved weights");
  } else {
    //myAllocateMemory();
    Serial.println("Starting fresh training");
  }

  while (true) {
    // Load training data
    myTrainingData.clear();
    for(int i=0; i<NUM_CLASSES; i++) {
      File root = SD.open("/images/" + myClassLabels[i]);
      if (root) {
        while(File file = root.openNextFile()) {
          if(!file.isDirectory()) {
            String fn = String(file.name());
            if(fn.endsWith(".jpg") || fn.endsWith(".JPG")) {
              myTrainingData.push_back({file.path(), i});
            }
          }
          file.close();
        }
        root.close();
      }
    }
    
    if(myTrainingData.empty()) { 
      u8g2.firstPage();
      do { u8g2.drawStr(0, 20, "No Images!"); } while (u8g2.nextPage());
      delay(2000);
      myResetMenuState();
      return; 
    }

    // v44: Sort by path for a deterministic split, then hold out the last
    // VALIDATION_IMAGES images per class as a validation set.
    std::sort(myTrainingData.begin(), myTrainingData.end(),
              [](const TrainingItem& a, const TrainingItem& b){ return a.path < b.path; });

    std::vector<TrainingItem> myValidationData;
    if (VALIDATION_IMAGES > 0) {
      int counts[NUM_CLASSES] = {};
      for (auto& item : myTrainingData) counts[item.label]++;
      int skip[NUM_CLASSES];
      for (int c = 0; c < NUM_CLASSES; c++) skip[c] = min(VALIDATION_IMAGES, counts[c]);

      std::vector<TrainingItem> trainOnly;
      int seen[NUM_CLASSES] = {};
      for (int i = (int)myTrainingData.size() - 1; i >= 0; i--) {
        int c = myTrainingData[i].label;
        if (seen[c] < skip[c]) {
          myValidationData.push_back(myTrainingData[i]);
          seen[c]++;
        } else {
          trainOnly.push_back(myTrainingData[i]);
        }
      }
      myTrainingData = trainOnly;
      Serial.printf("Val: %d images  Train: %d images\n",
                    (int)myValidationData.size(), (int)myTrainingData.size());
    }

    int total = myTrainingData.size();
    int batchesPerEpoch = (total + BATCH_SIZE - 1) / BATCH_SIZE;
    int totalBatches = TARGET_EPOCHS * batchesPerEpoch;
    
    Serial.printf("Training: %d images, %d batches\n", total, totalBatches);
    
    // Training loop
    std::vector<int> indices;
    for(int i=0; i<total; i++) indices.push_back(i);
    
    float runningLoss = 0;
    int lossCount = 0;
    
    for(int batch=0; batch<totalBatches; batch++) {
      // Check for exit during training
      if (Serial.available()) {
        char c = Serial.read();
        // v43 FIX 4: accept 'l'/'L' as well as 'x'/'X' — consistent with all other modes
        if (c == 'x' || c == 'X' || c == 'l' || c == 'L') {
          Serial.println("Stopping training...");
          mySaveWeights();
          myWeightsTrained = true; 
          myResetMenuState();
          return;
        }
      }
      
      // Touch input during training - check in background
      myCheckTouchBackground();  // Update touch state without blocking
      if (myPeekTouchAction() == 2) {
        myCheckTouchInput();  // Consume the action
        Serial.println("Long press - stopping training");
        mySaveWeights();
        myWeightsTrained = true; 
        myResetMenuState();
        return;
      }
      
      // Shuffle at epoch start
      if(batch % batchesPerEpoch == 0) {
        int epoch = batch/batchesPerEpoch + 1;
        Serial.printf("\n--- Epoch %d/%d ---\n", epoch, TARGET_EPOCHS);
        for(int i=total-1; i>0; i--) {
          int j = random(i+1);
          int tmp = indices[i];
          indices[i] = indices[j];
          indices[j] = tmp;
        }
      }
      
      int batchStart = (batch % batchesPerEpoch) * BATCH_SIZE;
      int batchEnd = min(batchStart + BATCH_SIZE, total);
      
      float batchLoss = 0;
      int correctCount = 0;
      
      // v43 FIX 1: Zero ALL weight gradient buffers once per batch before accumulating.
      // This replaces the per-function memsets that were incorrectly resetting grads
      // between images mid-batch in v42.
      memset(myConv1_w_grad,  0, CONV1_WEIGHTS  * sizeof(float));
      memset(myConv1_b_grad,  0, CONV1_FILTERS  * sizeof(float));
      memset(myConv2_w_grad,  0, CONV2_WEIGHTS  * sizeof(float));
      memset(myConv2_b_grad,  0, CONV2_FILTERS  * sizeof(float));
      memset(myOutput_w_grad, 0, OUTPUT_WEIGHTS * sizeof(float));
      memset(myOutput_b_grad, 0, NUM_CLASSES    * sizeof(float));
      
      // Train on batch
      for(int i=batchStart; i<batchEnd; i++) {
        int idx = indices[i];
        TrainingItem& img = myTrainingData[idx];
        
        if(!myLoadImageFromFile(img.path.c_str(), myInputBuffer)) continue;
        
        float logits[NUM_CLASSES];
        myForwardPass(myInputBuffer, logits);
        
        float loss = -log(max(myDense_output[img.label], 1e-7f));
        batchLoss += loss;
        
        int pred = 0;
        for(int j=1; j<NUM_CLASSES; j++) if(myDense_output[j] > myDense_output[pred]) pred = j;
        if(pred == img.label) correctCount++;
        
        myBackwardDense(img.label);
        myBackwardConv2();
        myBackwardPool1();
        myBackwardConv1();
        
        // Update touch state during heavy computation
        // v43 FIX 5: also peek for action here so a tap exits within one image,
        // not at the end of the entire batch (which can be a 5-15 second wait)
        if (i % 3 == 0) {
          myCheckTouchBackground();
          if (myPeekTouchAction() == 2) {
            myCheckTouchInput();  // consume
            Serial.println("Long press - stopping training");
            mySaveWeights();
            myWeightsTrained = true; 
            myResetMenuState();
            return;
          }
          if (Serial.available()) {
            char c = Serial.read();
            if (c == 'x' || c == 'X' || c == 'l' || c == 'L') {
              Serial.println("Stopping training...");
              mySaveWeights();
              myWeightsTrained = true; 
              myResetMenuState();
              return;
            }
          }
        }
      }
      
      myUpdateWeights(batch+1);
      
      float avgLoss = batchLoss / (batchEnd - batchStart);
      float batchAcc = (float)correctCount / (batchEnd - batchStart);
      runningLoss += avgLoss;
      lossCount++;
      
      // Update display
      if((batch+1) % 5 == 0) {
        float displayLoss = runningLoss / lossCount;
        u8g2.firstPage();
        do {
          u8g2.setFont(u8g2_font_5x7_tf);   // _6x10_tf
          u8g2.setCursor(0, 12); u8g2.print("Training...");
          u8g2.setCursor(0, 24); 
          u8g2.print("B:"); u8g2.print(batch+1); 
          u8g2.print("/"); u8g2.print(totalBatches);
          u8g2.setCursor(0, 36); 
          u8g2.print("L:"); u8g2.print(displayLoss, 3);
          u8g2.print(" A:"); u8g2.print((int)(batchAcc*100)); u8g2.print("%");
        } while (u8g2.nextPage());
        runningLoss = 0;
        lossCount = 0;
      }
      
      if((batch+1) % 10 == 0) {
        Serial.printf("Batch %d/%d - Loss: %.4f - Acc: %.1f%%\n", 
                     batch+1, totalBatches, avgLoss, batchAcc*100);
      }
    }
    
    Serial.println("\n--- Training Complete ---");

    // v44: Run forward pass on held-out validation images and report accuracy.
    if (!myValidationData.empty()) {
      int valCorrect = 0;
      int valCount   = 0;
      for (auto& vitem : myValidationData) {
        if (!myLoadImageFromFile(vitem.path.c_str(), myInputBuffer)) continue;
        float logits[NUM_CLASSES];
        myForwardPass(myInputBuffer, logits);
        int pred = 0;
        for (int j = 1; j < NUM_CLASSES; j++)
          if (myDense_output[j] > myDense_output[pred]) pred = j;
        if (pred == vitem.label) valCorrect++;
        valCount++;
      }
      if (valCount > 0) {
        Serial.printf("Validation Accuracy: %.1f%%  (%d/%d correct)\n",
                      100.0f * valCorrect / valCount, valCorrect, valCount);
      }
    }

    mySaveWeights();
    myWeightsTrained = true;

    u8g2.firstPage();
    do { 
      u8g2.drawStr(0, 12, "DONE!");
      u8g2.drawStr(0, 24, "Tap:Again");
      u8g2.drawStr(0, 36, "3+Taps:Exit");
    } while (u8g2.nextPage());

    myResetTouchState();
    
    Serial.println("Waiting for input...");
    Serial.println("  Serial: T=train again  L=exit");
    Serial.println("  Touch:  1-2 taps=train again  3+taps=exit");
    while (true) {
      if (Serial.available()) {
        char c = Serial.read();
        // v43 FIX: added l/L as exit — was missing here (only x/X worked before)
        if (c == 'x' || c == 'X' || c == 'l' || c == 'L') {
          myResetMenuState();
          return;
        } else if (c == 't' || c == 'T') {
          break;
        }
      }
      int touchAction = myCheckTouchInput();
      if (touchAction == 2) {
        myResetMenuState();
        return;
      } else if (touchAction == 1) {
        Serial.println("Starting new training cycle");
        break;
      }
      delay(10);
    }
  }
}


// ██████████████████████████████████████████████████████████████████████████████
// ██                                                                          ██
// ██  PART 3: INFERENCE FUNCTION - OPTIMIZED                                  ██
// ██                                                                          ██
// ██  DEPENDENCIES (functions called from Part 0):                            ██
// ██  - myLoadWeights()    // Weights loaded in setup()                       ██
// ██  - myForwardPass()                        [Part 2]                       ██
// ██  - myRgbBuffer (global, allocated in setup)                              ██
// ██                                                                          ██
// ██  VARIABLES USED (defined in Part 0):                                     ██
// ██  - myInputBuffer, myDense_output (probabilities)                         ██
// ██  - myClassLabels[NUM_CLASSES], myThresholdPress                                    ██
// ██  - u8g2 (OLED display object)                                            ██
// ██                                                                          ██
// ██████████████████████████████████████████████████████████████████████████████


void myActionInfer() {
  // Guard: refuse to run if no trained weights are loaded
  if (!myWeightsTrained) {
    Serial.println("ERROR: No trained weights! Please run menu item 4 (Train) first.");
    u8g2.firstPage();
    do {
      u8g2.setFont(u8g2_font_6x10_tf);
      u8g2.drawStr(0, 12, "No weights!");
      u8g2.drawStr(0, 24, "Train first");
      u8g2.drawStr(0, 36, "(menu item 4)");
    } while (u8g2.nextPage());
    delay(3000);
    myResetMenuState();
    return;
  }
  Serial.println("\n>>> Inference mode - OPTIMIZED");
  Serial.println("Instructions:");
  Serial.println("  T or L exit to menu");

  
  myResetTouchState();  // Clear touch state when entering
  
  // Weights already loaded in setup() - just verify PSRAM is ready
  if (!myInputBuffer || !myDense_output) {
    Serial.println("ERROR: Memory not allocated - cannot infer");
    u8g2.firstPage();
    do { u8g2.drawStr(0, 15, "NOT READY!"); } while (u8g2.nextPage());
    delay(2000);
    myResetMenuState();
    return;
  }
  
  // Pre-compute resize lookup tables (done once)
  static int sy_lookup[INPUT_SIZE];
  static int sx_lookup[INPUT_SIZE];
  static bool lookup_initialized = false;
  
  if (!lookup_initialized) {
    for(int i=0; i<INPUT_SIZE; i++) {
      sy_lookup[i] = min((int)((i+0.5)*240.0/INPUT_SIZE), 239);
      sx_lookup[i] = min((int)((i+0.5)*240.0/INPUT_SIZE), 239);
    }
    lookup_initialized = true;
    Serial.println("Resize lookup tables initialized");
  }
  
  // Timing arrays for 10-frame batches
  unsigned long frameTimes[10];
  int frameIndex = 0;
  int pred = 0;  // Store prediction outside loop for printing
  
  while (true) {
    unsigned long frameStart = millis();
    
    // Serial input check (fast, every frame)
    if (Serial.available()) {
      char c = Serial.read();
      if (c == 't' || c == 'T' || c == 'l' || c == 'L') {
        myResetMenuState();
        return;
      }
    }
    
    // Get camera frame
    camera_fb_t * fb = esp_camera_fb_get();
    if (!fb) {
      Serial.println("Camera frame failed - retrying");
      delay(10);
      continue;
    }
    
    // Check if RGB buffer is allocated
    if (!myRgbBuffer) {
      Serial.println("ERROR: myRgbBuffer not allocated!");
      esp_camera_fb_return(fb);
      delay(10);
      continue;
    }
    
    // Convert JPEG to RGB (reusing pre-allocated buffer)
    if (fmt2rgb888(fb->buf, fb->len, PIXFORMAT_JPEG, myRgbBuffer)) {
      
      // Optimized resize using lookup tables
      for(int y=0; y<INPUT_SIZE; y++) {
        int sy = sy_lookup[y];
        int sy_offset = sy * 240;
        int dst_y_offset = y * INPUT_SIZE;
        
        for(int x=0; x<INPUT_SIZE; x++) {
          int srcIdx = (sy_offset + sx_lookup[x]) * 3;
          int dstIdx = (dst_y_offset + x) * 3;
          myInputBuffer[dstIdx] = myRgbBuffer[srcIdx] * 0.003921569f;      // /255.0
          myInputBuffer[dstIdx+1] = myRgbBuffer[srcIdx+1] * 0.003921569f;
          myInputBuffer[dstIdx+2] = myRgbBuffer[srcIdx+2] * 0.003921569f;
        }
      }
      
      // Run inference
      float myLogits[NUM_CLASSES];
      myForwardPass(myInputBuffer, myLogits);
      
      // Find prediction
      pred = 0;
      for(int i=1; i<NUM_CLASSES; i++) {
        if(myDense_output[i] > myDense_output[pred]) pred = i;
      }

      // Every 10th frame: draw live image + label overlay on OLED.
      // Done HERE while myRgbBuffer is still valid (before fb is returned).
      if (frameIndex == 9) {
        int oW = u8g2.getDisplayWidth();
        int oH = u8g2.getDisplayHeight();
        int scX = 240 / oW;
        int scY = 240 / oH;
        u8g2.firstPage();
        do {
          // Draw downsampled camera image
          for (int ox = 0; ox < oW; ox++) {
            for (int oy = 0; oy < oH; oy++) {
              int pi = ((oy * scY) * 240 + (ox * scX)) * 3;
              uint8_t bright = (myRgbBuffer[pi] + myRgbBuffer[pi+1] + myRgbBuffer[pi+2]) / 3;
              if (bright > 100) u8g2.drawPixel(ox, oy);
            }
          }
          // Label overlay bar at bottom
          u8g2.setFont(u8g2_font_5x7_tf);
          u8g2.setColorIndex(0);
          u8g2.drawBox(0, oH - 9, oW, 9);
          u8g2.setColorIndex(1);
          char buf[20];
          snprintf(buf, sizeof(buf), "%s %d%%",
                   myClassLabels[pred].c_str(),
                   (int)(myDense_output[pred] * 100));
          u8g2.drawStr(1, oH - 1, buf);
        } while (u8g2.nextPage());
      }
    }
    
    esp_camera_fb_return(fb);
    
    // Record frame timing
    frameTimes[frameIndex] = millis() - frameStart;
    float fps2 = 1000.0 / frameTimes[frameIndex];
    Serial.printf("Frame %d: %lu ms (%.1f FPS) ", frameIndex+1, frameTimes[frameIndex], fps2);
    frameIndex++;
    Serial.printf("Current Pred: %s (%.1f%%) | All:", 
                   myClassLabels[pred].c_str(), myDense_output[pred]*100);
    for(int i=0; i<NUM_CLASSES; i++) Serial.printf(" %.0f%%", myDense_output[i]*100);
    Serial.println();
   
    // Every 10th frame: touch exit check (OLED image already drawn above before fb return)
    if (frameIndex >= 10) {
      int touchVal = myReadTouch();
      if (touchVal > myThresholdPress) {
        Serial.println("Touch detected - exiting inference");
        delay(200);
        myResetMenuState();
        return;
      }
      frameIndex = 0;
    }
  }
}


// ██████████████████████████████████████████████████████████████████████████████
// ██                                                                          ██
// ██  PART 4: MENU SYSTEM FUNCTIONS                                           ██
// ██                                                                          ██
// ██  DEPENDENCIES (functions called from Part 0):                            ██
// ██  - myActionCollect(int classIdx)          [Part 1]                       ██
// ██  - myActionTrain()                        [Part 2]                       ██
// ██  - myActionInfer()                        [Part 3]                       ██
// ██                                                                          ██
// ██  VARIABLES USED (defined in Part 0):                                     ██
// ██  - myClassLabels[NUM_CLASSES]                                                      ██
// ██  - myTotalItems, myThresholdPress, myThresholdRelease                    ██
// ██  - myLastActivityTime, myLastTapTime, myTapCooldown                      ██
// ██  - myIsTouching, myLongPressTriggered, myMenuIndex, myIsSelected         ██
// ██  - u8g2 (OLED display object)                                            ██
// ██                                                                          ██
// ██  NOTE: This part is called from loop() in Part 0                         ██
// ██                                                                          ██
// ██████████████████████████████████████████████████████████████████████████████


void myResetMenuState() {
  myIsSelected = false;
  myResetTouchState();  // Use unified touch reset
  myLastActivityTime = millis();
  myDrawMenu();
}

void myDrawMenu() {
  // ===== SERIAL MENU =====
  Serial.println("\n=== MENU ===");
  for (int i = 1; i <= myTotalItems; i++) {
    String label =
      (i <= NUM_CLASSES) ? myClassLabels[i - 1] :
      (i == NUM_CLASSES + 1) ? "Train" : "Infer";

    if (i == myMenuIndex) Serial.print(" > ");
    else                 Serial.print("   ");

    Serial.printf("%d. %s\n", i, label.c_str());
  }
  Serial.println("Commands: t=next (tap)  l=select (longpress)");

  // ===== OLED MENU =====
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(0, 8, "TAP:Next HOLD:Ok");

    int myStartItem = (myMenuIndex <= NUM_CLASSES) ? 1 : myMenuIndex - 2;

    for (int i = 0; i < 3; i++) {
      int cur = myStartItem + i;
      if (cur > myTotalItems) break;

      String label =
        (cur <= NUM_CLASSES) ? myClassLabels[cur - 1] :
        (cur == NUM_CLASSES + 1) ? "Train" : "Infer";

      int y = 18 + i * 9;
      if (cur == myMenuIndex)
        u8g2.drawStr(0, y, ("> " + label).c_str());
      else
        u8g2.drawStr(0, y, ("  " + label).c_str());
    }
  } while (u8g2.nextPage());
}

// Helper: execute the currently selected menu item
void myExecuteMenuItem(int idx) {
  if (idx <= NUM_CLASSES)        myActionCollect(idx - 1);
  else if (idx == NUM_CLASSES+1) myActionTrain();
  else                           myActionInfer();
}

void myHandleMenuNavigation() {
  unsigned long myCurrentMillis = millis();

  // --------------------------------------------------------------------------
  // SERIAL INPUT
  // --------------------------------------------------------------------------
  if (!myIsSelected && Serial.available()) {
    char c = Serial.read();

    // Single-digit direct selection (works for NUM_CLASSES up to 9+2=11 items via digit keys)
    if (c >= '1' && c <= '9') {
      int newIndex = c - '0';
      if (newIndex <= myTotalItems) {
        myMenuIndex = newIndex;
        myIsSelected = true;
        myLastActivityTime = myCurrentMillis;
        myExecuteMenuItem(myMenuIndex);
      }
    }
    else if (c == 't' || c == 'T') {
      if (myCurrentMillis - myLastTapTime > myTapCooldown) {
        myMenuIndex++;
        if (myMenuIndex > myTotalItems) myMenuIndex = 1;
        myDrawMenu();
        myLastTapTime = myCurrentMillis;
        myLastActivityTime = myCurrentMillis;
      }
    }
    else if (c == 'l' || c == 'L') {
      myIsSelected = true;
      myLastActivityTime = myCurrentMillis;
      myExecuteMenuItem(myMenuIndex);
    }
  }

  // --------------------------------------------------------------------------
  // TOUCH INPUT - NOW USING UNIFIED SYSTEM
  // --------------------------------------------------------------------------
  if (!myIsSelected) {
    int touchAction = myCheckTouchInput();
    
    if (touchAction == 1) {
      // Tap detected - advance menu
      if (myCurrentMillis - myLastTapTime > myTapCooldown) {
        myMenuIndex++;
        if (myMenuIndex > myTotalItems) myMenuIndex = 1;
        myDrawMenu();
        myLastTapTime = myCurrentMillis;
        myLastActivityTime = myCurrentMillis;
      }
    }
    else if (touchAction == 2) {
      // Long press detected - select menu item
      myIsSelected = true;
      myLastActivityTime = myCurrentMillis;
      myExecuteMenuItem(myMenuIndex);
    }
  }
}
