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



```

