# on-device-vision-ai
Complete Seeedstudio xiao ml kit esp32s3-sense on device machine learning pipeline




Copy of paper [main.pdf](main.pdf)

Seeedstudio $14.90 USD pre-soldered headers [xiao esp32s3 sense](https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32S3-Sense-Pre-Soldered-p-6335.html) or $22-38.90 USD [xiao ML kit](https://www.seeedstudio.com/The-XIAOML-Kit.html) (has IMU and 2 color OLED plus esp32s3 sense)

arduino style single file code at [firmware.ino](firmware.ino)

3 datasets at [datasets](datasets)



Citation at [CITATION.cff not yet ready](CITATION.cff)

Step to compile in the paper or see below




.


.



.


## Deployment Workflow Steps from the paper

### Arduino IDE
1. Install the U8g2 library via the Arduino Library Manager.
2. Open the Arduino IDE (tested with version 2.3.5); select the Seeed Studio XIAO
ESP32-S3 board target.
3. Under Tools → PSRAM, select OPI PSRAM.
4. Insert a FAT32 microSD card.
5. Compile and upload; place the board in bootloader mode if required (hold Boot while
connecting USB).
6. Open the serial monitor at 115200 baud.
7. Navigate with tap / long-press (3+ taps) on Pin A0, or use t (next) / L (select) in the
serial monitor.
8. Capture images for each class (recommended: ≥50 per class).
9. Run Train; monitor loss and accuracy on OLED or serial monitor.
10. Optionally copy /header/myWeights.h to the sketch folder and uncomment #define
USE
BAKED
WEIGHTS for SD-free deployment.
11. Run Infer for real-time classification at 6.3 FPS.

    
9.2 PlatformIO    platformio.ini configuration

```

lib_deps = olikraus/U8g2 @ ^2.35.30
build_flags =
   -DBOARD_HAS_PSRAM
   -DARDUINO_USB_CDC_ON_BOOT=1
board_build.arduino.memory_type = qio_opi
board_build.flash_mode = qio
board_build.flash_size = 8MB

```


