## Three small datasets to support proof of concept for a fully on device machine learning pipeline


### Dataset A barebones, hand drawn circles for a two class test. About 9 images per class 

```
#define NUM_CLASSES 2
String myClassLabels[NUM_CLASSES] = {"0Blank", "1Circle"};
```


### Dataset B Testing, The main dataset used in the paper. About 39 images per class

Note: The header file has a trained myWeights.bin and myWeights.h files to train from or you can delete those and start from scratch.

```
#define NUM_CLASSES 3
String myClassLabels[NUM_CLASSES] = {"0Blank", "1Cup", "2Pen"};
```

### Dataset C larger, an extended dataset for testing more classes. Expect much longer training times and cross class interactions. Over 60 images per class

Note: You do not have to use all 6 classses but can pick and choose in the JSON or Arduino code 

```
#define NUM_CLASSES 6
String myClassLabels[NUM_CLASSES] = {"0Blank", "1Cup", "2Pen", "3Unknown", "4Mouse", "5Star"};
```
