# qt

## for qt-app we will start with a simple calculator

### Step 1.0 Create a QMake Makefile

Create a .pro file for QMake `touch calculator.pro`
```
TEMPLATE = app
TARGET = calculator
CONFIG += c++11
SOURCES += main.cpp
```

Then run the following line to setup the Makefile
`qmake -o Makefile calculator.pro`

Then `make` the application and execute it via the following line:
`./SimpleCalculator`
