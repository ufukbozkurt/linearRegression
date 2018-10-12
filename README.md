## Linear Regression

Multiple Linear Regression, written in C++. It includes very simple example data under "data" folder. 
Every row in "data/train.txt" is an input vector and the last column of the input vectors are desired outputs. 
"data/test.txt" is similar but desired output column is omitted.

```bash
make&&./lreg&&make clean-all

---------- TRAINING ----------
Alpha: 0.5
Iteration Count: 100
Adaptive Alpha: Yes
Feature Scaling: Yes
Cost: 2.44783e-11
Weights: [ 2.49999 2.49999 5.5 ]

---------- TEST ----------
Prediction from: [ 7 8 ]
Result: 8.99999

Prediction from: [ 8 9 ]
Result: 9.99998

Prediction from: [ 9 10 ]
Result: 11

Prediction from: [ 10 11 ]
Result: 12

```
