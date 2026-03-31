The main dataset for the paper.
Simple 3 classes



Training log from the serial monitor

```
--- Connected @ 115200 baud: 3/31/2026, 10:23:53 AM ---
[10:23:53.644] itialized
[10:23:53.645] 
[10:23:53.646] === Allocating Memory ===
[10:23:53.646] Free PSRAM after allocation: 7543560 bytes
[10:23:53.646] He-init random weights set
[10:23:53.647] No SD weights file found
[10:23:53.647] 
[10:23:53.648] === MENU ===
[10:23:53.648] > 1. 0Blank
[10:23:53.649] 2. 1Cup
[10:23:53.650] 3. 2Pen
[10:23:53.650] 4. Train
[10:23:53.651] 5. Infer
[10:23:53.652] Commands: t=next (tap)  l=select (longpress)
[10:23:54.395] System ready - Tap A0 to navigate, 3+ taps to select
[10:23:54.398] 
[10:23:54.401] === MENU ===
[10:23:54.403] > 1. 0Blank
[10:23:54.405] 2. 1Cup
[10:23:54.407] 3. 2Pen
[10:23:54.409] 4. Train
[10:23:54.411] 5. Infer
[10:23:54.413] Commands: t=next (tap)  l=select (longpress)
[10:24:03.081] ERROR: No trained weights! Please run menu item 4 (Train) first.
[10:24:06.095] 
[10:24:06.100] === MENU ===
[10:24:06.103] 1. 0Blank
[10:24:06.106] 2. 1Cup
[10:24:06.108] 3. 2Pen
[10:24:06.110] 4. Train
[10:24:06.112] > 5. Infer
[10:24:06.114] Commands: t=next (tap)  l=select (longpress)
[10:24:06.303] 
[10:24:06.304] >>> Training mode
[10:24:06.304] Instructions:
[10:24:06.305] During training: 3+ taps = Save and exit
[10:24:06.306] After completion: TAP = Train again, 3+ taps = Exit
[10:24:06.306] Serial: 'T'=train again, 'L'=exit
[10:24:06.491] No SD weights file found
[10:24:06.496] Starting fresh training
[10:24:16.242] Val: 9 images  Train: 108 images
[10:24:16.246] Training: 108 images, 360 batches
[10:24:16.251] 
[10:24:16.254] --- Epoch 1/20 ---
[10:24:42.120] Batch 10/360 - Loss: 0.8257 - Acc: 83.3%
[10:25:02.007] 
[10:25:02.012] --- Epoch 2/20 ---
[10:25:06.968] Batch 20/360 - Loss: 1.0077 - Acc: 66.7%
[10:25:32.947] Batch 30/360 - Loss: 1.2239 - Acc: 0.0%
[10:25:47.795] 
[10:25:47.800] --- Epoch 3/20 ---
[10:25:57.550] Batch 40/360 - Loss: 0.9503 - Acc: 66.7%
[10:26:33.571] Batch 50/360 - Loss: 1.0808 - Acc: 16.7%
[10:26:33.577] 
[10:26:33.580] --- Epoch 4/20 ---
[10:26:48.696] Batch 60/360 - Loss: 0.9459 - Acc: 66.7%
[10:27:14.139] Batch 70/360 - Loss: 0.9806 - Acc: 66.7%
[10:27:19.339] 
[10:27:19.346] --- Epoch 5/20 ---
[10:27:39.704] Batch 80/360 - Loss: 0.8772 - Acc: 66.7%
[10:28:05.112] Batch 90/360 - Loss: 1.0396 - Acc: 50.0%
[10:28:05.118] 
[10:28:05.122] --- Epoch 6/20 ---
[10:28:31.207] Batch 100/360 - Loss: 0.8367 - Acc: 66.7%
[10:28:50.872] 
[10:28:50.880] --- Epoch 7/20 ---
[10:28:55.932] Batch 110/360 - Loss: 0.7191 - Acc: 66.7%
[10:29:21.332] Batch 120/360 - Loss: 0.7285 - Acc: 66.7%
[10:29:36.636] 
[10:29:36.643] --- Epoch 8/20 ---
[10:29:46.809] Batch 130/360 - Loss: 0.7263 - Acc: 83.3%
[10:30:12.071] Batch 140/360 - Loss: 0.5756 - Acc: 83.3%
[10:30:22.391] 
[10:30:22.398] --- Epoch 9/20 ---
[10:30:37.362] Batch 150/360 - Loss: 0.6700 - Acc: 66.7%
[10:31:03.139] Batch 160/360 - Loss: 0.6167 - Acc: 66.7%
[10:31:08.168] 
[10:31:08.175] --- Epoch 10/20 ---
[10:31:28.465] Batch 170/360 - Loss: 0.8218 - Acc: 66.7%
[10:31:53.940] Batch 180/360 - Loss: 0.8414 - Acc: 50.0%
[10:31:53.951] 
[10:31:53.961] --- Epoch 11/20 ---
[10:32:19.160] Batch 190/360 - Loss: 0.5951 - Acc: 83.3%
[10:32:39.702] 
[10:32:39.709] --- Epoch 12/20 ---
[10:32:44.952] Batch 200/360 - Loss: 0.5076 - Acc: 83.3%
[10:33:10.080] Batch 210/360 - Loss: 0.6813 - Acc: 100.0%
[10:33:25.473] 
[10:33:25.480] --- Epoch 13/20 ---
[10:33:35.704] Batch 220/360 - Loss: 0.7940 - Acc: 83.3%
[10:34:00.907] Batch 230/360 - Loss: 0.5359 - Acc: 66.7%
[10:34:11.230] 
[10:34:11.239] --- Epoch 14/20 ---
[10:34:26.571] Batch 240/360 - Loss: 0.4766 - Acc: 83.3%
[10:35:17.405] Batch 250/360 - Loss: 0.4412 - Acc: 100.0%
[10:35:17.409] 
[10:35:17.411] --- Epoch 15/20 ---
[10:35:17.412] Batch 260/360 - Loss: 0.9335 - Acc: 50.0%
[10:35:42.773] Batch 270/360 - Loss: 0.5409 - Acc: 100.0%
[10:35:42.780] 
[10:35:42.782] --- Epoch 16/20 ---
[10:36:08.314] Batch 280/360 - Loss: 0.3613 - Acc: 83.3%
[10:36:28.536] 
[10:36:28.538] --- Epoch 17/20 ---
[10:36:33.857] Batch 290/360 - Loss: 0.4475 - Acc: 100.0%
[10:36:59.419] Batch 300/360 - Loss: 0.8655 - Acc: 33.3%
[10:37:14.315] 
[10:37:14.316] --- Epoch 18/20 ---
[10:37:24.521] Batch 310/360 - Loss: 0.2924 - Acc: 100.0%
[10:37:49.881] Batch 320/360 - Loss: 0.5733 - Acc: 83.3%
[10:38:00.088] 
[10:38:00.095] --- Epoch 19/20 ---
[10:38:14.935] Batch 330/360 - Loss: 0.1445 - Acc: 100.0%
[10:38:45.873] Batch 340/360 - Loss: 0.4461 - Acc: 83.3%
[10:38:45.875] 
[10:38:45.876] --- Epoch 20/20 ---
[10:39:05.618] Batch 350/360 - Loss: 0.5262 - Acc: 100.0%
[10:39:31.652] Batch 360/360 - Loss: 0.5465 - Acc: 83.3%
[10:39:31.653] 
[10:39:31.654] --- Training Complete ---
[10:39:35.688] Validation Accuracy: 66.7%  (6/9 correct)
[10:39:37.667] Weights saved to SD
[10:39:45.293] You can copy /header/myWeights.h to the sketch folder, then uncomment #define USE_BAKED_WEIGHTS
[10:39:45.401] Waiting for input...
[10:39:45.404] Serial: T=train again  L=exit
[10:39:45.405] Touch:  1-2 taps=train again  3+taps=exit
[10:39:47.051] 
[10:39:47.053] === MENU ===
[10:39:47.054] 1. 0Blank
[10:39:47.056] 2. 1Cup
[10:39:47.057] 3. 2Pen
[10:39:47.057] > 4. Train
[10:39:47.058] 5. Infer
[10:39:47.059] Commands: t=next (tap)  l=select (longpress)
[10:39:49.027] 
[10:39:49.028] >>> Inference mode - OPTIMIZED
[10:39:49.029] Instructions:
[10:39:49.031] T or L exit to menu
[10:39:49.032] Resize lookup tables initialized
[10:39:49.142] Frame 1: 115 ms (8.7 FPS) Current Pred: 1Cup (73.6%) | All: 12% 74% 14%
[10:39:49.316] Frame 2: 173 ms (5.8 FPS) Current Pred: 2Pen (72.0%) | All: 16% 12% 72%
[10:39:49.477] Frame 3: 160 ms (6.2 FPS) Current Pred: 2Pen (73.0%) | All: 15% 12% 73%
[10:39:49.636] Frame 4: 160 ms (6.2 FPS) Current Pred: 2Pen (72.3%) | All: 16% 11% 72%
[10:39:49.797] Frame 5: 160 ms (6.2 FPS) Current Pred: 2Pen (72.6%) | All: 16% 11% 73%
[10:39:49.956] Frame 6: 160 ms (6.2 FPS) Current Pred: 2Pen (72.5%) | All: 17% 11% 72%
[10:39:50.116] Frame 7: 160 ms (6.2 FPS) Current Pred: 2Pen (57.9%) | All: 17% 25% 58%
[10:39:50.276] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (63.0%) | All: 63% 4% 33%
[10:39:50.437] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (51.1%) | All: 51% 23% 26%
[10:39:50.614] Frame 10: 175 ms (5.7 FPS) Current Pred: 0Blank (89.3%) | All: 89% 2% 9%
[10:39:50.854] Frame 1: 240 ms (4.2 FPS) Current Pred: 1Cup (68.1%) | All: 19% 68% 13%
[10:39:51.013] Frame 2: 160 ms (6.2 FPS) Current Pred: 1Cup (60.3%) | All: 13% 60% 27%
[10:39:51.173] Frame 3: 160 ms (6.2 FPS) Current Pred: 1Cup (65.9%) | All: 11% 66% 23%
[10:39:51.333] Frame 4: 160 ms (6.2 FPS) Current Pred: 1Cup (61.9%) | All: 20% 62% 18%
[10:39:51.493] Frame 5: 160 ms (6.2 FPS) Current Pred: 1Cup (59.8%) | All: 21% 60% 20%
[10:39:51.653] Frame 6: 160 ms (6.2 FPS) Current Pred: 1Cup (60.9%) | All: 19% 61% 20%
[10:39:51.813] Frame 7: 160 ms (6.2 FPS) Current Pred: 1Cup (53.3%) | All: 22% 53% 24%
[10:39:51.975] Frame 8: 161 ms (6.2 FPS) Current Pred: 1Cup (53.8%) | All: 18% 54% 28%
[10:39:52.133] Frame 9: 159 ms (6.3 FPS) Current Pred: 1Cup (58.1%) | All: 20% 58% 22%
[10:39:52.311] Frame 10: 177 ms (5.6 FPS) Current Pred: 1Cup (55.2%) | All: 21% 55% 24%
[10:39:52.486] Frame 1: 174 ms (5.7 FPS) Current Pred: 1Cup (73.2%) | All: 18% 73% 8%
[10:39:52.645] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (95.2%) | All: 95% 1% 4%
[10:39:52.807] Frame 3: 161 ms (6.2 FPS) Current Pred: 0Blank (62.2%) | All: 62% 9% 29%
[10:39:52.967] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (66.2%) | All: 66% 5% 29%
[10:39:53.130] Frame 5: 164 ms (6.1 FPS) Current Pred: 2Pen (56.2%) | All: 23% 21% 56%
[10:39:53.288] Frame 6: 157 ms (6.4 FPS) Current Pred: 0Blank (76.2%) | All: 76% 9% 15%
[10:39:53.448] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (72.9%) | All: 73% 4% 23%
[10:39:53.609] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (66.8%) | All: 67% 1% 32%
[10:39:53.768] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (50.7%) | All: 51% 1% 48%
[10:39:53.945] Frame 10: 176 ms (5.7 FPS) Current Pred: 2Pen (63.7%) | All: 28% 9% 64%
[10:39:54.121] Frame 1: 175 ms (5.7 FPS) Current Pred: 2Pen (39.8%) | All: 37% 23% 40%
[10:39:54.281] Frame 2: 160 ms (6.2 FPS) Current Pred: 2Pen (62.6%) | All: 31% 7% 63%
[10:39:54.440] Frame 3: 159 ms (6.3 FPS) Current Pred: 0Blank (96.4%) | All: 96% 0% 3%
[10:39:54.598] Frame 4: 158 ms (6.3 FPS) Current Pred: 0Blank (79.4%) | All: 79% 6% 15%
[10:39:54.758] Frame 5: 160 ms (6.2 FPS) Current Pred: 1Cup (66.0%) | All: 20% 66% 14%
[10:39:54.918] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (49.5%) | All: 49% 15% 35%
[10:39:55.078] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (52.9%) | All: 53% 12% 35%
[10:39:55.237] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (60.4%) | All: 60% 10% 29%
[10:39:55.400] Frame 9: 161 ms (6.2 FPS) Current Pred: 0Blank (60.7%) | All: 61% 10% 29%
[10:39:55.576] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (60.1%) | All: 60% 11% 29%
[10:39:55.750] Frame 1: 173 ms (5.8 FPS) Current Pred: 1Cup (54.6%) | All: 25% 55% 21%
[10:39:55.911] Frame 2: 160 ms (6.2 FPS) Current Pred: 1Cup (60.3%) | All: 20% 60% 20%
[10:39:56.071] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (46.6%) | All: 47% 36% 17%
[10:39:56.230] Frame 4: 159 ms (6.3 FPS) Current Pred: 1Cup (50.8%) | All: 41% 51% 8%
[10:39:56.391] Frame 5: 161 ms (6.2 FPS) Current Pred: 0Blank (92.0%) | All: 92% 1% 7%
[10:39:56.550] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (95.7%) | All: 96% 1% 3%
[10:39:56.711] Frame 7: 161 ms (6.2 FPS) Current Pred: 1Cup (39.9%) | All: 40% 40% 20%
[10:39:56.870] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (41.8%) | All: 42% 27% 31%
[10:39:57.032] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (43.1%) | All: 43% 32% 25%
[10:39:57.207] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (46.1%) | All: 46% 26% 28%
[10:39:57.383] Frame 1: 174 ms (5.7 FPS) Current Pred: 0Blank (36.2%) | All: 36% 34% 30%
[10:39:57.543] Frame 2: 159 ms (6.3 FPS) Current Pred: 1Cup (39.3%) | All: 35% 39% 26%
[10:39:57.701] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (55.0%) | All: 55% 7% 38%
[10:39:57.863] Frame 4: 160 ms (6.2 FPS) Current Pred: 2Pen (56.2%) | All: 32% 12% 56%
[10:39:58.023] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (50.8%) | All: 51% 15% 34%
[10:39:58.183] Frame 6: 160 ms (6.2 FPS) Current Pred: 2Pen (50.7%) | All: 28% 21% 51%
[10:39:58.342] Frame 7: 160 ms (6.2 FPS) Current Pred: 2Pen (50.9%) | All: 21% 28% 51%
[10:39:58.503] Frame 8: 160 ms (6.2 FPS) Current Pred: 2Pen (51.1%) | All: 21% 28% 51%
[10:39:58.662] Frame 9: 160 ms (6.2 FPS) Current Pred: 2Pen (51.3%) | All: 19% 30% 51%
[10:39:58.840] Frame 10: 177 ms (5.6 FPS) Current Pred: 2Pen (51.8%) | All: 18% 30% 52%
[10:39:59.015] Frame 1: 174 ms (5.7 FPS) Current Pred: 2Pen (54.5%) | All: 18% 28% 54%
[10:39:59.174] Frame 2: 159 ms (6.3 FPS) Current Pred: 2Pen (56.6%) | All: 17% 26% 57%
[10:39:59.335] Frame 3: 159 ms (6.3 FPS) Current Pred: 2Pen (57.3%) | All: 17% 26% 57%
[10:39:59.496] Frame 4: 160 ms (6.2 FPS) Current Pred: 2Pen (59.6%) | All: 18% 23% 60%
[10:39:59.655] Frame 5: 161 ms (6.2 FPS) Current Pred: 2Pen (59.2%) | All: 17% 24% 59%
[10:39:59.814] Frame 6: 159 ms (6.3 FPS) Current Pred: 2Pen (58.8%) | All: 17% 24% 59%
[10:39:59.817] 
[10:39:59.819] === MENU ===
[10:39:59.820] 1. 0Blank
[10:39:59.821] 2. 1Cup
[10:39:59.823] 3. 2Pen
[10:39:59.824] 4. Train
[10:39:59.825] > 5. Infer
[10:39:59.826] Commands: t=next (tap)  l=select (longpress)
[10:40:03.527] 
[10:40:03.529] >>> Training mode
[10:40:03.530] Instructions:
[10:40:03.531] During training: 3+ taps = Save and exit
[10:40:03.533] After completion: TAP = Train again, 3+ taps = Exit
[10:40:03.535] Serial: 'T'=train again, 'L'=exit
[10:40:03.586] Loading weights from SD...
[10:40:05.338] Weights loaded successfully
[10:40:05.341] Continuing from saved weights
[10:40:15.087] Val: 9 images  Train: 108 images
[10:40:15.089] Training: 108 images, 360 batches
[10:40:15.091] 
[10:40:15.093] --- Epoch 1/20 ---
[10:40:40.604] Batch 10/360 - Loss: 0.4804 - Acc: 66.7%
[10:41:00.843] 
[10:41:00.850] --- Epoch 2/20 ---
[10:41:05.872] Batch 20/360 - Loss: 0.2212 - Acc: 100.0%
[10:41:31.165] Batch 30/360 - Loss: 0.4140 - Acc: 83.3%
[10:41:46.623] 
[10:41:46.628] --- Epoch 3/20 ---
[10:41:56.615] Batch 40/360 - Loss: 0.5715 - Acc: 66.7%
[10:42:22.183] Batch 50/360 - Loss: 0.2940 - Acc: 83.3%
[10:42:32.386] 
[10:42:32.391] --- Epoch 4/20 ---
[10:42:47.926] Batch 60/360 - Loss: 0.3795 - Acc: 83.3%
[10:43:13.102] Batch 70/360 - Loss: 0.6004 - Acc: 50.0%
[10:43:18.162] 
[10:43:18.168] --- Epoch 5/20 ---
[10:43:38.357] Batch 80/360 - Loss: 0.1944 - Acc: 100.0%
[10:44:03.930] Batch 90/360 - Loss: 0.2640 - Acc: 100.0%
[10:44:03.933] 
[10:44:03.936] --- Epoch 6/20 ---
[10:44:29.259] Batch 100/360 - Loss: 0.2891 - Acc: 83.3%
[10:44:49.694] 
[10:44:49.698] --- Epoch 7/20 ---
[10:44:54.925] Batch 110/360 - Loss: 0.2598 - Acc: 100.0%
[10:45:20.253] Batch 120/360 - Loss: 0.2778 - Acc: 100.0%
[10:45:35.464] 
[10:45:35.469] --- Epoch 8/20 ---
[10:45:45.598] Batch 130/360 - Loss: 0.2047 - Acc: 100.0%
[10:46:10.789] Batch 140/360 - Loss: 0.3372 - Acc: 83.3%
[10:46:36.435] 
[10:46:36.445] --- Epoch 9/20 ---
[10:46:36.447] Batch 150/360 - Loss: 0.4196 - Acc: 100.0%
[10:47:01.961] Batch 160/360 - Loss: 0.4159 - Acc: 66.7%
[10:47:06.988] 
[10:47:06.995] --- Epoch 10/20 ---
[10:47:27.385] Batch 170/360 - Loss: 0.3373 - Acc: 83.3%
[10:47:52.760] Batch 180/360 - Loss: 0.3722 - Acc: 83.3%
[10:47:52.767] 
[10:47:52.770] --- Epoch 11/20 ---
[10:48:18.332] Batch 190/360 - Loss: 0.5624 - Acc: 50.0%
[10:48:38.520] 
[10:48:38.529] --- Epoch 12/20 ---
[10:48:43.675] Batch 200/360 - Loss: 0.2607 - Acc: 100.0%
[10:49:09.051] Batch 210/360 - Loss: 0.2250 - Acc: 100.0%
[10:49:24.294] 
[10:49:24.298] --- Epoch 13/20 ---
[10:49:34.566] Batch 220/360 - Loss: 0.2552 - Acc: 100.0%
[10:50:00.181] Batch 230/360 - Loss: 0.1846 - Acc: 100.0%
[10:50:25.475] 
[10:50:25.482] --- Epoch 14/20 ---
[10:50:25.484] Batch 240/360 - Loss: 0.2949 - Acc: 83.3%
[10:50:50.787] Batch 250/360 - Loss: 0.1501 - Acc: 100.0%
[10:50:55.824] 
[10:50:55.833] --- Epoch 15/20 ---
[10:51:16.369] Batch 260/360 - Loss: 0.4095 - Acc: 83.3%
[10:51:41.594] Batch 270/360 - Loss: 0.3063 - Acc: 83.3%
[10:51:41.600] 
[10:51:41.602] --- Epoch 16/20 ---
[10:52:06.798] Batch 280/360 - Loss: 0.1507 - Acc: 100.0%
[10:52:27.356] 
[10:52:27.365] --- Epoch 17/20 ---
[10:52:57.811] Batch 290/360 - Loss: 0.1215 - Acc: 100.0%
[10:52:57.820] Batch 300/360 - Loss: 0.2636 - Acc: 100.0%
[10:53:23.715] 
[10:53:23.724] --- Epoch 18/20 ---
[10:53:23.726] Batch 310/360 - Loss: 0.4207 - Acc: 83.3%
[10:53:49.083] Batch 320/360 - Loss: 0.5604 - Acc: 66.7%
[10:53:58.879] 
[10:53:58.882] --- Epoch 19/20 ---
[10:54:13.997] Batch 330/360 - Loss: 0.2003 - Acc: 100.0%
[10:54:39.437] Batch 340/360 - Loss: 0.1032 - Acc: 100.0%
[10:54:44.652] 
[10:54:44.660] --- Epoch 20/20 ---
[10:55:05.081] Batch 350/360 - Loss: 0.3326 - Acc: 83.3%
[10:55:30.425] Batch 360/360 - Loss: 0.1697 - Acc: 100.0%
[10:55:30.447] 
[10:55:30.459] --- Training Complete ---
[10:55:34.464] Validation Accuracy: 88.9%  (8/9 correct)
[10:55:36.334] Weights saved to SD
[10:55:43.854] You can copy /header/myWeights.h to the sketch folder, then uncomment #define USE_BAKED_WEIGHTS
[10:55:43.960] Waiting for input...
[10:55:43.979] Serial: T=train again  L=exit
[10:55:43.986] Touch:  1-2 taps=train again  3+taps=exit
[10:55:48.670] 
[10:55:48.678] === MENU ===
[10:55:48.682] 1. 0Blank
[10:55:48.686] 2. 1Cup
[10:55:48.690] 3. 2Pen
[10:55:48.695] > 4. Train
[10:55:48.699] 5. Infer
[10:55:48.703] Commands: t=next (tap)  l=select (longpress)
[10:55:51.166] 
[10:55:51.170] >>> Inference mode - OPTIMIZED
[10:55:51.174] Instructions:
[10:55:51.178] T or L exit to menu
[10:55:51.283] Frame 1: 116 ms (8.6 FPS) Current Pred: 0Blank (81.6%) | All: 82% 4% 15%
[10:55:51.458] Frame 2: 175 ms (5.7 FPS) Current Pred: 0Blank (88.7%) | All: 89% 1% 10%
[10:55:51.620] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (88.2%) | All: 88% 1% 11%
[10:55:51.779] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (88.0%) | All: 88% 1% 11%
[10:55:51.939] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (88.0%) | All: 88% 1% 11%
[10:55:52.100] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (89.9%) | All: 90% 0% 10%
[10:55:52.259] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (88.0%) | All: 88% 1% 11%
[10:55:52.420] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (97.2%) | All: 97% 1% 2%
[10:55:52.581] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (99.9%) | All: 100% 0% 0%
[10:55:52.758] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (93.2%) | All: 93% 3% 4%
[10:55:52.933] Frame 1: 174 ms (5.7 FPS) Current Pred: 0Blank (98.6%) | All: 99% 0% 1%
[10:55:53.093] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (98.4%) | All: 98% 0% 2%
[10:55:53.253] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (98.3%) | All: 98% 0% 2%
[10:55:53.414] Frame 4: 161 ms (6.2 FPS) Current Pred: 0Blank (97.5%) | All: 98% 1% 2%
[10:55:53.574] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (97.5%) | All: 98% 1% 2%
[10:55:53.733] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (97.6%) | All: 98% 1% 2%
[10:55:53.893] Frame 7: 159 ms (6.3 FPS) Current Pred: 0Blank (97.5%) | All: 97% 1% 2%
[10:55:54.053] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (95.5%) | All: 95% 2% 2%
[10:55:54.213] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (94.4%) | All: 94% 4% 2%
[10:55:54.391] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (87.6%) | All: 88% 9% 4%
[10:55:54.566] Frame 1: 173 ms (5.8 FPS) Current Pred: 0Blank (89.9%) | All: 90% 7% 3%
[10:55:54.726] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (97.7%) | All: 98% 0% 2%
[10:55:54.884] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (93.7%) | All: 94% 4% 2%
[10:55:55.045] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (97.7%) | All: 98% 1% 2%
[10:55:55.205] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (89.0%) | All: 89% 4% 7%
[10:55:55.364] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (93.8%) | All: 94% 5% 1%
[10:55:55.558] Frame 7: 192 ms (5.2 FPS) Current Pred: 0Blank (93.0%) | All: 93% 4% 3%
[10:55:55.719] Frame 8: 161 ms (6.2 FPS) Current Pred: 0Blank (97.7%) | All: 98% 1% 1%
[10:55:55.877] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (90.3%) | All: 90% 8% 2%
[10:55:56.055] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (85.6%) | All: 86% 13% 1%
[10:55:56.262] Frame 1: 206 ms (4.9 FPS) Current Pred: 0Blank (91.4%) | All: 91% 7% 1%
[10:55:56.336] cam_hal: FB-OVF
[10:55:56.454] Frame 2: 192 ms (5.2 FPS) Current Pred: 0Blank (91.8%) | All: 92% 7% 1%
[10:55:56.615] Frame 3: 161 ms (6.2 FPS) Current Pred: 0Blank (94.6%) | All: 95% 4% 2%
[10:55:56.776] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (92.1%) | All: 92% 6% 2%
[10:55:56.936] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (94.5%) | All: 95% 3% 3%
[10:55:57.094] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (93.0%) | All: 93% 2% 5%
[10:55:57.256] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (92.6%) | All: 93% 1% 7%
[10:55:57.329] cam_hal: FB-OVF
[10:55:57.446] Frame 8: 190 ms (5.3 FPS) Current Pred: 0Blank (98.0%) | All: 98% 1% 1%
[10:55:57.608] Frame 9: 161 ms (6.2 FPS) Current Pred: 0Blank (98.2%) | All: 98% 1% 1%
[10:55:57.784] Frame 10: 176 ms (5.7 FPS) Current Pred: 0Blank (99.3%) | All: 99% 0% 0%
[10:55:57.960] Frame 1: 175 ms (5.7 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[10:55:58.120] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (99.9%) | All: 100% 0% 0%
[10:55:58.280] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (99.4%) | All: 99% 0% 0%
[10:55:58.440] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (99.9%) | All: 100% 0% 0%
[10:55:58.600] Frame 5: 161 ms (6.2 FPS) Current Pred: 0Blank (99.0%) | All: 99% 0% 1%
[10:55:58.793] Frame 6: 193 ms (5.2 FPS) Current Pred: 0Blank (94.1%) | All: 94% 1% 5%
[10:55:58.865] cam_hal: FB-OVF
[10:55:58.888] cam_hal: FB-OVF
[10:55:58.986] Frame 7: 191 ms (5.2 FPS) Current Pred: 0Blank (98.2%) | All: 98% 1% 1%
[10:55:59.176] Frame 8: 192 ms (5.2 FPS) Current Pred: 0Blank (98.6%) | All: 99% 1% 0%
[10:55:59.338] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (97.4%) | All: 97% 2% 0%
[10:55:59.516] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (97.0%) | All: 97% 3% 0%
[10:55:59.689] Frame 1: 174 ms (5.7 FPS) Current Pred: 0Blank (99.1%) | All: 99% 1% 0%
[10:55:59.793] cam_hal: FB-OVF
[10:55:59.819] cam_hal: FB-OVF
[10:55:59.915] Frame 2: 225 ms (4.4 FPS) Current Pred: 0Blank (99.5%) | All: 100% 0% 0%
[10:56:00.073] Frame 3: 157 ms (6.4 FPS) Current Pred: 0Blank (98.2%) | All: 98% 0% 2%
[10:56:00.233] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (98.4%) | All: 98% 1% 1%
[10:56:00.392] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (99.2%) | All: 99% 0% 0%
[10:56:00.552] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (99.4%) | All: 99% 0% 0%
[10:56:00.712] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (71.9%) | All: 72% 23% 5%
[10:56:00.871] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (96.0%) | All: 96% 3% 1%
[10:56:01.030] Frame 9: 158 ms (6.3 FPS) Current Pred: 0Blank (99.4%) | All: 99% 0% 0%
[10:56:01.238] Frame 10: 208 ms (4.8 FPS) Current Pred: 0Blank (99.1%) | All: 99% 1% 0%
[10:56:01.445] Frame 1: 207 ms (4.8 FPS) Current Pred: 0Blank (98.3%) | All: 98% 0% 1%
[10:56:01.607] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (73.8%) | All: 74% 12% 14%
[10:56:01.767] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (89.2%) | All: 89% 1% 10%
[10:56:01.927] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (94.4%) | All: 94% 1% 5%
[10:56:02.086] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (98.4%) | All: 98% 0% 1%
[10:56:02.246] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (97.4%) | All: 97% 0% 2%
[10:56:02.408] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (97.1%) | All: 97% 0% 3%
[10:56:02.568] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (96.6%) | All: 97% 0% 3%
[10:56:02.726] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (96.6%) | All: 97% 0% 3%
[10:56:02.905] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (97.9%) | All: 98% 0% 2%
[10:56:03.079] Frame 1: 174 ms (5.7 FPS) Current Pred: 0Blank (97.4%) | All: 97% 0% 2%
[10:56:03.241] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (97.6%) | All: 98% 0% 2%
[10:56:03.400] Frame 3: 159 ms (6.3 FPS) Current Pred: 0Blank (98.1%) | All: 98% 0% 2%
[10:56:03.560] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (93.8%) | All: 94% 0% 6%
[10:56:03.719] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (94.2%) | All: 94% 1% 5%
[10:56:03.879] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (97.7%) | All: 98% 0% 2%
[10:56:04.071] Frame 7: 192 ms (5.2 FPS) Current Pred: 0Blank (98.7%) | All: 99% 0% 1%
[10:56:04.231] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (86.8%) | All: 87% 4% 9%
[10:56:04.391] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (99.3%) | All: 99% 0% 0%
[10:56:04.569] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[10:56:04.744] Frame 1: 174 ms (5.7 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[10:56:04.905] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[10:56:05.064] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (98.9%) | All: 99% 1% 0%
[10:56:05.226] Frame 4: 161 ms (6.2 FPS) Current Pred: 0Blank (98.0%) | All: 98% 2% 0%
[10:56:05.384] Frame 5: 158 ms (6.3 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[10:56:05.544] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (99.7%) | All: 100% 0% 0%
[10:56:05.703] Frame 7: 159 ms (6.3 FPS) Current Pred: 0Blank (78.1%) | All: 78% 20% 2%
[10:56:05.863] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (79.7%) | All: 80% 17% 3%
[10:56:06.023] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (66.0%) | All: 66% 2% 32%
[10:56:06.233] Frame 10: 209 ms (4.8 FPS) Current Pred: 0Blank (91.8%) | All: 92% 1% 8%
[10:56:06.408] Frame 1: 174 ms (5.7 FPS) Current Pred: 0Blank (97.9%) | All: 98% 0% 2%
[10:56:06.569] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (96.1%) | All: 96% 1% 3%
[10:56:06.728] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (76.1%) | All: 76% 4% 20%
[10:56:06.889] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (77.7%) | All: 78% 3% 19%
[10:56:07.048] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (90.1%) | All: 90% 1% 9%
[10:56:07.209] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (88.4%) | All: 88% 1% 10%
[10:56:07.367] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (86.8%) | All: 87% 2% 11%
[10:56:07.372] 
[10:56:07.377] === MENU ===
[10:56:07.382] 1. 0Blank
[10:56:07.387] 2. 1Cup
[10:56:07.393] 3. 2Pen
[10:56:07.399] 4. Train
[10:56:07.404] > 5. Infer
[10:56:07.410] Commands: t=next (tap)  l=select (longpress)
[10:56:10.562] 
[10:56:10.568] >>> Training mode
[10:56:10.573] Instructions:
[10:56:10.578] During training: 3+ taps = Save and exit
[10:56:10.583] After completion: TAP = Train again, 3+ taps = Exit
[10:56:10.589] Serial: 'T'=train again, 'L'=exit
[10:56:10.621] Loading weights from SD...
[10:56:12.375] Weights loaded successfully
[10:56:12.392] Continuing from saved weights
[10:56:22.125] Val: 9 images  Train: 108 images
[10:56:22.155] Training: 108 images, 360 batches
[10:56:22.183] 
[10:56:22.192] --- Epoch 1/20 ---
[10:57:07.895] Batch 10/360 - Loss: 0.1269 - Acc: 100.0%
[10:57:07.922] 
[10:57:07.941] --- Epoch 2/20 ---
[10:57:12.682] Batch 20/360 - Loss: 0.2702 - Acc: 83.3%
[10:57:53.675] Batch 30/360 - Loss: 0.1266 - Acc: 100.0%
[10:57:53.690] 
[10:57:53.695] --- Epoch 3/20 ---
[10:58:29.298] Batch 40/360 - Loss: 0.1178 - Acc: 100.0%
[10:58:29.308] Batch 50/360 - Loss: 0.1391 - Acc: 100.0%
[10:58:39.435] 
[10:58:39.456] --- Epoch 4/20 ---
[10:59:20.297] Batch 60/360 - Loss: 0.2184 - Acc: 100.0%
[10:59:20.314] Batch 70/360 - Loss: 0.2495 - Acc: 83.3%
[10:59:25.203] 
[10:59:25.210] --- Epoch 5/20 ---
[10:59:46.033] Batch 80/360 - Loss: 0.2449 - Acc: 83.3%
[11:00:10.979] Batch 90/360 - Loss: 0.4690 - Acc: 66.7%
[11:00:10.988] 
[11:00:10.990] --- Epoch 6/20 ---
[11:00:36.127] Batch 100/360 - Loss: 0.2686 - Acc: 100.0%
[11:00:56.738] 
[11:00:56.748] --- Epoch 7/20 ---
[11:01:01.979] Batch 110/360 - Loss: 0.0954 - Acc: 100.0%
[11:01:42.516] Batch 120/360 - Loss: 0.1435 - Acc: 100.0%
[11:01:42.523] 
[11:01:42.526] --- Epoch 8/20 ---
[11:01:52.691] Batch 130/360 - Loss: 0.0853 - Acc: 100.0%
[11:02:17.855] Batch 140/360 - Loss: 0.0654 - Acc: 100.0%
[11:02:28.269] 
[11:02:28.280] --- Epoch 9/20 ---
[11:02:43.566] Batch 150/360 - Loss: 0.2469 - Acc: 100.0%
[11:03:09.089] Batch 160/360 - Loss: 0.3693 - Acc: 83.3%
[11:03:14.040] 
[11:03:14.048] --- Epoch 10/20 ---
[11:03:34.171] Batch 170/360 - Loss: 0.2491 - Acc: 83.3%
[11:03:59.822] Batch 180/360 - Loss: 0.1412 - Acc: 100.0%
[11:03:59.832] 
[11:03:59.835] --- Epoch 11/20 ---
[11:04:25.602] Batch 190/360 - Loss: 0.1491 - Acc: 100.0%
[11:04:45.577] 
[11:04:45.586] --- Epoch 12/20 ---
[11:04:50.641] Batch 200/360 - Loss: 0.0928 - Acc: 100.0%
[11:05:16.881] Batch 210/360 - Loss: 0.1349 - Acc: 100.0%
[11:05:31.347] 
[11:05:31.357] --- Epoch 13/20 ---
[11:05:41.860] Batch 220/360 - Loss: 0.1336 - Acc: 100.0%
[11:06:07.318] Batch 230/360 - Loss: 0.1913 - Acc: 100.0%
[11:06:17.102] 
[11:06:17.110] --- Epoch 14/20 ---
[11:06:32.821] Batch 240/360 - Loss: 0.2883 - Acc: 100.0%
[11:06:57.968] Batch 250/360 - Loss: 0.0803 - Acc: 100.0%
[11:07:02.870] 
[11:07:02.879] --- Epoch 15/20 ---
[11:07:23.564] Batch 260/360 - Loss: 0.1253 - Acc: 100.0%
[11:07:48.638] Batch 270/360 - Loss: 0.2560 - Acc: 83.3%
[11:07:48.643] 
[11:07:48.646] --- Epoch 16/20 ---
[11:08:14.471] Batch 280/360 - Loss: 0.1342 - Acc: 100.0%
[11:08:34.397] 
[11:08:34.407] --- Epoch 17/20 ---
[11:08:39.491] Batch 290/360 - Loss: 0.2045 - Acc: 100.0%
[11:09:04.620] Batch 300/360 - Loss: 0.3550 - Acc: 100.0%
[11:09:20.165] 
[11:09:20.172] --- Epoch 18/20 ---
[11:09:29.984] Batch 310/360 - Loss: 0.3065 - Acc: 83.3%
[11:09:55.827] Batch 320/360 - Loss: 0.1095 - Acc: 100.0%
[11:10:05.927] 
[11:10:05.937] --- Epoch 19/20 ---
[11:10:21.113] Batch 330/360 - Loss: 0.3901 - Acc: 83.3%
[11:10:46.388] Batch 340/360 - Loss: 0.2169 - Acc: 83.3%
[11:10:51.696] 
[11:10:51.708] --- Epoch 20/20 ---
[11:11:12.248] Batch 350/360 - Loss: 0.2242 - Acc: 83.3%
[11:11:37.459] Batch 360/360 - Loss: 0.1001 - Acc: 100.0%
[11:11:37.471] 
[11:11:37.476] --- Training Complete ---
[11:11:41.496] Validation Accuracy: 77.8%  (7/9 correct)
[11:11:43.369] Weights saved to SD
[11:11:50.888] You can copy /header/myWeights.h to the sketch folder, then uncomment #define USE_BAKED_WEIGHTS
[11:11:50.994] Waiting for input...
[11:11:51.003] Serial: T=train again  L=exit
[11:11:51.008] Touch:  1-2 taps=train again  3+taps=exit
[11:11:53.034] 
[11:11:53.038] === MENU ===
[11:11:53.041] 1. 0Blank
[11:11:53.044] 2. 1Cup
[11:11:53.048] 3. 2Pen
[11:11:53.051] > 4. Train
[11:11:53.056] 5. Infer
[11:11:53.060] Commands: t=next (tap)  l=select (longpress)
[11:11:55.336] 
[11:11:55.343] >>> Inference mode - OPTIMIZED
[11:11:55.346] Instructions:
[11:11:55.350] T or L exit to menu
[11:11:55.454] Frame 1: 115 ms (8.7 FPS) Current Pred: 0Blank (79.8%) | All: 80% 2% 18%
[11:11:55.606] Frame 2: 152 ms (6.6 FPS) Current Pred: 0Blank (97.0%) | All: 97% 0% 3%
[11:11:55.767] Frame 3: 161 ms (6.2 FPS) Current Pred: 0Blank (96.4%) | All: 96% 0% 4%
[11:11:55.925] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (94.0%) | All: 94% 0% 6%
[11:11:56.084] Frame 5: 158 ms (6.3 FPS) Current Pred: 0Blank (86.0%) | All: 86% 1% 13%
[11:11:56.245] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (97.5%) | All: 97% 0% 2%
[11:11:56.407] Frame 7: 161 ms (6.2 FPS) Current Pred: 1Cup (50.6%) | All: 30% 51% 19%
[11:11:56.567] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (69.4%) | All: 69% 1% 30%
[11:11:56.727] Frame 9: 161 ms (6.2 FPS) Current Pred: 2Pen (86.1%) | All: 9% 5% 86%
[11:11:56.937] Frame 10: 207 ms (4.8 FPS) Current Pred: 0Blank (88.3%) | All: 88% 0% 12%
[11:11:57.111] Frame 1: 175 ms (5.7 FPS) Current Pred: 1Cup (85.6%) | All: 7% 86% 8%
[11:11:57.271] Frame 2: 159 ms (6.3 FPS) Current Pred: 1Cup (72.2%) | All: 18% 72% 10%
[11:11:57.431] Frame 3: 160 ms (6.2 FPS) Current Pred: 1Cup (92.7%) | All: 6% 93% 1%
[11:11:57.591] Frame 4: 160 ms (6.2 FPS) Current Pred: 1Cup (90.6%) | All: 8% 91% 1%
[11:11:57.751] Frame 5: 160 ms (6.2 FPS) Current Pred: 1Cup (84.2%) | All: 13% 84% 3%
[11:11:57.911] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (55.9%) | All: 56% 33% 11%
[11:11:58.069] Frame 7: 159 ms (6.3 FPS) Current Pred: 0Blank (36.5%) | All: 37% 36% 28%
[11:11:58.229] Frame 8: 160 ms (6.2 FPS) Current Pred: 2Pen (37.4%) | All: 32% 31% 37%
[11:11:58.390] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (50.8%) | All: 51% 42% 7%
[11:11:58.567] Frame 10: 176 ms (5.7 FPS) Current Pred: 0Blank (81.3%) | All: 81% 18% 1%
[11:11:58.744] Frame 1: 175 ms (5.7 FPS) Current Pred: 0Blank (61.1%) | All: 61% 39% 0%
[11:11:58.902] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (72.3%) | All: 72% 27% 1%
[11:11:59.063] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (85.2%) | All: 85% 15% 0%
[11:11:59.222] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (93.6%) | All: 94% 6% 0%
[11:11:59.383] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (89.5%) | All: 90% 10% 1%
[11:11:59.543] Frame 6: 160 ms (6.2 FPS) Current Pred: 2Pen (37.7%) | All: 33% 29% 38%
[11:11:59.705] Frame 7: 161 ms (6.2 FPS) Current Pred: 2Pen (47.8%) | All: 23% 29% 48%
[11:11:59.864] Frame 8: 158 ms (6.3 FPS) Current Pred: 0Blank (73.0%) | All: 73% 19% 8%
[11:12:00.023] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (98.4%) | All: 98% 0% 2%
[11:12:00.201] Frame 10: 176 ms (5.7 FPS) Current Pred: 0Blank (94.4%) | All: 94% 5% 1%
[11:12:00.375] Frame 1: 174 ms (5.7 FPS) Current Pred: 1Cup (96.3%) | All: 4% 96% 0%
[11:12:00.534] Frame 2: 160 ms (6.2 FPS) Current Pred: 1Cup (50.1%) | All: 48% 50% 2%
[11:12:00.695] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (90.5%) | All: 91% 9% 0%
[11:12:00.854] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (87.5%) | All: 88% 12% 1%
[11:12:01.015] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (98.7%) | All: 99% 0% 1%
[11:12:01.176] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (94.3%) | All: 94% 3% 2%
[11:12:01.337] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (98.8%) | All: 99% 0% 1%
[11:12:01.497] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (82.6%) | All: 83% 17% 0%
[11:12:01.656] Frame 9: 160 ms (6.2 FPS) Current Pred: 1Cup (98.6%) | All: 1% 99% 0%
[11:12:01.833] Frame 10: 176 ms (5.7 FPS) Current Pred: 1Cup (93.0%) | All: 7% 93% 0%
[11:12:02.007] Frame 1: 175 ms (5.7 FPS) Current Pred: 0Blank (99.3%) | All: 99% 1% 0%
[11:12:02.169] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (100.0%) | All: 100% 0% 0%
[11:12:02.329] Frame 3: 161 ms (6.2 FPS) Current Pred: 0Blank (99.9%) | All: 100% 0% 0%
[11:12:02.489] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (98.1%) | All: 98% 1% 1%
[11:12:02.650] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (95.0%) | All: 95% 5% 0%
[11:12:02.809] Frame 6: 159 ms (6.3 FPS) Current Pred: 1Cup (99.4%) | All: 1% 99% 0%
[11:12:02.969] Frame 7: 160 ms (6.2 FPS) Current Pred: 1Cup (74.5%) | All: 25% 75% 0%
[11:12:03.128] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (99.2%) | All: 99% 0% 1%
[11:12:03.289] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (98.2%) | All: 98% 0% 2%
[11:12:03.466] Frame 10: 176 ms (5.7 FPS) Current Pred: 0Blank (97.2%) | All: 97% 0% 3%
[11:12:03.641] Frame 1: 174 ms (5.7 FPS) Current Pred: 0Blank (99.1%) | All: 99% 0% 1%
[11:12:03.800] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (99.6%) | All: 100% 0% 0%
[11:12:03.962] Frame 3: 161 ms (6.2 FPS) Current Pred: 0Blank (99.2%) | All: 99% 0% 1%
[11:12:04.120] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (97.1%) | All: 97% 3% 0%
[11:12:04.282] Frame 5: 161 ms (6.2 FPS) Current Pred: 0Blank (97.5%) | All: 97% 2% 0%
[11:12:04.440] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (99.5%) | All: 99% 0% 0%
[11:12:04.601] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (95.7%) | All: 96% 4% 0%
[11:12:04.760] Frame 8: 160 ms (6.2 FPS) Current Pred: 1Cup (100.0%) | All: 0% 100% 0%
[11:12:04.920] Frame 9: 160 ms (6.2 FPS) Current Pred: 1Cup (100.0%) | All: 0% 100% 0%
[11:12:05.096] Frame 10: 175 ms (5.7 FPS) Current Pred: 0Blank (51.6%) | All: 52% 48% 0%
[11:12:05.274] Frame 1: 176 ms (5.7 FPS) Current Pred: 0Blank (94.7%) | All: 95% 5% 0%
[11:12:05.435] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (95.3%) | All: 95% 1% 4%
[11:12:05.594] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (99.5%) | All: 100% 0% 0%
[11:12:05.756] Frame 4: 162 ms (6.2 FPS) Current Pred: 0Blank (99.9%) | All: 100% 0% 0%
[11:12:05.915] Frame 5: 158 ms (6.3 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[11:12:06.074] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (99.5%) | All: 100% 0% 0%
[11:12:06.233] Frame 7: 159 ms (6.3 FPS) Current Pred: 0Blank (99.4%) | All: 99% 0% 1%
[11:12:06.394] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (99.3%) | All: 99% 0% 1%
[11:12:06.554] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (99.4%) | All: 99% 0% 1%
[11:12:06.730] Frame 10: 176 ms (5.7 FPS) Current Pred: 0Blank (99.4%) | All: 99% 0% 1%
[11:12:06.906] Frame 1: 175 ms (5.7 FPS) Current Pred: 0Blank (99.6%) | All: 100% 0% 0%
[11:12:07.066] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (99.6%) | All: 100% 0% 0%
[11:12:07.225] Frame 3: 159 ms (6.3 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[11:12:07.385] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[11:12:07.546] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (99.6%) | All: 100% 0% 0%
[11:12:07.705] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[11:12:07.866] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (99.9%) | All: 100% 0% 0%
[11:12:08.025] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (100.0%) | All: 100% 0% 0%
[11:12:08.185] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (100.0%) | All: 100% 0% 0%
[11:12:08.363] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (100.0%) | All: 100% 0% 0%
[11:12:08.539] Frame 1: 175 ms (5.7 FPS) Current Pred: 0Blank (99.9%) | All: 100% 0% 0%
[11:12:08.857] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (99.9%) | All: 100% 0% 0%
[11:12:08.862] Frame 3: 159 ms (6.3 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[11:12:09.017] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (100.0%) | All: 100% 0% 0%
[11:12:09.155] cam_hal: FB-OVF
[11:12:09.159] cam_hal: FB-OVF
[11:12:09.274] Frame 5: 256 ms (3.9 FPS) Current Pred: 0Blank (100.0%) | All: 100% 0% 0%
[11:12:09.434] Frame 6: 160 ms (6.2 FPS) Current Pred: 2Pen (52.5%) | All: 37% 11% 53%
[11:12:09.625] Frame 7: 190 ms (5.3 FPS) Current Pred: 0Blank (68.0%) | All: 68% 23% 9%
[11:12:09.785] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (92.7%) | All: 93% 6% 1%
[11:12:09.946] Frame 9: 161 ms (6.2 FPS) Current Pred: 0Blank (95.1%) | All: 95% 4% 1%
[11:12:10.123] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (86.7%) | All: 87% 9% 4%
[11:12:10.298] Frame 1: 173 ms (5.8 FPS) Current Pred: 0Blank (79.4%) | All: 79% 13% 8%
[11:12:10.457] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (95.4%) | All: 95% 3% 2%
[11:12:10.617] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (97.5%) | All: 97% 1% 2%
[11:12:10.778] Frame 4: 159 ms (6.3 FPS) Current Pred: 2Pen (49.7%) | All: 49% 1% 50%
[11:12:10.968] Frame 5: 191 ms (5.2 FPS) Current Pred: 0Blank (95.6%) | All: 96% 0% 4%
[11:12:11.160] Frame 6: 192 ms (5.2 FPS) Current Pred: 0Blank (74.4%) | All: 74% 13% 12%
[11:12:11.321] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (99.7%) | All: 100% 0% 0%
[11:12:11.482] Frame 8: 161 ms (6.2 FPS) Current Pred: 0Blank (99.6%) | All: 100% 0% 0%
[11:12:11.640] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (99.6%) | All: 100% 0% 0%
[11:12:11.820] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (99.5%) | All: 100% 0% 0%
[11:12:11.992] Frame 1: 173 ms (5.8 FPS) Current Pred: 0Blank (99.2%) | All: 99% 0% 1%
[11:12:12.153] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (99.0%) | All: 99% 0% 1%
[11:12:12.314] Frame 3: 161 ms (6.2 FPS) Current Pred: 0Blank (98.8%) | All: 99% 0% 1%
[11:12:12.320] 
[11:12:12.323] === MENU ===
[11:12:12.327] 1. 0Blank
[11:12:12.332] 2. 1Cup
[11:12:12.337] 3. 2Pen
[11:12:12.341] 4. Train
[11:12:12.346] > 5. Infer
[11:12:12.351] Commands: t=next (tap)  l=select (longpress)
[11:12:14.574] 
[11:12:14.580] >>> Training mode
[11:12:14.584] Instructions:
[11:12:14.588] During training: 3+ taps = Save and exit
[11:12:14.592] After completion: TAP = Train again, 3+ taps = Exit
[11:12:14.595] Serial: 'T'=train again, 'L'=exit
[11:12:14.632] Loading weights from SD...
[11:12:16.387] Weights loaded successfully
[11:12:16.400] Continuing from saved weights
[11:12:26.135] Val: 9 images  Train: 108 images
[11:12:26.141] Training: 108 images, 360 batches
[11:12:26.145] 
[11:12:26.149] --- Epoch 1/20 ---
[11:12:51.038] Batch 10/360 - Loss: 0.1102 - Acc: 100.0%
[11:13:11.884] 
[11:13:11.894] --- Epoch 2/20 ---
[11:13:16.762] Batch 20/360 - Loss: 0.0510 - Acc: 100.0%
[11:13:57.661] Batch 30/360 - Loss: 0.1956 - Acc: 100.0%
[11:13:57.671] 
[11:13:57.676] --- Epoch 3/20 ---
[11:14:07.874] Batch 40/360 - Loss: 0.0785 - Acc: 100.0%
[11:14:33.315] Batch 50/360 - Loss: 0.0681 - Acc: 100.0%
[11:14:43.404] 
[11:14:43.409] --- Epoch 4/20 ---
[11:14:58.833] Batch 60/360 - Loss: 0.0844 - Acc: 100.0%
[11:15:23.879] Batch 70/360 - Loss: 0.2780 - Acc: 83.3%
[11:15:29.173] 
[11:15:29.180] --- Epoch 5/20 ---
[11:15:50.101] Batch 80/360 - Loss: 0.1739 - Acc: 100.0%
[11:16:14.938] Batch 90/360 - Loss: 0.0515 - Acc: 100.0%
[11:16:14.944] 
[11:16:14.949] --- Epoch 6/20 ---
[11:16:40.572] Batch 100/360 - Loss: 0.1898 - Acc: 100.0%
[11:17:00.690] 
[11:17:00.702] --- Epoch 7/20 ---
[11:17:05.947] Batch 110/360 - Loss: 0.1364 - Acc: 100.0%
[11:17:31.203] Batch 120/360 - Loss: 0.1730 - Acc: 100.0%
[11:17:46.451] 
[11:17:46.463] --- Epoch 8/20 ---
[11:17:56.715] Batch 130/360 - Loss: 0.1144 - Acc: 100.0%
[11:18:22.187] Batch 140/360 - Loss: 0.1892 - Acc: 83.3%
[11:18:32.198] 
[11:18:32.208] --- Epoch 9/20 ---
[11:18:47.615] Batch 150/360 - Loss: 0.1929 - Acc: 100.0%
[11:19:12.700] Batch 160/360 - Loss: 0.1014 - Acc: 100.0%
[11:19:17.974] 
[11:19:17.984] --- Epoch 10/20 ---
[11:19:38.637] Batch 170/360 - Loss: 0.1023 - Acc: 100.0%
[11:20:03.741] Batch 180/360 - Loss: 0.1270 - Acc: 100.0%
[11:20:03.753] 
[11:20:03.758] --- Epoch 11/20 ---
[11:20:28.969] Batch 190/360 - Loss: 0.2961 - Acc: 83.3%
[11:20:49.491] 
[11:20:49.498] --- Epoch 12/20 ---
[11:20:54.572] Batch 200/360 - Loss: 0.1082 - Acc: 100.0%
[11:21:19.525] Batch 210/360 - Loss: 0.1893 - Acc: 100.0%
[11:21:35.251] 
[11:21:35.265] --- Epoch 13/20 ---
[11:21:45.510] Batch 220/360 - Loss: 0.4929 - Acc: 66.7%
[11:22:10.837] Batch 230/360 - Loss: 0.3396 - Acc: 100.0%
[11:22:21.001] 
[11:22:21.007] --- Epoch 14/20 ---
[11:22:36.194] Batch 240/360 - Loss: 0.1862 - Acc: 100.0%
[11:23:01.565] Batch 250/360 - Loss: 0.2453 - Acc: 100.0%
[11:23:06.764] 
[11:23:06.780] --- Epoch 15/20 ---
[11:23:27.155] Batch 260/360 - Loss: 0.0242 - Acc: 100.0%
[11:23:52.525] Batch 270/360 - Loss: 0.1778 - Acc: 100.0%
[11:23:52.530] 
[11:23:52.535] --- Epoch 16/20 ---
[11:24:18.236] Batch 280/360 - Loss: 0.3600 - Acc: 83.3%
[11:24:38.280] 
[11:24:38.293] --- Epoch 17/20 ---
[11:24:43.389] Batch 290/360 - Loss: 0.3002 - Acc: 83.3%
[11:25:09.250] Batch 300/360 - Loss: 0.1292 - Acc: 100.0%
[11:25:24.061] 
[11:25:24.074] --- Epoch 18/20 ---
[11:25:34.275] Batch 310/360 - Loss: 0.1351 - Acc: 100.0%
[11:25:59.777] Batch 320/360 - Loss: 0.1909 - Acc: 100.0%
[11:26:09.812] 
[11:26:09.824] --- Epoch 19/20 ---
[11:26:24.880] Batch 330/360 - Loss: 0.0374 - Acc: 100.0%
[11:26:50.409] Batch 340/360 - Loss: 0.1030 - Acc: 100.0%
[11:26:55.577] 
[11:26:55.586] --- Epoch 20/20 ---
[11:27:15.871] Batch 350/360 - Loss: 0.2099 - Acc: 100.0%
[11:27:41.339] Batch 360/360 - Loss: 0.0977 - Acc: 100.0%
[11:27:41.349] 
[11:27:41.354] --- Training Complete ---
[11:27:45.375] Validation Accuracy: 66.7%  (6/9 correct)
[11:27:47.246] Weights saved to SD
[11:27:54.766] You can copy /header/myWeights.h to the sketch folder, then uncomment #define USE_BAKED_WEIGHTS
[11:27:54.873] Waiting for input...
[11:27:54.883] Serial: T=train again  L=exit
[11:27:54.887] Touch:  1-2 taps=train again  3+taps=exit
[11:28:07.411] 
[11:28:07.417] === MENU ===
[11:28:07.421] 1. 0Blank
[11:28:07.426] 2. 1Cup
[11:28:07.431] 3. 2Pen
[11:28:07.437] > 4. Train
[11:28:07.443] 5. Infer
[11:28:07.449] Commands: t=next (tap)  l=select (longpress)
[11:28:09.495] 
[11:28:09.502] >>> Inference mode - OPTIMIZED
[11:28:09.506] Instructions:
[11:28:09.511] T or L exit to menu
[11:28:09.611] Frame 1: 115 ms (8.7 FPS) Current Pred: 0Blank (99.1%) | All: 99% 0% 1%
[11:28:09.761] Frame 2: 150 ms (6.7 FPS) Current Pred: 0Blank (90.0%) | All: 90% 1% 9%
[11:28:09.922] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (86.2%) | All: 86% 1% 13%
[11:28:10.081] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (82.5%) | All: 82% 1% 17%
[11:28:10.241] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (77.7%) | All: 78% 1% 21%
[11:28:10.401] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (81.7%) | All: 82% 1% 18%
[11:28:10.563] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[11:28:10.722] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (98.6%) | All: 99% 0% 1%
[11:28:10.882] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (97.8%) | All: 98% 0% 2%
[11:28:11.060] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (98.8%) | All: 99% 0% 1%
[11:28:11.235] Frame 1: 172 ms (5.8 FPS) Current Pred: 0Blank (99.9%) | All: 100% 0% 0%
[11:28:11.394] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (94.7%) | All: 95% 0% 5%
[11:28:11.555] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (86.8%) | All: 87% 1% 12%
[11:28:11.714] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (97.5%) | All: 97% 0% 2%
[11:28:11.874] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (96.8%) | All: 97% 0% 3%
[11:28:12.036] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (98.8%) | All: 99% 0% 1%
[11:28:12.194] Frame 7: 158 ms (6.3 FPS) Current Pred: 0Blank (99.0%) | All: 99% 0% 1%
[11:28:12.354] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (99.5%) | All: 99% 0% 1%
[11:28:12.514] Frame 9: 158 ms (6.3 FPS) Current Pred: 0Blank (99.5%) | All: 100% 0% 0%
[11:28:12.692] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (99.7%) | All: 100% 0% 0%
[11:28:12.866] Frame 1: 174 ms (5.7 FPS) Current Pred: 0Blank (98.5%) | All: 98% 0% 1%
[11:28:13.026] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (92.1%) | All: 92% 1% 6%
[11:28:13.187] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (85.9%) | All: 86% 3% 11%
[11:28:13.346] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (97.8%) | All: 98% 0% 2%
[11:28:13.507] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (96.6%) | All: 97% 0% 3%
[11:28:13.667] Frame 6: 161 ms (6.2 FPS) Current Pred: 0Blank (98.4%) | All: 98% 0% 2%
[11:28:13.827] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (99.2%) | All: 99% 0% 1%
[11:28:13.987] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (91.3%) | All: 91% 3% 6%
[11:28:14.146] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (99.7%) | All: 100% 0% 0%
[11:28:14.325] Frame 10: 179 ms (5.6 FPS) Current Pred: 0Blank (99.3%) | All: 99% 0% 1%
[11:28:14.500] Frame 1: 173 ms (5.8 FPS) Current Pred: 0Blank (99.6%) | All: 100% 0% 0%
[11:28:14.658] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (99.9%) | All: 100% 0% 0%
[11:28:14.820] Frame 3: 162 ms (6.2 FPS) Current Pred: 0Blank (81.2%) | All: 81% 7% 11%
[11:28:14.980] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (71.9%) | All: 72% 28% 1%
[11:28:15.139] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (82.7%) | All: 83% 15% 3%
[11:28:15.299] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (77.3%) | All: 77% 22% 1%
[11:28:15.459] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (89.3%) | All: 89% 10% 1%
[11:28:15.619] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (98.7%) | All: 99% 1% 0%
[11:28:15.779] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (95.4%) | All: 95% 4% 1%
[11:28:15.957] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (99.1%) | All: 99% 0% 1%
[11:28:16.132] Frame 1: 173 ms (5.8 FPS) Current Pred: 0Blank (97.2%) | All: 97% 0% 3%
[11:28:16.292] Frame 2: 161 ms (6.2 FPS) Current Pred: 0Blank (98.3%) | All: 98% 0% 2%
[11:28:16.450] Frame 3: 159 ms (6.3 FPS) Current Pred: 0Blank (98.3%) | All: 98% 0% 2%
[11:28:16.611] Frame 4: 161 ms (6.2 FPS) Current Pred: 0Blank (98.9%) | All: 99% 0% 1%
[11:28:16.771] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (98.3%) | All: 98% 0% 2%
[11:28:16.932] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (98.4%) | All: 98% 0% 2%
[11:28:17.090] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (98.2%) | All: 98% 0% 2%
[11:28:17.253] Frame 8: 162 ms (6.2 FPS) Current Pred: 0Blank (92.5%) | All: 92% 5% 3%
[11:28:17.411] Frame 9: 158 ms (6.3 FPS) Current Pred: 0Blank (89.4%) | All: 89% 10% 0%
[11:28:17.588] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (99.0%) | All: 99% 1% 0%
[11:28:17.765] Frame 1: 175 ms (5.7 FPS) Current Pred: 0Blank (98.8%) | All: 99% 0% 1%
[11:28:17.923] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (75.5%) | All: 75% 22% 3%
[11:28:18.083] Frame 3: 159 ms (6.3 FPS) Current Pred: 0Blank (86.6%) | All: 87% 13% 0%
[11:28:18.245] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (87.1%) | All: 87% 12% 1%
[11:28:18.405] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (77.6%) | All: 78% 22% 1%
[11:28:18.565] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (89.9%) | All: 90% 10% 0%
[11:28:18.725] Frame 7: 159 ms (6.3 FPS) Current Pred: 0Blank (89.5%) | All: 90% 10% 0%
[11:28:18.886] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (92.7%) | All: 93% 7% 0%
[11:28:19.044] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (93.5%) | All: 94% 6% 0%
[11:28:19.223] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (89.8%) | All: 90% 10% 0%
[11:28:19.398] Frame 1: 174 ms (5.7 FPS) Current Pred: 0Blank (82.4%) | All: 82% 18% 0%
[11:28:19.556] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (92.2%) | All: 92% 7% 0%
[11:28:19.750] Frame 3: 192 ms (5.2 FPS) Current Pred: 0Blank (91.1%) | All: 91% 2% 7%
[11:28:19.909] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (99.0%) | All: 99% 0% 1%
[11:28:20.068] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (99.7%) | All: 100% 0% 0%
[11:28:20.228] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (99.2%) | All: 99% 0% 1%
[11:28:20.389] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (98.6%) | All: 99% 0% 1%
[11:28:20.548] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (99.3%) | All: 99% 0% 1%
[11:28:20.707] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (99.3%) | All: 99% 0% 1%
[11:28:20.888] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (99.1%) | All: 99% 0% 1%
[11:28:21.060] Frame 1: 174 ms (5.7 FPS) Current Pred: 0Blank (98.7%) | All: 99% 0% 1%
[11:28:21.220] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (99.0%) | All: 99% 0% 1%
[11:28:21.383] Frame 3: 161 ms (6.2 FPS) Current Pred: 0Blank (99.3%) | All: 99% 0% 1%
[11:28:21.541] Frame 4: 158 ms (6.3 FPS) Current Pred: 0Blank (98.4%) | All: 98% 0% 2%
[11:28:21.700] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (98.6%) | All: 99% 0% 1%
[11:28:21.861] Frame 6: 161 ms (6.2 FPS) Current Pred: 0Blank (89.4%) | All: 89% 3% 7%
[11:28:22.022] Frame 7: 161 ms (6.2 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[11:28:22.183] Frame 8: 161 ms (6.2 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[11:28:22.343] Frame 9: 159 ms (6.3 FPS) Current Pred: 2Pen (67.3%) | All: 11% 22% 67%
[11:28:22.518] Frame 10: 175 ms (5.7 FPS) Current Pred: 1Cup (98.4%) | All: 1% 98% 0%
[11:28:22.693] Frame 1: 174 ms (5.7 FPS) Current Pred: 0Blank (100.0%) | All: 100% 0% 0%
[11:28:22.853] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (99.9%) | All: 100% 0% 0%
[11:28:23.044] Frame 3: 191 ms (5.2 FPS) Current Pred: 0Blank (76.4%) | All: 76% 11% 13%
[11:28:23.205] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (99.3%) | All: 99% 0% 1%
[11:28:23.365] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (99.5%) | All: 99% 0% 0%
[11:28:23.524] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (99.4%) | All: 99% 0% 1%
[11:28:23.684] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (99.5%) | All: 99% 0% 0%
[11:28:23.846] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (99.4%) | All: 99% 0% 1%
[11:28:24.005] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (99.3%) | All: 99% 0% 1%
[11:28:24.183] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (99.4%) | All: 99% 0% 1%
[11:28:24.359] Frame 1: 174 ms (5.7 FPS) Current Pred: 0Blank (99.4%) | All: 99% 0% 1%
[11:28:24.516] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (99.4%) | All: 99% 0% 1%
[11:28:24.677] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (99.4%) | All: 99% 0% 0%
[11:28:24.838] Frame 4: 161 ms (6.2 FPS) Current Pred: 0Blank (99.5%) | All: 99% 0% 0%
[11:28:24.847] 
[11:28:24.851] === MENU ===
[11:28:24.858] 1. 0Blank
[11:28:24.864] 2. 1Cup
[11:28:24.870] 3. 2Pen
[11:28:24.877] 4. Train
[11:28:24.883] > 5. Infer
[11:28:24.890] Commands: t=next (tap)  l=select (longpress)
[11:28:35.012] 
[11:28:35.018] >>> Inference mode - OPTIMIZED
[11:28:35.024] Instructions:
[11:28:35.030] T or L exit to menu
[11:28:35.128] Frame 1: 116 ms (8.6 FPS) Current Pred: 0Blank (99.5%) | All: 100% 0% 0%
[11:28:35.305] Frame 2: 177 ms (5.6 FPS) Current Pred: 1Cup (57.6%) | All: 40% 58% 3%
[11:28:35.465] Frame 3: 159 ms (6.3 FPS) Current Pred: 2Pen (70.9%) | All: 29% 0% 71%
[11:28:35.624] Frame 4: 160 ms (6.2 FPS) Current Pred: 1Cup (68.7%) | All: 9% 69% 23%
[11:28:35.784] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (59.4%) | All: 59% 0% 41%
[11:28:35.947] Frame 6: 163 ms (6.1 FPS) Current Pred: 0Blank (100.0%) | All: 100% 0% 0%
[11:28:36.106] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (79.2%) | All: 79% 0% 21%
[11:28:36.270] Frame 8: 161 ms (6.2 FPS) Current Pred: 1Cup (77.3%) | All: 18% 77% 5%
[11:28:36.428] Frame 9: 160 ms (6.2 FPS) Current Pred: 1Cup (36.3%) | All: 28% 36% 36%
[11:28:36.603] Frame 10: 174 ms (5.7 FPS) Current Pred: 0Blank (95.8%) | All: 96% 1% 3%
[11:28:36.779] Frame 1: 174 ms (5.7 FPS) Current Pred: 2Pen (99.2%) | All: 0% 1% 99%
[11:28:36.970] Frame 2: 191 ms (5.2 FPS) Current Pred: 0Blank (97.1%) | All: 97% 0% 3%
[11:28:37.130] Frame 3: 160 ms (6.2 FPS) Current Pred: 2Pen (80.8%) | All: 19% 0% 81%
[11:28:37.289] Frame 4: 159 ms (6.3 FPS) Current Pred: 2Pen (57.4%) | All: 43% 0% 57%
[11:28:37.450] Frame 5: 159 ms (6.3 FPS) Current Pred: 2Pen (73.9%) | All: 25% 1% 74%
[11:28:37.673] Frame 6: 223 ms (4.5 FPS) Current Pred: 0Blank (99.8%) | All: 100% 0% 0%
[11:28:37.834] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (91.2%) | All: 91% 0% 9%
[11:28:37.994] Frame 8: 160 ms (6.2 FPS) Current Pred: 2Pen (82.3%) | All: 0% 18% 82%
[11:28:38.153] Frame 9: 158 ms (6.3 FPS) Current Pred: 0Blank (89.9%) | All: 90% 1% 9%
[11:28:38.330] Frame 10: 177 ms (5.6 FPS) Current Pred: 2Pen (81.7%) | All: 17% 1% 82%
[11:28:38.509] Frame 1: 179 ms (5.6 FPS) Current Pred: 0Blank (33.6%) | All: 34% 33% 33%
[11:28:38.669] Frame 2: 158 ms (6.3 FPS) Current Pred: 0Blank (84.1%) | All: 84% 0% 16%
[11:28:38.827] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (99.9%) | All: 100% 0% 0%
[11:28:38.988] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (98.1%) | All: 98% 0% 2%
[11:28:39.148] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (94.3%) | All: 94% 5% 1%
[11:28:39.310] Frame 6: 162 ms (6.2 FPS) Current Pred: 1Cup (74.9%) | All: 10% 75% 16%
[11:28:39.470] Frame 7: 159 ms (6.3 FPS) Current Pred: 0Blank (98.4%) | All: 98% 0% 2%
[11:28:39.626] Frame 8: 157 ms (6.4 FPS) Current Pred: 0Blank (100.0%) | All: 100% 0% 0%
[11:28:39.787] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (97.1%) | All: 97% 0% 3%
[11:28:39.964] Frame 10: 177 ms (5.6 FPS) Current Pred: 2Pen (100.0%) | All: 0% 0% 100%
[11:28:40.139] Frame 1: 173 ms (5.8 FPS) Current Pred: 0Blank (79.5%) | All: 79% 3% 17%
[11:28:40.331] Frame 2: 193 ms (5.2 FPS) Current Pred: 2Pen (61.1%) | All: 29% 10% 61%
[11:28:40.491] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (43.3%) | All: 43% 41% 15%
[11:28:40.652] Frame 4: 160 ms (6.2 FPS) Current Pred: 1Cup (83.4%) | All: 1% 83% 15%
[11:28:40.811] Frame 5: 160 ms (6.2 FPS) Current Pred: 1Cup (55.4%) | All: 2% 55% 43%
[11:28:40.972] Frame 6: 160 ms (6.2 FPS) Current Pred: 2Pen (97.9%) | All: 1% 2% 98%
[11:28:41.134] Frame 7: 160 ms (6.2 FPS) Current Pred: 2Pen (97.3%) | All: 1% 2% 97%
[11:28:41.292] Frame 8: 160 ms (6.2 FPS) Current Pred: 2Pen (95.5%) | All: 2% 3% 96%
[11:28:41.451] Frame 9: 159 ms (6.3 FPS) Current Pred: 2Pen (80.9%) | All: 17% 2% 81%
[11:28:41.460] 
[11:28:41.468] === MENU ===
[11:28:41.475] 1. 0Blank
[11:28:41.482] 2. 1Cup
[11:28:41.490] 3. 2Pen
[11:28:41.497] 4. Train
[11:28:41.505] > 5. Infer
[11:28:41.510] Commands: t=next (tap)  l=select (longpress)


```
