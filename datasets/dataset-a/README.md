


## Steps to reproduce on-device-ai experiment 1


1.Copy files in "for-sd-card to the micro sd card
2. Load irmware.ino after changing the lines 

```
#define NUM_CLASSES 2

String myClassLabels[NUM_CLASSES] = {"0Blank", "1Circle"};

```

Using serial monitor or touch pin A0, triple tap to enter menu "L" on serial monitor

Train 

Infer


Here is the full serial print for 4 training runs live

```
--- Connected @ 115200 baud: 3/31/2026, 9:21:34 AM ---
[09:21:34.094] amera initialized
[09:21:34.096] 
[09:21:34.096] === Allocating Memory ===
[09:21:34.098] Free PSRAM after allocation: 7654172 bytes
[09:21:34.099] He-init random weights set
[09:21:34.100] No SD weights file found
[09:21:34.101] 
[09:21:34.102] === MENU ===
[09:21:34.102] > 1. 0Blank
[09:21:34.104] 2. 1Circle
[09:21:34.104] 3. Train
[09:21:34.105] 4. Infer
[09:21:34.105] Commands: t=next (tap)  l=select (longpress)
[09:21:35.342] System ready - Tap A0 to navigate, 3+ taps to select
[09:21:35.345] 
[09:21:35.346] === MENU ===
[09:21:35.347] > 1. 0Blank
[09:21:35.348] 2. 1Circle
[09:21:35.349] 3. Train
[09:21:35.350] 4. Infer
[09:21:35.351] Commands: t=next (tap)  l=select (longpress)
[09:22:26.977] ERROR: No trained weights! Please run menu item 4 (Train) first.
[09:22:29.992] 
[09:22:29.998] === MENU ===
[09:22:30.004] 1. 0Blank
[09:22:30.008] 2. 1Circle
[09:22:30.011] 3. Train
[09:22:30.016] > 4. Infer
[09:22:30.019] Commands: t=next (tap)  l=select (longpress)
[09:22:34.904] 
[09:22:34.906] >>> Training mode
[09:22:34.906] Instructions:
[09:22:34.907] During training: 3+ taps = Save and exit
[09:22:34.908] After completion: TAP = Train again, 3+ taps = Exit
[09:22:34.908] Serial: 'T'=train again, 'L'=exit
[09:22:35.093] No SD weights file found
[09:22:35.099] Starting fresh training
[09:22:36.014] Val: 6 images  Train: 12 images
[09:22:36.020] Training: 12 images, 40 batches
[09:22:36.024] 
[09:22:36.028] --- Epoch 1/20 ---
[09:22:40.014] 
[09:22:40.020] --- Epoch 2/20 ---
[09:22:44.016] 
[09:22:44.021] --- Epoch 3/20 ---
[09:22:48.031] 
[09:22:48.037] --- Epoch 4/20 ---
[09:22:52.032] 
[09:22:52.034] --- Epoch 5/20 ---
[09:22:56.048] Batch 10/40 - Loss: 0.6605 - Acc: 50.0%
[09:22:56.055] 
[09:22:56.059] --- Epoch 6/20 ---
[09:23:00.050] 
[09:23:00.056] --- Epoch 7/20 ---
[09:23:04.051] 
[09:23:04.058] --- Epoch 8/20 ---
[09:23:08.068] 
[09:23:08.075] --- Epoch 9/20 ---
[09:23:12.070] 
[09:23:12.076] --- Epoch 10/20 ---
[09:23:16.083] Batch 20/40 - Loss: 0.5993 - Acc: 100.0%
[09:23:16.085] 
[09:23:16.086] --- Epoch 11/20 ---
[09:23:20.087] 
[09:23:20.093] --- Epoch 12/20 ---
[09:23:24.088] 
[09:23:24.093] --- Epoch 13/20 ---
[09:23:28.103] 
[09:23:28.109] --- Epoch 14/20 ---
[09:23:32.104] 
[09:23:32.106] --- Epoch 15/20 ---
[09:23:36.121] Batch 30/40 - Loss: 0.5474 - Acc: 100.0%
[09:23:36.127] 
[09:23:36.135] --- Epoch 16/20 ---
[09:23:40.125] 
[09:23:40.133] --- Epoch 17/20 ---
[09:23:44.125] 
[09:23:44.127] --- Epoch 18/20 ---
[09:23:48.142] 
[09:23:48.150] --- Epoch 19/20 ---
[09:23:52.148] 
[09:23:52.154] --- Epoch 20/20 ---
[09:23:56.163] Batch 40/40 - Loss: 0.4710 - Acc: 100.0%
[09:23:56.171] 
[09:23:56.178] --- Training Complete ---
[09:23:57.663] Validation Accuracy: 83.3%  (5/6 correct)
[09:23:59.097] Weights saved to SD
[09:24:04.238] You can copy /header/myWeights.h to the sketch folder, then uncomment #define USE_BAKED_WEIGHTS
[09:24:04.395] Waiting for input...
[09:24:04.402] Serial: T=train again  L=exit
[09:24:04.408] Touch:  1-2 taps=train again  3+taps=exit
[09:24:06.815] 
[09:24:06.817] === MENU ===
[09:24:06.818] 1. 0Blank
[09:24:06.819] 2. 1Circle
[09:24:06.821] > 3. Train
[09:24:06.822] 4. Infer
[09:24:06.823] Commands: t=next (tap)  l=select (longpress)
[09:24:09.893] 
[09:24:09.895] >>> Inference mode - OPTIMIZED
[09:24:09.896] Instructions:
[09:24:09.898] T or L exit to menu
[09:24:09.899] Resize lookup tables initialized
[09:24:10.004] Frame 1: 110 ms (9.1 FPS) Current Pred: 0Blank (51.5%) | All: 51% 49%
[09:24:10.164] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (50.8%) | All: 51% 49%
[09:24:10.324] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (50.8%) | All: 51% 49%
[09:24:10.483] Frame 4: 159 ms (6.3 FPS) Current Pred: 1Circle (52.1%) | All: 48% 52%
[09:24:10.644] Frame 5: 161 ms (6.2 FPS) Current Pred: 0Blank (50.0%) | All: 50% 50%
[09:24:10.804] Frame 6: 159 ms (6.3 FPS) Current Pred: 1Circle (51.3%) | All: 49% 51%
[09:24:10.884] cam_hal: FB-OVF
[09:24:10.993] Frame 7: 189 ms (5.3 FPS) Current Pred: 0Blank (51.4%) | All: 51% 49%
[09:24:11.152] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (64.3%) | All: 64% 36%
[09:24:11.312] Frame 9: 160 ms (6.2 FPS) Current Pred: 1Circle (50.3%) | All: 50% 50%
[09:24:11.490] Frame 10: 177 ms (5.6 FPS) Current Pred: 1Circle (54.2%) | All: 46% 54%
[09:24:11.632] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (60.4%) | All: 60% 40%
[09:24:11.792] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (50.0%) | All: 50% 50%
[09:24:11.954] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (63.9%) | All: 64% 36%
[09:24:12.113] Frame 4: 160 ms (6.2 FPS) Current Pred: 1Circle (53.2%) | All: 47% 53%
[09:24:12.271] Frame 5: 158 ms (6.3 FPS) Current Pred: 1Circle (60.3%) | All: 40% 60%
[09:24:12.431] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (52.8%) | All: 53% 47%
[09:24:12.591] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (51.6%) | All: 52% 48%
[09:24:12.752] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (55.8%) | All: 56% 44%
[09:24:12.911] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (56.5%) | All: 57% 43%
[09:24:13.089] Frame 10: 177 ms (5.6 FPS) Current Pred: 1Circle (59.7%) | All: 40% 60%
[09:24:13.231] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (50.7%) | All: 51% 49%
[09:24:13.392] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (56.0%) | All: 56% 44%
[09:24:13.552] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (56.4%) | All: 56% 44%
[09:24:13.712] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (55.2%) | All: 55% 45%
[09:24:13.872] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (56.3%) | All: 56% 44%
[09:24:14.032] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (55.8%) | All: 56% 44%
[09:24:14.192] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (55.5%) | All: 55% 45%
[09:24:14.352] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (57.1%) | All: 57% 43%
[09:24:14.543] Frame 9: 192 ms (5.2 FPS) Current Pred: 0Blank (51.4%) | All: 51% 49%
[09:24:14.723] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (54.2%) | All: 54% 46%
[09:24:14.864] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (57.0%) | All: 57% 43%
[09:24:15.025] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (57.0%) | All: 57% 43%
[09:24:15.185] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (63.9%) | All: 64% 36%
[09:24:15.345] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (62.2%) | All: 62% 38%
[09:24:15.506] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (63.6%) | All: 64% 36%
[09:24:15.665] Frame 6: 159 ms (6.3 FPS) Current Pred: 1Circle (62.4%) | All: 38% 62%
[09:24:15.825] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (58.4%) | All: 58% 42%
[09:24:15.985] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (52.5%) | All: 52% 48%
[09:24:16.146] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (53.2%) | All: 53% 47%
[09:24:16.323] Frame 10: 177 ms (5.6 FPS) Current Pred: 1Circle (59.1%) | All: 41% 59%
[09:24:16.466] Frame 1: 142 ms (7.0 FPS) Current Pred: 1Circle (68.3%) | All: 32% 68%
[09:24:16.625] Frame 2: 160 ms (6.2 FPS) Current Pred: 1Circle (57.7%) | All: 42% 58%
[09:24:16.785] Frame 3: 160 ms (6.2 FPS) Current Pred: 1Circle (63.1%) | All: 37% 63%
[09:24:16.945] Frame 4: 160 ms (6.2 FPS) Current Pred: 1Circle (63.8%) | All: 36% 64%
[09:24:17.106] Frame 5: 160 ms (6.2 FPS) Current Pred: 1Circle (51.8%) | All: 48% 52%
[09:24:17.265] Frame 6: 160 ms (6.2 FPS) Current Pred: 1Circle (53.8%) | All: 46% 54%
[09:24:17.425] Frame 7: 160 ms (6.2 FPS) Current Pred: 1Circle (53.1%) | All: 47% 53%
[09:24:17.585] Frame 8: 160 ms (6.2 FPS) Current Pred: 1Circle (63.7%) | All: 36% 64%
[09:24:17.745] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (58.8%) | All: 59% 41%
[09:24:17.923] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (59.7%) | All: 60% 40%
[09:24:18.067] Frame 1: 143 ms (7.0 FPS) Current Pred: 0Blank (56.2%) | All: 56% 44%
[09:24:18.226] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (56.7%) | All: 57% 43%
[09:24:18.385] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (51.4%) | All: 51% 49%
[09:24:18.546] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (52.9%) | All: 53% 47%
[09:24:18.706] Frame 5: 158 ms (6.3 FPS) Current Pred: 0Blank (55.4%) | All: 55% 45%
[09:24:18.865] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (53.7%) | All: 54% 46%
[09:24:19.027] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (53.4%) | All: 53% 47%
[09:24:19.186] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (52.7%) | All: 53% 47%
[09:24:19.346] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (53.0%) | All: 53% 47%
[09:24:19.523] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (54.3%) | All: 54% 46%
[09:24:19.827] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (54.8%) | All: 55% 45%
[09:24:19.846] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (57.1%) | All: 57% 43%
[09:24:19.986] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (56.4%) | All: 56% 44%
[09:24:20.146] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (53.9%) | All: 54% 46%
[09:24:20.306] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (59.9%) | All: 60% 40%
[09:24:20.466] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (54.0%) | All: 54% 46%
[09:24:20.626] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (54.1%) | All: 54% 46%
[09:24:20.786] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (54.0%) | All: 54% 46%
[09:24:20.946] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (54.6%) | All: 55% 45%
[09:24:21.124] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (50.3%) | All: 50% 50%
[09:24:21.266] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (51.2%) | All: 51% 49%
[09:24:21.427] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (50.9%) | All: 51% 49%
[09:24:21.587] Frame 3: 161 ms (6.2 FPS) Current Pred: 0Blank (53.1%) | All: 53% 47%
[09:24:21.746] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (51.9%) | All: 52% 48%
[09:24:21.905] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (52.5%) | All: 52% 48%
[09:24:22.067] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (52.3%) | All: 52% 48%
[09:24:22.227] Frame 7: 159 ms (6.3 FPS) Current Pred: 0Blank (52.0%) | All: 52% 48%
[09:24:22.385] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (54.0%) | All: 54% 46%
[09:24:22.547] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (52.2%) | All: 52% 48%
[09:24:22.723] Frame 10: 176 ms (5.7 FPS) Current Pred: 0Blank (53.0%) | All: 53% 47%
[09:24:22.866] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (54.3%) | All: 54% 46%
[09:24:23.027] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (51.7%) | All: 52% 48%
[09:24:23.186] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (52.9%) | All: 53% 47%
[09:24:23.347] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (53.9%) | All: 54% 46%
[09:24:23.506] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (59.3%) | All: 59% 41%
[09:24:23.666] Frame 6: 159 ms (6.3 FPS) Current Pred: 1Circle (53.1%) | All: 47% 53%
[09:24:23.834] Frame 7: 161 ms (6.2 FPS) Current Pred: 0Blank (55.0%) | All: 55% 45%
[09:24:23.987] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (52.8%) | All: 53% 47%
[09:24:24.147] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (62.3%) | All: 62% 38%
[09:24:24.324] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (65.6%) | All: 66% 34%
[09:24:24.467] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (55.2%) | All: 55% 45%
[09:24:24.483] 
[09:24:24.491] === MENU ===
[09:24:24.497] 1. 0Blank
[09:24:24.500] 2. 1Circle
[09:24:24.502] 3. Train
[09:24:24.504] > 4. Infer
[09:24:24.506] Commands: t=next (tap)  l=select (longpress)
[09:24:26.565] 
[09:24:26.568] >>> Training mode
[09:24:26.570] Instructions:
[09:24:26.573] During training: 3+ taps = Save and exit
[09:24:26.575] After completion: TAP = Train again, 3+ taps = Exit
[09:24:26.579] Serial: 'T'=train again, 'L'=exit
[09:24:26.625] Loading weights from SD...
[09:24:27.830] Weights loaded successfully
[09:24:27.846] Continuing from saved weights
[09:24:28.750] Val: 6 images  Train: 12 images
[09:24:28.759] Training: 12 images, 40 batches
[09:24:28.768] 
[09:24:28.775] --- Epoch 1/20 ---
[09:24:32.752] 
[09:24:32.770] --- Epoch 2/20 ---
[09:24:40.770] 
[09:24:40.787] --- Epoch 3/20 ---
[09:24:40.800] 
[09:24:40.806] --- Epoch 4/20 ---
[09:24:44.772] 
[09:24:44.790] --- Epoch 5/20 ---
[09:24:48.785] Batch 10/40 - Loss: 0.3814 - Acc: 100.0%
[09:24:48.788] 
[09:24:48.793] --- Epoch 6/20 ---
[09:24:52.791] 
[09:24:52.807] --- Epoch 7/20 ---
[09:24:56.793] 
[09:24:56.810] --- Epoch 8/20 ---
[09:25:00.808] 
[09:25:00.822] --- Epoch 9/20 ---
[09:25:04.812] 
[09:25:04.830] --- Epoch 10/20 ---
[09:25:08.829] Batch 20/40 - Loss: 0.3217 - Acc: 100.0%
[09:25:08.846] 
[09:25:08.856] --- Epoch 11/20 ---
[09:25:12.832] 
[09:25:12.850] --- Epoch 12/20 ---
[09:25:16.838] 
[09:25:16.856] --- Epoch 13/20 ---
[09:25:20.855] 
[09:25:20.872] --- Epoch 14/20 ---
[09:25:24.861] 
[09:25:24.877] --- Epoch 15/20 ---
[09:25:28.879] Batch 30/40 - Loss: 0.2920 - Acc: 100.0%
[09:25:28.897] 
[09:25:28.910] --- Epoch 16/20 ---
[09:25:32.884] 
[09:25:32.903] --- Epoch 17/20 ---
[09:25:36.886] 
[09:25:36.902] --- Epoch 18/20 ---
[09:25:40.910] 
[09:25:40.926] --- Epoch 19/20 ---
[09:25:44.910] 
[09:25:44.922] --- Epoch 20/20 ---
[09:25:48.926] Batch 40/40 - Loss: 0.2623 - Acc: 100.0%
[09:25:48.941] 
[09:25:48.949] --- Training Complete ---
[09:25:50.425] Validation Accuracy: 83.3%  (5/6 correct)
[09:25:51.751] Weights saved to SD
[09:25:56.785] You can copy /header/myWeights.h to the sketch folder, then uncomment #define USE_BAKED_WEIGHTS
[09:25:56.943] Waiting for input...
[09:25:56.965] Serial: T=train again  L=exit
[09:25:56.974] Touch:  1-2 taps=train again  3+taps=exit
[09:25:58.933] 
[09:25:58.937] === MENU ===
[09:25:58.941] 1. 0Blank
[09:25:58.945] 2. 1Circle
[09:25:58.948] > 3. Train
[09:25:58.951] 4. Infer
[09:25:58.955] Commands: t=next (tap)  l=select (longpress)
[09:26:00.416] 
[09:26:00.421] >>> Inference mode - OPTIMIZED
[09:26:00.426] Instructions:
[09:26:00.430] T or L exit to menu
[09:26:00.524] Frame 1: 108 ms (9.3 FPS) Current Pred: 0Blank (82.3%) | All: 82% 18%
[09:26:00.683] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (82.3%) | All: 82% 18%
[09:26:00.843] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (82.1%) | All: 82% 18%
[09:26:01.004] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (81.9%) | All: 82% 18%
[09:26:01.163] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (82.3%) | All: 82% 18%
[09:26:01.323] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (79.3%) | All: 79% 21%
[09:26:01.484] Frame 7: 161 ms (6.2 FPS) Current Pred: 0Blank (88.1%) | All: 88% 12%
[09:26:01.642] Frame 8: 159 ms (6.3 FPS) Current Pred: 1Circle (63.6%) | All: 36% 64%
[09:26:01.813] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (79.2%) | All: 79% 21%
[09:26:01.982] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (67.8%) | All: 68% 32%
[09:26:02.123] Frame 1: 141 ms (7.1 FPS) Current Pred: 0Blank (53.5%) | All: 54% 46%
[09:26:02.284] Frame 2: 160 ms (6.2 FPS) Current Pred: 1Circle (52.0%) | All: 48% 52%
[09:26:02.443] Frame 3: 160 ms (6.2 FPS) Current Pred: 1Circle (56.7%) | All: 43% 57%
[09:26:02.604] Frame 4: 160 ms (6.2 FPS) Current Pred: 1Circle (56.9%) | All: 43% 57%
[09:26:02.764] Frame 5: 160 ms (6.2 FPS) Current Pred: 1Circle (50.6%) | All: 49% 51%
[09:26:02.925] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (51.7%) | All: 52% 48%
[09:26:03.084] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (59.0%) | All: 59% 41%
[09:26:03.244] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (58.6%) | All: 59% 41%
[09:26:03.405] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (54.2%) | All: 54% 46%
[09:26:03.582] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (56.1%) | All: 56% 44%
[09:26:03.724] Frame 1: 141 ms (7.1 FPS) Current Pred: 0Blank (60.8%) | All: 61% 39%
[09:26:03.883] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (73.6%) | All: 74% 26%
[09:26:04.043] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (64.1%) | All: 64% 36%
[09:26:04.204] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (55.0%) | All: 55% 45%
[09:26:04.364] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (59.7%) | All: 60% 40%
[09:26:04.525] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (55.8%) | All: 56% 44%
[09:26:04.684] Frame 7: 159 ms (6.3 FPS) Current Pred: 0Blank (55.1%) | All: 55% 45%
[09:26:04.844] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (60.6%) | All: 61% 39%
[09:26:05.005] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (54.4%) | All: 54% 46%
[09:26:05.182] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (54.3%) | All: 54% 46%
[09:26:05.326] Frame 1: 141 ms (7.1 FPS) Current Pred: 0Blank (53.9%) | All: 54% 46%
[09:26:05.485] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (56.9%) | All: 57% 43%
[09:26:05.644] Frame 3: 159 ms (6.3 FPS) Current Pred: 0Blank (61.6%) | All: 62% 38%
[09:26:05.804] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (60.1%) | All: 60% 40%
[09:26:05.964] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (59.7%) | All: 60% 40%
[09:26:06.124] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (61.2%) | All: 61% 39%
[09:26:06.284] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (62.2%) | All: 62% 38%
[09:26:06.444] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (65.7%) | All: 66% 34%
[09:26:06.605] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (65.6%) | All: 66% 34%
[09:26:06.783] Frame 10: 176 ms (5.7 FPS) Current Pred: 0Blank (57.5%) | All: 57% 43%
[09:26:06.925] Frame 1: 142 ms (7.0 FPS) Current Pred: 1Circle (60.6%) | All: 39% 61%
[09:26:07.085] Frame 2: 160 ms (6.2 FPS) Current Pred: 1Circle (59.5%) | All: 41% 59%
[09:26:07.245] Frame 3: 160 ms (6.2 FPS) Current Pred: 1Circle (65.7%) | All: 34% 66%
[09:26:07.405] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (50.6%) | All: 51% 49%
[09:26:07.566] Frame 5: 160 ms (6.2 FPS) Current Pred: 1Circle (60.6%) | All: 39% 61%
[09:26:07.725] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (76.6%) | All: 77% 23%
[09:26:07.885] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (66.7%) | All: 67% 33%
[09:26:08.044] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (61.5%) | All: 61% 39%
[09:26:08.206] Frame 9: 160 ms (6.2 FPS) Current Pred: 1Circle (54.5%) | All: 46% 54%
[09:26:08.383] Frame 10: 177 ms (5.6 FPS) Current Pred: 1Circle (59.6%) | All: 40% 60%
[09:26:08.526] Frame 1: 142 ms (7.0 FPS) Current Pred: 1Circle (53.1%) | All: 47% 53%
[09:26:08.685] Frame 2: 160 ms (6.2 FPS) Current Pred: 1Circle (56.6%) | All: 43% 57%
[09:26:08.845] Frame 3: 160 ms (6.2 FPS) Current Pred: 1Circle (61.6%) | All: 38% 62%
[09:26:09.006] Frame 4: 160 ms (6.2 FPS) Current Pred: 1Circle (61.7%) | All: 38% 62%
[09:26:09.165] Frame 5: 160 ms (6.2 FPS) Current Pred: 1Circle (60.9%) | All: 39% 61%
[09:26:09.327] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (55.3%) | All: 55% 45%
[09:26:09.487] Frame 7: 159 ms (6.3 FPS) Current Pred: 0Blank (71.3%) | All: 71% 29%
[09:26:09.645] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (68.4%) | All: 68% 32%
[09:26:09.806] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (66.7%) | All: 67% 33%
[09:26:09.983] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (68.0%) | All: 68% 32%
[09:26:10.126] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (64.9%) | All: 65% 35%
[09:26:10.285] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (61.9%) | All: 62% 38%
[09:26:10.446] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (63.0%) | All: 63% 37%
[09:26:10.606] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (66.0%) | All: 66% 34%
[09:26:10.766] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (66.0%) | All: 66% 34%
[09:26:10.926] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (61.4%) | All: 61% 39%
[09:26:11.086] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (61.2%) | All: 61% 39%
[09:26:11.246] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (62.5%) | All: 62% 38%
[09:26:11.406] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (68.1%) | All: 68% 32%
[09:26:11.584] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (68.1%) | All: 68% 32%
[09:26:11.725] Frame 1: 141 ms (7.1 FPS) Current Pred: 0Blank (66.9%) | All: 67% 33%
[09:26:11.886] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (60.2%) | All: 60% 40%
[09:26:12.046] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (69.4%) | All: 69% 31%
[09:26:12.206] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (71.7%) | All: 72% 28%
[09:26:12.366] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (63.2%) | All: 63% 37%
[09:26:12.526] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (62.4%) | All: 62% 38%
[09:26:12.687] Frame 7: 161 ms (6.2 FPS) Current Pred: 0Blank (80.4%) | All: 80% 20%
[09:26:12.845] Frame 8: 158 ms (6.3 FPS) Current Pred: 0Blank (73.4%) | All: 73% 27%
[09:26:13.006] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (71.4%) | All: 71% 29%
[09:26:13.183] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (71.5%) | All: 72% 28%
[09:26:13.326] Frame 1: 141 ms (7.1 FPS) Current Pred: 0Blank (71.3%) | All: 71% 29%
[09:26:13.486] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (71.9%) | All: 72% 28%
[09:26:13.646] Frame 3: 159 ms (6.3 FPS) Current Pred: 0Blank (73.1%) | All: 73% 27%
[09:26:13.668] 
[09:26:13.681] === MENU ===
[09:26:13.698] 1. 0Blank
[09:26:13.710] 2. 1Circle
[09:26:13.723] 3. Train
[09:26:13.733] > 4. Infer
[09:26:13.741] Commands: t=next (tap)  l=select (longpress)
[09:26:15.958] 
[09:26:15.963] >>> Training mode
[09:26:15.968] Instructions:
[09:26:15.972] During training: 3+ taps = Save and exit
[09:26:15.978] After completion: TAP = Train again, 3+ taps = Exit
[09:26:15.982] Serial: 'T'=train again, 'L'=exit
[09:26:16.017] Loading weights from SD...
[09:26:17.223] Weights loaded successfully
[09:26:17.248] Continuing from saved weights
[09:26:18.142] Val: 6 images  Train: 12 images
[09:26:18.158] Training: 12 images, 40 batches
[09:26:18.165] 
[09:26:18.170] --- Epoch 1/20 ---
[09:26:22.146] 
[09:26:22.165] --- Epoch 2/20 ---
[09:26:26.153] 
[09:26:26.166] --- Epoch 3/20 ---
[09:26:30.172] 
[09:26:30.197] --- Epoch 4/20 ---
[09:26:34.176] 
[09:26:34.197] --- Epoch 5/20 ---
[09:26:38.192] Batch 10/40 - Loss: 0.1660 - Acc: 100.0%
[09:26:38.199] 
[09:26:38.205] --- Epoch 6/20 ---
[09:26:42.196] 
[09:26:42.214] --- Epoch 7/20 ---
[09:26:46.200] 
[09:26:46.226] --- Epoch 8/20 ---
[09:26:50.216] 
[09:26:50.236] --- Epoch 9/20 ---
[09:26:54.222] 
[09:26:54.250] --- Epoch 10/20 ---
[09:26:58.241] Batch 20/40 - Loss: 0.2171 - Acc: 100.0%
[09:26:58.267] 
[09:26:58.277] --- Epoch 11/20 ---
[09:27:02.246] 
[09:27:02.275] --- Epoch 12/20 ---
[09:27:06.247] 
[09:27:06.272] --- Epoch 13/20 ---
[09:27:10.261] 
[09:27:10.286] --- Epoch 14/20 ---
[09:27:14.264] 
[09:27:14.295] --- Epoch 15/20 ---
[09:27:18.281] Batch 30/40 - Loss: 0.1553 - Acc: 100.0%
[09:27:18.310] 
[09:27:18.323] --- Epoch 16/20 ---
[09:27:22.293] 
[09:27:22.322] --- Epoch 17/20 ---
[09:27:26.298] 
[09:27:26.328] --- Epoch 18/20 ---
[09:27:30.314] 
[09:27:30.331] --- Epoch 19/20 ---
[09:27:34.318] 
[09:27:34.347] --- Epoch 20/20 ---
[09:27:38.334] Batch 40/40 - Loss: 0.1218 - Acc: 100.0%
[09:27:38.362] 
[09:27:38.374] --- Training Complete ---
[09:27:39.833] Validation Accuracy: 83.3%  (5/6 correct)
[09:27:41.151] Weights saved to SD
[09:27:46.185] You can copy /header/myWeights.h to the sketch folder, then uncomment #define USE_BAKED_WEIGHTS
[09:27:46.343] Waiting for input...
[09:27:46.368] Serial: T=train again  L=exit
[09:27:46.382] Touch:  1-2 taps=train again  3+taps=exit
[09:27:48.003] 
[09:27:48.009] === MENU ===
[09:27:48.015] 1. 0Blank
[09:27:48.020] 2. 1Circle
[09:27:48.024] > 3. Train
[09:27:48.030] 4. Infer
[09:27:48.035] Commands: t=next (tap)  l=select (longpress)
[09:27:49.749] 
[09:27:49.757] >>> Inference mode - OPTIMIZED
[09:27:49.763] Instructions:
[09:27:49.768] T or L exit to menu
[09:27:49.856] Frame 1: 106 ms (9.4 FPS) Current Pred: 0Blank (85.0%) | All: 85% 15%
[09:27:50.023] Frame 2: 166 ms (6.0 FPS) Current Pred: 0Blank (74.4%) | All: 74% 26%
[09:27:50.182] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (74.1%) | All: 74% 26%
[09:27:50.343] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (75.0%) | All: 75% 25%
[09:27:50.503] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (84.5%) | All: 84% 16%
[09:27:50.663] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (96.5%) | All: 96% 4%
[09:27:50.823] Frame 7: 159 ms (6.3 FPS) Current Pred: 0Blank (85.8%) | All: 86% 14%
[09:27:50.984] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (83.8%) | All: 84% 16%
[09:27:51.142] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (75.8%) | All: 76% 24%
[09:27:51.321] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (54.6%) | All: 55% 45%
[09:27:51.495] Frame 1: 174 ms (5.7 FPS) Current Pred: 0Blank (63.2%) | All: 63% 37%
[09:27:51.657] Frame 2: 160 ms (6.2 FPS) Current Pred: 1Circle (61.0%) | All: 39% 61%
[09:27:51.847] Frame 3: 191 ms (5.2 FPS) Current Pred: 0Blank (53.0%) | All: 53% 47%
[09:27:52.040] Frame 4: 192 ms (5.2 FPS) Current Pred: 1Circle (58.4%) | All: 42% 58%
[09:27:52.199] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (82.1%) | All: 82% 18%
[09:27:52.360] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (87.0%) | All: 87% 13%
[09:27:52.520] Frame 7: 159 ms (6.3 FPS) Current Pred: 1Circle (55.2%) | All: 45% 55%
[09:27:52.679] Frame 8: 160 ms (6.2 FPS) Current Pred: 1Circle (86.0%) | All: 14% 86%
[09:27:52.841] Frame 9: 160 ms (6.2 FPS) Current Pred: 1Circle (89.8%) | All: 10% 90%
[09:27:53.018] Frame 10: 178 ms (5.6 FPS) Current Pred: 1Circle (90.2%) | All: 10% 90%
[09:27:53.159] Frame 1: 141 ms (7.1 FPS) Current Pred: 1Circle (60.7%) | All: 39% 61%
[09:27:53.320] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (90.8%) | All: 91% 9%
[09:27:53.480] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (53.2%) | All: 53% 47%
[09:27:53.639] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (69.0%) | All: 69% 31%
[09:27:53.800] Frame 5: 159 ms (6.3 FPS) Current Pred: 1Circle (66.5%) | All: 33% 67%
[09:27:53.961] Frame 6: 160 ms (6.2 FPS) Current Pred: 1Circle (73.4%) | All: 27% 73%
[09:27:54.119] Frame 7: 159 ms (6.3 FPS) Current Pred: 0Blank (50.4%) | All: 50% 50%
[09:27:54.280] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (59.0%) | All: 59% 41%
[09:27:54.440] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (85.4%) | All: 85% 15%
[09:27:54.618] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (75.9%) | All: 76% 24%
[09:27:54.760] Frame 1: 142 ms (7.0 FPS) Current Pred: 1Circle (60.7%) | All: 39% 61%
[09:27:54.972] cam_hal: FB-OVF
[09:27:55.002] cam_hal: FB-OVF
[09:27:55.082] Frame 2: 320 ms (3.1 FPS) Current Pred: 0Blank (59.3%) | All: 59% 41%
[09:27:55.241] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (58.5%) | All: 59% 41%
[09:27:55.401] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (50.2%) | All: 50% 50%
[09:27:55.623] Frame 5: 223 ms (4.5 FPS) Current Pred: 0Blank (54.9%) | All: 55% 45%
[09:27:55.784] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (81.9%) | All: 82% 18%
[09:27:55.944] Frame 7: 160 ms (6.2 FPS) Current Pred: 1Circle (51.0%) | All: 49% 51%
[09:27:56.104] Frame 8: 160 ms (6.2 FPS) Current Pred: 1Circle (62.6%) | All: 37% 63%
[09:27:56.266] Frame 9: 160 ms (6.2 FPS) Current Pred: 1Circle (71.3%) | All: 29% 71%
[09:27:56.443] Frame 10: 178 ms (5.6 FPS) Current Pred: 1Circle (68.7%) | All: 31% 69%
[09:27:56.586] Frame 1: 141 ms (7.1 FPS) Current Pred: 1Circle (62.6%) | All: 37% 63%
[09:27:56.745] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (56.2%) | All: 56% 44%
[09:27:56.905] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (65.6%) | All: 66% 34%
[09:27:57.065] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (88.1%) | All: 88% 12%
[09:27:57.224] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (84.5%) | All: 85% 15%
[09:27:57.384] Frame 6: 158 ms (6.3 FPS) Current Pred: 0Blank (94.3%) | All: 94% 6%
[09:27:57.544] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (73.8%) | All: 74% 26%
[09:27:57.706] Frame 8: 161 ms (6.2 FPS) Current Pred: 0Blank (86.7%) | All: 87% 13%
[09:27:57.864] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (86.1%) | All: 86% 14%
[09:27:58.044] Frame 10: 179 ms (5.6 FPS) Current Pred: 0Blank (87.3%) | All: 87% 13%
[09:27:58.183] Frame 1: 140 ms (7.1 FPS) Current Pred: 0Blank (88.0%) | All: 88% 12%
[09:27:58.190] 
[09:27:58.199] === MENU ===
[09:27:58.209] 1. 0Blank
[09:27:58.218] 2. 1Circle
[09:27:58.224] 3. Train
[09:27:58.230] > 4. Infer
[09:27:58.236] Commands: t=next (tap)  l=select (longpress)
[09:28:17.979] 
[09:28:17.987] >>> Training mode
[09:28:17.994] Instructions:
[09:28:17.999] During training: 3+ taps = Save and exit
[09:28:18.007] After completion: TAP = Train again, 3+ taps = Exit
[09:28:18.013] Serial: 'T'=train again, 'L'=exit
[09:28:18.036] Loading weights from SD...
[09:28:19.242] Weights loaded successfully
[09:28:19.265] Continuing from saved weights
[09:28:20.162] Val: 6 images  Train: 12 images
[09:28:20.177] Training: 12 images, 40 batches
[09:28:20.185] 
[09:28:20.193] --- Epoch 1/20 ---
[09:28:24.165] 
[09:28:24.188] --- Epoch 2/20 ---
[09:28:32.188] 
[09:28:32.203] --- Epoch 3/20 ---
[09:28:32.209] 
[09:28:32.216] --- Epoch 4/20 ---
[09:28:36.190] 
[09:28:36.201] --- Epoch 5/20 ---
[09:28:40.205] Batch 10/40 - Loss: 0.1067 - Acc: 100.0%
[09:28:40.224] 
[09:28:40.243] --- Epoch 6/20 ---
[09:28:44.207] 
[09:28:44.236] --- Epoch 7/20 ---
[09:28:48.210] 
[09:28:48.242] --- Epoch 8/20 ---
[09:28:52.226] 
[09:28:52.260] --- Epoch 9/20 ---
[09:28:56.229] 
[09:28:56.261] --- Epoch 10/20 ---
[09:29:00.245] Batch 20/40 - Loss: 0.1086 - Acc: 100.0%
[09:29:00.278] 
[09:29:00.290] --- Epoch 11/20 ---
[09:29:04.249] 
[09:29:04.290] --- Epoch 12/20 ---
[09:29:08.253] 
[09:29:08.289] --- Epoch 13/20 ---
[09:29:12.269] 
[09:29:12.297] --- Epoch 14/20 ---
[09:29:16.272] 
[09:29:16.303] --- Epoch 15/20 ---
[09:29:20.284] Batch 30/40 - Loss: 0.0942 - Acc: 100.0%
[09:29:20.317] 
[09:29:20.330] --- Epoch 16/20 ---
[09:29:28.292] 
[09:29:28.317] --- Epoch 17/20 ---
[09:29:28.335] 
[09:29:28.352] --- Epoch 18/20 ---
[09:29:32.311] 
[09:29:32.328] --- Epoch 19/20 ---
[09:29:36.316] 
[09:29:36.348] --- Epoch 20/20 ---
[09:29:40.331] Batch 40/40 - Loss: 0.0811 - Acc: 100.0%
[09:29:40.368] 
[09:29:40.378] --- Training Complete ---
[09:29:41.831] Validation Accuracy: 83.3%  (5/6 correct)
[09:29:43.155] Weights saved to SD
[09:29:48.190] You can copy /header/myWeights.h to the sketch folder, then uncomment #define USE_BAKED_WEIGHTS
[09:29:48.348] Waiting for input...
[09:29:48.382] Serial: T=train again  L=exit
[09:29:48.405] Touch:  1-2 taps=train again  3+taps=exit
[09:29:50.427] 
[09:29:50.435] === MENU ===
[09:29:50.441] 1. 0Blank
[09:29:50.448] 2. 1Circle
[09:29:50.455] > 3. Train
[09:29:50.463] 4. Infer
[09:29:50.473] Commands: t=next (tap)  l=select (longpress)
[09:29:51.836] 
[09:29:51.844] >>> Inference mode - OPTIMIZED
[09:29:51.851] Instructions:
[09:29:51.857] T or L exit to menu
[09:29:51.944] Frame 1: 108 ms (9.3 FPS) Current Pred: 0Blank (93.8%) | All: 94% 6%
[09:29:52.101] Frame 2: 157 ms (6.4 FPS) Current Pred: 0Blank (85.6%) | All: 86% 14%
[09:29:52.261] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (85.2%) | All: 85% 15%
[09:29:52.421] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (85.0%) | All: 85% 15%
[09:29:52.582] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (88.3%) | All: 88% 12%
[09:29:52.742] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (89.5%) | All: 90% 10%
[09:29:52.902] Frame 7: 158 ms (6.3 FPS) Current Pred: 0Blank (91.4%) | All: 91% 9%
[09:29:53.061] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (88.4%) | All: 88% 12%
[09:29:53.222] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (87.8%) | All: 88% 12%
[09:29:53.400] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (75.3%) | All: 75% 25%
[09:29:53.541] Frame 1: 142 ms (7.0 FPS) Current Pred: 1Circle (56.8%) | All: 43% 57%
[09:29:53.702] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (52.5%) | All: 53% 47%
[09:29:53.863] Frame 3: 161 ms (6.2 FPS) Current Pred: 0Blank (55.3%) | All: 55% 45%
[09:29:54.022] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (55.2%) | All: 55% 45%
[09:29:54.182] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (83.6%) | All: 84% 16%
[09:29:54.342] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (66.1%) | All: 66% 34%
[09:29:54.511] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (68.3%) | All: 68% 32%
[09:29:54.766] Frame 8: 256 ms (3.9 FPS) Current Pred: 1Circle (71.2%) | All: 29% 71%
[09:29:54.959] Frame 9: 192 ms (5.2 FPS) Current Pred: 0Blank (56.0%) | All: 56% 44%
[09:29:55.135] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (88.9%) | All: 89% 11%
[09:29:55.278] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (89.5%) | All: 89% 11%
[09:29:55.438] Frame 2: 160 ms (6.2 FPS) Current Pred: 1Circle (66.3%) | All: 34% 66%
[09:29:55.598] Frame 3: 160 ms (6.2 FPS) Current Pred: 1Circle (93.9%) | All: 6% 94%
[09:29:55.759] Frame 4: 160 ms (6.2 FPS) Current Pred: 1Circle (90.3%) | All: 10% 90%
[09:29:55.919] Frame 5: 158 ms (6.3 FPS) Current Pred: 1Circle (80.1%) | All: 20% 80%
[09:29:56.078] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (82.7%) | All: 83% 17%
[09:29:56.239] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (88.9%) | All: 89% 11%
[09:29:56.399] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (73.0%) | All: 73% 27%
[09:29:56.558] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (82.5%) | All: 83% 17%
[09:29:56.735] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (69.1%) | All: 69% 31%
[09:29:56.879] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (75.5%) | All: 75% 25%
[09:29:57.039] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (94.1%) | All: 94% 6%
[09:29:57.197] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (82.5%) | All: 82% 18%
[09:29:57.358] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (62.3%) | All: 62% 38%
[09:29:57.520] Frame 5: 161 ms (6.2 FPS) Current Pred: 0Blank (74.1%) | All: 74% 26%
[09:29:57.679] Frame 6: 158 ms (6.3 FPS) Current Pred: 0Blank (71.7%) | All: 72% 28%
[09:29:57.839] Frame 7: 159 ms (6.3 FPS) Current Pred: 0Blank (74.1%) | All: 74% 26%
[09:29:57.999] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (80.4%) | All: 80% 20%
[09:29:58.161] Frame 9: 161 ms (6.2 FPS) Current Pred: 0Blank (87.4%) | All: 87% 13%
[09:29:58.337] Frame 10: 176 ms (5.7 FPS) Current Pred: 0Blank (67.3%) | All: 67% 33%
[09:29:58.479] Frame 1: 141 ms (7.1 FPS) Current Pred: 0Blank (66.4%) | All: 66% 34%
[09:29:58.640] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (57.0%) | All: 57% 43%
[09:29:58.799] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (56.7%) | All: 57% 43%
[09:29:58.959] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (57.8%) | All: 58% 42%
[09:29:59.120] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (58.1%) | All: 58% 42%
[09:29:59.279] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (88.3%) | All: 88% 12%
[09:29:59.438] Frame 7: 159 ms (6.3 FPS) Current Pred: 0Blank (91.2%) | All: 91% 9%
[09:29:59.599] Frame 8: 161 ms (6.2 FPS) Current Pred: 0Blank (73.3%) | All: 73% 27%
[09:29:59.758] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (67.2%) | All: 67% 33%
[09:29:59.938] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (91.9%) | All: 92% 8%
[09:30:00.079] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (85.4%) | All: 85% 15%
[09:30:00.240] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (79.4%) | All: 79% 21%
[09:30:00.401] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (74.3%) | All: 74% 26%
[09:30:00.561] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (70.1%) | All: 70% 30%
[09:30:00.719] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (68.4%) | All: 68% 32%
[09:30:00.879] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (68.3%) | All: 68% 32%
[09:30:01.041] Frame 7: 161 ms (6.2 FPS) Current Pred: 0Blank (68.7%) | All: 69% 31%
[09:30:01.199] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (69.8%) | All: 70% 30%
[09:30:01.224] 
[09:30:01.235] === MENU ===
[09:30:01.248] 1. 0Blank
[09:30:01.256] 2. 1Circle
[09:30:01.265] 3. Train
[09:30:01.272] > 4. Infer
[09:30:01.281] Commands: t=next (tap)  l=select (longpress)
[09:30:30.581] 
[09:30:30.589] >>> Inference mode - OPTIMIZED
[09:30:30.597] Instructions:
[09:30:30.603] T or L exit to menu
[09:30:30.691] Frame 1: 108 ms (9.3 FPS) Current Pred: 0Blank (69.3%) | All: 69% 31%
[09:30:30.838] Frame 2: 149 ms (6.7 FPS) Current Pred: 0Blank (92.7%) | All: 93% 7%
[09:30:30.999] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (92.0%) | All: 92% 8%
[09:30:31.161] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (92.0%) | All: 92% 8%
[09:30:31.319] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (92.5%) | All: 92% 8%
[09:30:31.479] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (96.0%) | All: 96% 4%
[09:30:31.639] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (84.7%) | All: 85% 15%
[09:30:31.799] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (77.3%) | All: 77% 23%
[09:30:31.960] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (70.1%) | All: 70% 30%
[09:30:32.137] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (64.6%) | All: 65% 35%
[09:30:32.281] Frame 1: 143 ms (7.0 FPS) Current Pred: 1Circle (58.0%) | All: 42% 58%
[09:30:32.440] Frame 2: 159 ms (6.3 FPS) Current Pred: 1Circle (50.8%) | All: 49% 51%
[09:30:32.600] Frame 3: 160 ms (6.2 FPS) Current Pred: 1Circle (51.9%) | All: 48% 52%
[09:30:32.761] Frame 4: 160 ms (6.2 FPS) Current Pred: 1Circle (54.6%) | All: 45% 55%
[09:30:33.079] Frame 5: 160 ms (6.2 FPS) Current Pred: 1Circle (54.5%) | All: 46% 54%
[09:30:33.118] Frame 6: 159 ms (6.3 FPS) Current Pred: 1Circle (62.2%) | All: 38% 62%
[09:30:33.240] Frame 7: 159 ms (6.3 FPS) Current Pred: 1Circle (62.7%) | All: 37% 63%
[09:30:33.401] Frame 8: 160 ms (6.2 FPS) Current Pred: 1Circle (60.5%) | All: 40% 60%
[09:30:33.559] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (72.4%) | All: 72% 28%
[09:30:33.738] Frame 10: 179 ms (5.6 FPS) Current Pred: 0Blank (85.3%) | All: 85% 15%
[09:30:33.879] Frame 1: 141 ms (7.1 FPS) Current Pred: 0Blank (89.7%) | All: 90% 10%
[09:30:34.041] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (79.5%) | All: 80% 20%
[09:30:34.201] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (73.4%) | All: 73% 27%
[09:30:34.359] Frame 4: 159 ms (6.3 FPS) Current Pred: 1Circle (71.2%) | All: 29% 71%
[09:30:34.520] Frame 5: 160 ms (6.2 FPS) Current Pred: 1Circle (74.0%) | All: 26% 74%
[09:30:34.680] Frame 6: 160 ms (6.2 FPS) Current Pred: 1Circle (67.7%) | All: 32% 68%
[09:30:34.840] Frame 7: 160 ms (6.2 FPS) Current Pred: 1Circle (57.6%) | All: 42% 58%
[09:30:35.001] Frame 8: 160 ms (6.2 FPS) Current Pred: 1Circle (64.1%) | All: 36% 64%
[09:30:35.161] Frame 9: 161 ms (6.2 FPS) Current Pred: 0Blank (50.6%) | All: 51% 49%
[09:30:35.337] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (62.5%) | All: 63% 37%
[09:30:35.480] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (67.6%) | All: 68% 32%
[09:30:35.641] Frame 2: 160 ms (6.2 FPS) Current Pred: 1Circle (57.2%) | All: 43% 57%
[09:30:35.800] Frame 3: 160 ms (6.2 FPS) Current Pred: 1Circle (64.0%) | All: 36% 64%
[09:30:35.960] Frame 4: 160 ms (6.2 FPS) Current Pred: 1Circle (64.0%) | All: 36% 64%
[09:30:36.121] Frame 5: 161 ms (6.2 FPS) Current Pred: 0Blank (84.9%) | All: 85% 15%
[09:30:36.282] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (82.4%) | All: 82% 18%
[09:30:36.440] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (82.2%) | All: 82% 18%
[09:30:36.601] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (75.4%) | All: 75% 25%
[09:30:36.761] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (79.1%) | All: 79% 21%
[09:30:36.938] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (85.5%) | All: 86% 14%
[09:30:37.081] Frame 1: 141 ms (7.1 FPS) Current Pred: 0Blank (82.9%) | All: 83% 17%
[09:30:37.240] Frame 2: 159 ms (6.3 FPS) Current Pred: 0Blank (82.5%) | All: 82% 18%
[09:30:37.402] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (82.4%) | All: 82% 18%
[09:30:37.561] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (76.1%) | All: 76% 24%
[09:30:37.721] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (75.4%) | All: 75% 25%
[09:30:37.880] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (76.8%) | All: 77% 23%
[09:30:38.042] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (83.9%) | All: 84% 16%
[09:30:38.201] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (76.7%) | All: 77% 23%
[09:30:38.361] Frame 9: 159 ms (6.3 FPS) Current Pred: 0Blank (65.7%) | All: 66% 34%
[09:30:38.539] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (74.4%) | All: 74% 26%
[09:30:38.681] Frame 1: 141 ms (7.1 FPS) Current Pred: 0Blank (80.2%) | All: 80% 20%
[09:30:38.842] Frame 2: 161 ms (6.2 FPS) Current Pred: 0Blank (79.5%) | All: 79% 21%
[09:30:39.002] Frame 3: 159 ms (6.3 FPS) Current Pred: 0Blank (82.1%) | All: 82% 18%
[09:30:39.162] Frame 4: 161 ms (6.2 FPS) Current Pred: 0Blank (77.4%) | All: 77% 23%
[09:30:39.321] Frame 5: 159 ms (6.3 FPS) Current Pred: 0Blank (80.7%) | All: 81% 19%
[09:30:39.482] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (80.7%) | All: 81% 19%
[09:30:39.644] Frame 7: 161 ms (6.2 FPS) Current Pred: 0Blank (75.5%) | All: 76% 24%
[09:30:39.801] Frame 8: 159 ms (6.3 FPS) Current Pred: 0Blank (87.2%) | All: 87% 13%
[09:30:39.962] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (77.3%) | All: 77% 23%
[09:30:40.138] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (70.2%) | All: 70% 30%
[09:30:40.281] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (77.9%) | All: 78% 22%
[09:30:40.441] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (80.1%) | All: 80% 20%
[09:30:40.601] Frame 3: 160 ms (6.2 FPS) Current Pred: 0Blank (78.2%) | All: 78% 22%
[09:30:40.762] Frame 4: 160 ms (6.2 FPS) Current Pred: 0Blank (77.5%) | All: 77% 23%
[09:30:40.922] Frame 5: 160 ms (6.2 FPS) Current Pred: 0Blank (77.3%) | All: 77% 23%
[09:30:41.081] Frame 6: 160 ms (6.2 FPS) Current Pred: 0Blank (78.8%) | All: 79% 21%
[09:30:41.240] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (89.9%) | All: 90% 10%
[09:30:41.402] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (82.7%) | All: 83% 17%
[09:30:41.562] Frame 9: 161 ms (6.2 FPS) Current Pred: 0Blank (78.1%) | All: 78% 22%
[09:30:41.740] Frame 10: 177 ms (5.6 FPS) Current Pred: 0Blank (85.0%) | All: 85% 15%
[09:30:41.882] Frame 1: 142 ms (7.0 FPS) Current Pred: 0Blank (82.6%) | All: 83% 17%
[09:30:42.043] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (82.2%) | All: 82% 18%
[09:30:42.203] Frame 3: 161 ms (6.2 FPS) Current Pred: 0Blank (81.1%) | All: 81% 19%
[09:30:42.361] Frame 4: 159 ms (6.3 FPS) Current Pred: 0Blank (80.8%) | All: 81% 19%
[09:30:42.523] Frame 5: 161 ms (6.2 FPS) Current Pred: 0Blank (80.7%) | All: 81% 19%
[09:30:42.682] Frame 6: 159 ms (6.3 FPS) Current Pred: 0Blank (81.2%) | All: 81% 19%
[09:30:42.842] Frame 7: 160 ms (6.2 FPS) Current Pred: 0Blank (80.9%) | All: 81% 19%
[09:30:43.002] Frame 8: 160 ms (6.2 FPS) Current Pred: 0Blank (81.7%) | All: 82% 18%
[09:30:43.162] Frame 9: 160 ms (6.2 FPS) Current Pred: 0Blank (81.9%) | All: 82% 18%
[09:30:43.340] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (84.9%) | All: 85% 15%
[09:30:43.481] Frame 1: 141 ms (7.1 FPS) Current Pred: 0Blank (94.1%) | All: 94% 6%
[09:30:43.643] Frame 2: 160 ms (6.2 FPS) Current Pred: 1Circle (50.8%) | All: 49% 51%
[09:30:43.803] Frame 3: 160 ms (6.2 FPS) Current Pred: 1Circle (83.2%) | All: 17% 83%
[09:30:43.962] Frame 4: 159 ms (6.3 FPS) Current Pred: 1Circle (76.1%) | All: 24% 76%
[09:30:44.122] Frame 5: 159 ms (6.3 FPS) Current Pred: 1Circle (63.6%) | All: 36% 64%
[09:30:44.283] Frame 6: 160 ms (6.2 FPS) Current Pred: 1Circle (72.3%) | All: 28% 72%
[09:30:44.443] Frame 7: 160 ms (6.2 FPS) Current Pred: 1Circle (70.8%) | All: 29% 71%
[09:30:44.603] Frame 8: 160 ms (6.2 FPS) Current Pred: 1Circle (72.1%) | All: 28% 72%
[09:30:44.762] Frame 9: 159 ms (6.3 FPS) Current Pred: 1Circle (68.6%) | All: 31% 69%
[09:30:44.940] Frame 10: 178 ms (5.6 FPS) Current Pred: 0Blank (90.6%) | All: 91% 9%
[09:30:45.083] Frame 1: 141 ms (7.1 FPS) Current Pred: 0Blank (87.1%) | All: 87% 13%
[09:30:45.244] Frame 2: 159 ms (6.3 FPS) Current Pred: 1Circle (61.6%) | All: 38% 62%
[09:30:45.402] Frame 3: 160 ms (6.2 FPS) Current Pred: 1Circle (98.4%) | All: 2% 98%
[09:30:45.562] Frame 4: 159 ms (6.3 FPS) Current Pred: 1Circle (98.8%) | All: 1% 99%
[09:30:45.724] Frame 5: 160 ms (6.2 FPS) Current Pred: 1Circle (98.8%) | All: 1% 99%
[09:30:45.883] Frame 6: 159 ms (6.3 FPS) Current Pred: 1Circle (97.1%) | All: 3% 97%
[09:30:46.043] Frame 7: 160 ms (6.2 FPS) Current Pred: 1Circle (87.5%) | All: 13% 87%
[09:30:46.203] Frame 8: 160 ms (6.2 FPS) Current Pred: 1Circle (81.2%) | All: 19% 81%
[09:30:46.361] Frame 9: 160 ms (6.2 FPS) Current Pred: 1Circle (70.2%) | All: 30% 70%
[09:30:46.540] Frame 10: 176 ms (5.7 FPS) Current Pred: 1Circle (68.1%) | All: 32% 68%
[09:30:46.683] Frame 1: 143 ms (7.0 FPS) Current Pred: 1Circle (51.9%) | All: 48% 52%
[09:30:46.843] Frame 2: 160 ms (6.2 FPS) Current Pred: 0Blank (50.3%) | All: 50% 50%
[09:30:46.873] 
[09:30:46.884] === MENU ===
[09:30:46.894] 1. 0Blank
[09:30:46.903] 2. 1Circle
[09:30:46.913] 3. Train
[09:30:46.922] > 4. Infer
[09:30:46.933] Commands: t=next (tap)  l=select (longpress)


```
