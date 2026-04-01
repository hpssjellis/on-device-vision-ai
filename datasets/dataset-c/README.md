Each class in this dataset has 63 images. The basic code put in the firmware.ino file should be


```

#define NUM_CLASSES 6

String myClassLabels[NUM_CLASSES] = {"0Blank", "1Cup", "2Pen", "3unknown", "4Circle", "5Mouse"};
```

Note: a 2 layer Vision CNN is not well suited for this many classes so don't expect very good results without a lot of training runs and even then I feel we are pushing the limits of this NN  architecture



But an interesting point is that you can mix and match any of these values for example. The following should also work and is a bigger dataset than before


```

#define NUM_CLASSES 3

String myClassLabels[NUM_CLASSES] = {"0Blank", "1Cup", "2Pen"};
```


Or even try


```

#define NUM_CLASSES 2

String myClassLabels[NUM_CLASSES] = {"0Blank",  "3unknown"};
```





Here is the serial monitor printout for only one run using my webSerial print webpage at   https://hpssjellis.github.io/webserial-print/index.html


```
--- Connected @ 115200 baud: 4/1/2026, 3:05:00 PM ---
[15:05:00.902] ESP-ROM:esp32s3-20210327
[15:05:00.903] e PSRAM after allocation: 7215820 bytes
[15:05:00.904] He-init random weights set
[15:05:00.904] No SD weights file found
[15:05:00.904] 
[15:05:00.905] === MENU ===
[15:05:00.905] > 1. 0Blank
[15:05:00.905] 2. 1Cup
[15:05:00.905] 3. 2Pen
[15:05:00.906] 4. 3unknown
[15:05:00.906] 5. 4Circle
[15:05:00.906] 6. 5Mouse
[15:05:00.907] 7. Train
[15:05:00.907] 8. Infer
[15:05:00.907] Commands: t=next (tap)  l=select (longpress)
[15:05:02.487] System ready - Tap A0 to navigate, 3+ taps to select
[15:05:02.490] 
[15:05:02.493] === MENU ===
[15:05:02.494] > 1. 0Blank
[15:05:02.495] 2. 1Cup
[15:05:02.495] 3. 2Pen
[15:05:02.496] 4. 3unknown
[15:05:02.498] 5. 4Circle
[15:05:02.501] 6. 5Mouse
[15:05:02.504] 7. Train
[15:05:02.506] 8. Infer
[15:05:02.507] Commands: t=next (tap)  l=select (longpress)
[15:05:15.837] 
[15:05:15.838] >>> Training mode
[15:05:15.839] Instructions:
[15:05:15.839] During training: 3+ taps = Save and exit
[15:05:15.840] After completion: TAP = Train again, 3+ taps = Exit
[15:05:15.841] Serial: 'T'=train again, 'L'=exit
[15:05:16.458] No SD weights file found
[15:05:16.464] Starting fresh training
[15:05:51.830] Val: 18 images  Train: 360 images
[15:05:51.835] Training: 360 images, 1200 batches
[15:05:51.837] 
[15:05:51.839] --- Epoch 1/20 ---
[15:06:22.182] Batch 10/1200 - Loss: 2.2648 - Acc: 0.0%
[15:06:51.865] Batch 20/1200 - Loss: 1.8688 - Acc: 16.7%
[15:07:20.601] Batch 30/1200 - Loss: 1.7654 - Acc: 16.7%
[15:08:18.423] Batch 40/1200 - Loss: 1.7230 - Acc: 33.3%
[15:08:18.424] Batch 50/1200 - Loss: 1.7709 - Acc: 16.7%
[15:08:48.074] Batch 60/1200 - Loss: 1.6097 - Acc: 33.3%
[15:08:48.078] 
[15:08:48.083] --- Epoch 2/20 ---
[15:09:18.424] Batch 70/1200 - Loss: 1.4576 - Acc: 50.0%
[15:09:47.942] Batch 80/1200 - Loss: 1.9461 - Acc: 33.3%
[15:10:16.718] Batch 90/1200 - Loss: 1.8386 - Acc: 16.7%
[15:10:45.832] Batch 100/1200 - Loss: 1.2696 - Acc: 83.3%
[15:11:14.168] Batch 110/1200 - Loss: 1.5731 - Acc: 33.3%
[15:11:44.365] Batch 120/1200 - Loss: 1.2259 - Acc: 50.0%
[15:11:44.375] 
[15:11:44.376] --- Epoch 3/20 ---
[15:12:14.262] Batch 130/1200 - Loss: 1.4108 - Acc: 50.0%
[15:12:43.329] Batch 140/1200 - Loss: 1.4373 - Acc: 50.0%
[15:13:12.712] Batch 150/1200 - Loss: 1.6311 - Acc: 33.3%
[15:13:42.375] Batch 160/1200 - Loss: 1.4531 - Acc: 50.0%
[15:14:11.604] Batch 170/1200 - Loss: 1.2511 - Acc: 66.7%
[15:14:40.657] Batch 180/1200 - Loss: 1.0207 - Acc: 66.7%
[15:14:40.659] 
[15:14:40.661] --- Epoch 4/20 ---
[15:15:10.432] Batch 190/1200 - Loss: 1.2139 - Acc: 50.0%
[15:15:39.444] Batch 200/1200 - Loss: 1.1490 - Acc: 66.7%
[15:16:08.452] Batch 210/1200 - Loss: 1.2160 - Acc: 66.7%
[15:16:37.998] Batch 220/1200 - Loss: 1.6814 - Acc: 33.3%
[15:17:07.847] Batch 230/1200 - Loss: 1.1710 - Acc: 50.0%
[15:17:36.976] Batch 240/1200 - Loss: 1.0035 - Acc: 83.3%
[15:17:36.985] 
[15:17:36.991] --- Epoch 5/20 ---
[15:18:06.405] Batch 250/1200 - Loss: 1.4479 - Acc: 33.3%
[15:18:35.498] Batch 260/1200 - Loss: 1.4023 - Acc: 50.0%
[15:19:04.788] Batch 270/1200 - Loss: 0.7212 - Acc: 100.0%
[15:19:34.167] Batch 280/1200 - Loss: 1.0245 - Acc: 83.3%
[15:20:03.166] Batch 290/1200 - Loss: 0.7422 - Acc: 100.0%
[15:20:33.295] Batch 300/1200 - Loss: 1.0392 - Acc: 66.7%
[15:20:33.298] 
[15:20:33.301] --- Epoch 6/20 ---
[15:21:02.207] Batch 310/1200 - Loss: 0.9856 - Acc: 83.3%
[15:21:32.128] Batch 320/1200 - Loss: 1.2544 - Acc: 66.7%
[15:22:01.108] Batch 330/1200 - Loss: 0.4787 - Acc: 83.3%
[15:22:59.990] Batch 340/1200 - Loss: 1.0361 - Acc: 50.0%
[15:22:59.993] Batch 350/1200 - Loss: 1.0027 - Acc: 83.3%
[15:23:29.621] Batch 360/1200 - Loss: 0.7211 - Acc: 83.3%
[15:23:29.625] 
[15:23:29.627] --- Epoch 7/20 ---
[15:23:59.517] Batch 370/1200 - Loss: 0.8447 - Acc: 83.3%
[15:24:28.400] Batch 380/1200 - Loss: 0.7690 - Acc: 66.7%
[15:24:57.906] Batch 390/1200 - Loss: 1.1455 - Acc: 66.7%
[15:25:27.933] Batch 400/1200 - Loss: 0.8019 - Acc: 50.0%
[15:25:56.479] Batch 410/1200 - Loss: 1.1516 - Acc: 66.7%
[15:26:25.921] Batch 420/1200 - Loss: 1.0393 - Acc: 66.7%
[15:26:25.926] 
[15:26:25.929] --- Epoch 8/20 ---
[15:26:56.356] Batch 430/1200 - Loss: 0.9550 - Acc: 66.7%
[15:27:25.491] Batch 440/1200 - Loss: 0.9503 - Acc: 66.7%
[15:27:54.745] Batch 450/1200 - Loss: 1.3039 - Acc: 33.3%
[15:28:23.728] Batch 460/1200 - Loss: 0.7959 - Acc: 83.3%
[15:28:53.134] Batch 470/1200 - Loss: 1.3174 - Acc: 33.3%
[15:29:22.211] Batch 480/1200 - Loss: 0.5291 - Acc: 83.3%
[15:29:22.218] 
[15:29:22.221] --- Epoch 9/20 ---
[15:29:52.068] Batch 490/1200 - Loss: 1.0105 - Acc: 50.0%
[15:30:22.402] Batch 500/1200 - Loss: 0.6155 - Acc: 83.3%
[15:30:51.645] Batch 510/1200 - Loss: 0.7317 - Acc: 100.0%
[15:31:20.183] Batch 520/1200 - Loss: 0.7005 - Acc: 66.7%
[15:31:48.986] Batch 530/1200 - Loss: 0.4243 - Acc: 100.0%
[15:32:18.516] Batch 540/1200 - Loss: 0.4267 - Acc: 100.0%
[15:32:18.518] 
[15:32:18.519] --- Epoch 10/20 ---
[15:32:47.432] Batch 550/1200 - Loss: 0.7646 - Acc: 83.3%
[15:33:17.349] Batch 560/1200 - Loss: 0.6222 - Acc: 83.3%
[15:33:46.484] Batch 570/1200 - Loss: 0.8307 - Acc: 66.7%
[15:34:16.714] Batch 580/1200 - Loss: 0.2112 - Acc: 100.0%
[15:34:45.456] Batch 590/1200 - Loss: 1.1887 - Acc: 50.0%
[15:35:14.870] Batch 600/1200 - Loss: 0.6675 - Acc: 66.7%
[15:35:14.873] 
[15:35:14.874] --- Epoch 11/20 ---
[15:35:43.403] Batch 610/1200 - Loss: 0.8731 - Acc: 66.7%
[15:36:13.164] Batch 620/1200 - Loss: 0.4491 - Acc: 100.0%
[15:36:42.936] Batch 630/1200 - Loss: 0.5044 - Acc: 83.3%
[15:37:41.854] Batch 640/1200 - Loss: 0.5238 - Acc: 83.3%
[15:37:41.861] Batch 650/1200 - Loss: 0.2835 - Acc: 100.0%
[15:38:11.172] Batch 660/1200 - Loss: 0.7757 - Acc: 83.3%
[15:38:11.174] 
[15:38:11.175] --- Epoch 12/20 ---
[15:38:41.204] Batch 670/1200 - Loss: 0.6313 - Acc: 66.7%
[15:39:10.787] Batch 680/1200 - Loss: 1.3524 - Acc: 66.7%
[15:39:39.525] Batch 690/1200 - Loss: 0.4683 - Acc: 100.0%
[15:40:08.945] Batch 700/1200 - Loss: 0.3181 - Acc: 100.0%
[15:40:38.569] Batch 710/1200 - Loss: 0.1212 - Acc: 100.0%
[15:41:07.463] Batch 720/1200 - Loss: 0.5509 - Acc: 83.3%
[15:41:07.464] 
[15:41:07.465] --- Epoch 13/20 ---
[15:41:36.796] Batch 730/1200 - Loss: 0.2658 - Acc: 100.0%
[15:42:06.028] Batch 740/1200 - Loss: 0.4672 - Acc: 100.0%
[15:43:05.481] Batch 750/1200 - Loss: 0.5850 - Acc: 83.3%
[15:43:05.487] Batch 760/1200 - Loss: 0.5701 - Acc: 83.3%
[15:43:34.348] Batch 770/1200 - Loss: 0.1583 - Acc: 100.0%
[15:44:03.755] Batch 780/1200 - Loss: 0.0958 - Acc: 100.0%
[15:44:03.760] 
[15:44:03.763] --- Epoch 14/20 ---
[15:44:32.377] Batch 790/1200 - Loss: 0.5301 - Acc: 83.3%
[15:45:01.942] Batch 800/1200 - Loss: 0.3954 - Acc: 83.3%
[15:45:31.276] Batch 810/1200 - Loss: 0.4554 - Acc: 83.3%
[15:46:00.997] Batch 820/1200 - Loss: 0.4756 - Acc: 100.0%
[15:46:30.796] Batch 830/1200 - Loss: 0.7395 - Acc: 66.7%
[15:47:00.050] Batch 840/1200 - Loss: 0.2105 - Acc: 100.0%
[15:47:00.053] 
[15:47:00.054] --- Epoch 15/20 ---
[15:47:29.082] Batch 850/1200 - Loss: 0.7481 - Acc: 66.7%
[15:47:58.324] Batch 860/1200 - Loss: 0.4016 - Acc: 100.0%
[15:48:27.841] Batch 870/1200 - Loss: 0.3148 - Acc: 100.0%
[15:48:57.599] Batch 880/1200 - Loss: 1.1254 - Acc: 50.0%
[15:49:26.989] Batch 890/1200 - Loss: 0.3509 - Acc: 100.0%
[15:49:56.332] Batch 900/1200 - Loss: 0.3878 - Acc: 100.0%
[15:49:56.338] 
[15:49:56.341] --- Epoch 16/20 ---
[15:50:25.351] Batch 910/1200 - Loss: 0.2752 - Acc: 100.0%
[15:50:55.026] Batch 920/1200 - Loss: 0.6905 - Acc: 83.3%
[15:51:24.726] Batch 930/1200 - Loss: 0.1408 - Acc: 100.0%
[15:51:54.387] Batch 940/1200 - Loss: 0.5384 - Acc: 83.3%
[15:52:22.948] Batch 950/1200 - Loss: 0.6250 - Acc: 66.7%
[15:52:52.651] Batch 960/1200 - Loss: 0.7529 - Acc: 83.3%
[15:52:52.654] 
[15:52:52.656] --- Epoch 17/20 ---
[15:53:22.730] Batch 970/1200 - Loss: 0.2576 - Acc: 83.3%
[15:53:52.631] Batch 980/1200 - Loss: 0.5320 - Acc: 83.3%
[15:54:21.585] Batch 990/1200 - Loss: 0.2791 - Acc: 83.3%
[15:54:50.619] Batch 1000/1200 - Loss: 0.1066 - Acc: 100.0%
[15:55:19.121] Batch 1010/1200 - Loss: 0.3114 - Acc: 100.0%
[15:55:48.933] Batch 1020/1200 - Loss: 0.1636 - Acc: 100.0%
[15:55:48.942] 
[15:55:48.944] --- Epoch 18/20 ---
[15:56:18.828] Batch 1030/1200 - Loss: 0.5096 - Acc: 83.3%
[15:56:48.247] Batch 1040/1200 - Loss: 1.1662 - Acc: 66.7%
[15:57:16.562] Batch 1050/1200 - Loss: 0.1630 - Acc: 100.0%
[15:57:46.251] Batch 1060/1200 - Loss: 0.5188 - Acc: 83.3%
[15:58:15.845] Batch 1070/1200 - Loss: 0.3801 - Acc: 100.0%
[15:58:45.187] Batch 1080/1200 - Loss: 0.0483 - Acc: 100.0%
[15:58:45.192] 
[15:58:45.193] --- Epoch 19/20 ---
[15:59:13.923] Batch 1090/1200 - Loss: 0.7578 - Acc: 66.7%
[15:59:42.873] Batch 1100/1200 - Loss: 0.6260 - Acc: 83.3%
[16:00:12.455] Batch 1110/1200 - Loss: 0.2566 - Acc: 83.3%
[16:00:42.224] Batch 1120/1200 - Loss: 0.2051 - Acc: 100.0%
[16:01:11.637] Batch 1130/1200 - Loss: 0.4190 - Acc: 83.3%
[16:01:41.462] Batch 1140/1200 - Loss: 0.4036 - Acc: 83.3%
[16:01:41.470] 
[16:01:41.473] --- Epoch 20/20 ---
[16:02:11.336] Batch 1150/1200 - Loss: 0.2665 - Acc: 100.0%
[16:02:40.319] Batch 1160/1200 - Loss: 0.8268 - Acc: 66.7%
[16:03:09.984] Batch 1170/1200 - Loss: 0.2965 - Acc: 100.0%
[16:04:08.128] Batch 1180/1200 - Loss: 0.6520 - Acc: 83.3%
[16:04:08.133] Batch 1190/1200 - Loss: 0.1542 - Acc: 100.0%
[16:04:37.748] Batch 1200/1200 - Loss: 0.2334 - Acc: 100.0%
[16:04:37.754] 
[16:04:37.757] --- Training Complete ---
[16:04:46.925] Validation Accuracy: 66.7%  (12/18 correct)
[16:04:52.774] Weights saved to SD
[16:05:07.525] You can copy /header/myWeights.h to the sketch folder, then uncomment #define USE_BAKED_WEIGHTS
[16:05:07.642] Waiting for input...
[16:05:07.649] Serial: T=train again  L=exit
[16:05:07.651] Touch:  1-2 taps=train again  3+taps=exit
[16:05:26.641] 
[16:05:26.643] === MENU ===
[16:05:26.645] 1. 0Blank
[16:05:26.646] 2. 1Cup
[16:05:26.648] 3. 2Pen
[16:05:26.650] 4. 3unknown
[16:05:26.651] 5. 4Circle
[16:05:26.653] 6. 5Mouse
[16:05:26.655] > 7. Train
[16:05:26.656] 8. Infer
[16:05:26.658] Commands: t=next (tap)  l=select (longpress)
[16:05:29.355] 
[16:05:29.358] >>> Inference mode - OPTIMIZED
[16:05:29.360] Instructions:
[16:05:29.361] T or L exit to menu
[16:05:29.363] Resize lookup tables initialized
[16:05:29.501] Frame 1: 143 ms (7.0 FPS) Current Pred: 3unknown (44.6%) | All: 8% 20% 19% 45% 6% 2%
[16:05:29.697] Frame 2: 198 ms (5.1 FPS) Current Pred: 3unknown (69.8%) | All: 4% 1% 24% 70% 0% 0%
[16:05:29.891] Frame 3: 192 ms (5.2 FPS) Current Pred: 3unknown (69.6%) | All: 3% 1% 25% 70% 0% 0%
[16:05:30.082] Frame 4: 193 ms (5.2 FPS) Current Pred: 3unknown (68.9%) | All: 4% 1% 26% 69% 0% 0%
[16:05:30.274] Frame 5: 191 ms (5.2 FPS) Current Pred: 3unknown (68.1%) | All: 5% 1% 26% 68% 0% 0%
[16:05:30.467] Frame 6: 192 ms (5.2 FPS) Current Pred: 3unknown (67.4%) | All: 4% 1% 27% 67% 0% 0%
[16:05:30.659] Frame 7: 192 ms (5.2 FPS) Current Pred: 4Circle (57.8%) | All: 0% 6% 4% 33% 58% 0%
[16:05:30.849] Frame 8: 192 ms (5.2 FPS) Current Pred: 3unknown (66.4%) | All: 6% 24% 1% 66% 3% 0%
[16:05:31.044] Frame 9: 194 ms (5.2 FPS) Current Pred: 3unknown (56.1%) | All: 0% 43% 1% 56% 0% 0%
[16:05:31.253] Frame 10: 207 ms (4.8 FPS) Current Pred: 1Cup (95.6%) | All: 0% 96% 2% 2% 0% 0%
[16:05:31.458] Frame 1: 204 ms (4.9 FPS) Current Pred: 1Cup (49.8%) | All: 0% 50% 40% 7% 1% 2%
[16:05:31.650] Frame 2: 191 ms (5.2 FPS) Current Pred: 4Circle (85.7%) | All: 0% 0% 8% 5% 86% 1%
[16:05:31.874] Frame 3: 225 ms (4.4 FPS) Current Pred: 5Mouse (50.8%) | All: 0% 0% 1% 39% 9% 51%
[16:05:32.067] Frame 4: 194 ms (5.2 FPS) Current Pred: 4Circle (72.1%) | All: 0% 10% 12% 3% 72% 3%
[16:05:32.261] Frame 5: 192 ms (5.2 FPS) Current Pred: 1Cup (80.0%) | All: 0% 80% 3% 16% 0% 1%
[16:05:32.483] Frame 6: 222 ms (4.5 FPS) Current Pred: 3unknown (98.7%) | All: 0% 1% 0% 99% 0% 1%
[16:05:32.675] Frame 7: 192 ms (5.2 FPS) Current Pred: 3unknown (91.3%) | All: 0% 3% 1% 91% 5% 0%
[16:05:32.866] Frame 8: 192 ms (5.2 FPS) Current Pred: 3unknown (63.6%) | All: 0% 23% 4% 64% 10% 0%
[16:05:33.060] Frame 9: 192 ms (5.2 FPS) Current Pred: 3unknown (88.3%) | All: 0% 1% 0% 88% 0% 11%
[16:05:33.267] Frame 10: 207 ms (4.8 FPS) Current Pred: 1Cup (78.3%) | All: 0% 78% 3% 6% 10% 3%
[16:05:33.444] Frame 1: 175 ms (5.7 FPS) Current Pred: 1Cup (100.0%) | All: 0% 100% 0% 0% 0% 0%
[16:05:33.637] Frame 2: 192 ms (5.2 FPS) Current Pred: 1Cup (93.9%) | All: 0% 94% 0% 1% 2% 3%
[16:05:33.826] Frame 3: 190 ms (5.3 FPS) Current Pred: 3unknown (39.0%) | All: 20% 0% 34% 39% 1% 5%
[16:05:34.020] Frame 4: 193 ms (5.2 FPS) Current Pred: 3unknown (75.4%) | All: 3% 1% 20% 75% 2% 0%
[16:05:34.214] Frame 5: 193 ms (5.2 FPS) Current Pred: 4Circle (88.3%) | All: 0% 0% 11% 0% 88% 1%
[16:05:34.404] Frame 6: 191 ms (5.2 FPS) Current Pred: 5Mouse (96.2%) | All: 0% 0% 0% 3% 0% 96%
[16:05:34.597] Frame 7: 193 ms (5.2 FPS) Current Pred: 5Mouse (96.4%) | All: 0% 0% 0% 3% 0% 96%
[16:05:34.790] Frame 8: 192 ms (5.2 FPS) Current Pred: 5Mouse (92.6%) | All: 0% 0% 0% 7% 0% 93%
[16:05:34.980] Frame 9: 192 ms (5.2 FPS) Current Pred: 5Mouse (78.6%) | All: 0% 0% 0% 12% 9% 79%
[16:05:34.984] 
[16:05:34.987] === MENU ===
[16:05:34.989] 1. 0Blank
[16:05:34.990] 2. 1Cup
[16:05:34.993] 3. 2Pen
[16:05:34.995] 4. 3unknown
[16:05:34.997] 5. 4Circle
[16:05:34.999] 6. 5Mouse
[16:05:35.001] 7. Train
[16:05:35.003] > 8. Infer
[16:05:35.005] Commands: t=next (tap)  l=select (longpress)


```

