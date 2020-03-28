[![Build Status](https://travis-ci.com/ochrin/coremark.svg?branch=master)](https://travis-ci.com/ochrin/coremark)

# CoreMark
Starts a FreeRTOS task to run CoreMark benchmark.

See [EEMBC](https://github.com/eembc/coremark) for more details.

## Current results

| Processor     | Freq (MHz)   | CoreMark      | CoreMark/MHz  |
| ------------- | :----------: | :-----------: | ------------: |
| ESP8266       | 80           | 191           | 2.375         |
| ESP32         | 80           | 166           | 2.075         |
|               | 160          | 331           | 2.075         |
|               | 240          | 498           | 2.075         |
| ...           | ...          | ...           |   ...         |

(larger numbers are better)

## How to install
See [Espressif](https://docs.espressif.com/projects/esp-idf/en/v4.0/get-started/index.html#installation-step-by-step) for latest procedure

### Prerequisite (on Ubuntu)
```
sudo apt install git wget libncurses-dev flex bison gperf python python-pip python-setuptools python-serial python-click python-cryptography python-future python-pyparsing python-pyelftools cmake ninja-build ccache libffi-dev libssl-dev
```

### Get SDK
```
cd
mkdir git
git clone --recursive --branch release/v4.1 https://github.com/espressif/esp-idf.git
cd esp-idf
./install.sh
. ./export.sh
cd ..
```

### Get Coremark
```
cd 
cd git
git clone --branch esp32 https://github.com/ochrin/coremark.git 
```

## How to build
```
idf.py build
```
## How to configure CoreMark (optional)
```
idf.py menuconfig
```
You may adjust CoreMark settings in _CoreMark configuration_ else simply exit.  
You will need to build afterward.

## How to run
```
idf.py -p /dev/ttyUSB0 flash; screen /dev/ttyUSB0 115200
```
Ctrl-a + k then y to exit screen

## Result you should get with default settings
```
2K performance run parameters for coremark.
CoreMark Size    : 666
Total ticks      : 15070
Total time (secs): 15.070000
Iterations/Sec   : 331.785003
Iterations       : 5000
Compiler version : GCC8.2.0
Compiler flags   : -O3
Memory location  : STACK
seedcrc          : 0xe9f5
[0]crclist       : 0xe714
[0]crcmatrix     : 0x1fd7
[0]crcstate      : 0x8e3a
[0]crcfinal      : 0xbd59
Correct operation validated. See README.md for run and reporting rules.
CoreMark 1.0 : 331.785003 / GCC8.2.0 -O3 / STACK
```
