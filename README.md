[![Build Status](https://travis-ci.com/ochrin/coremark.svg?branch=master)](https://travis-ci.com/ochrin/coremark)

# CoreMark
Starts a FreeRTOS task to run CoreMark benchmark.

See [EEMBC](https://github.com/eembc/coremark) for more details.

## Current results
Between parenthesis result with -O0 for comparaison, otherwise -O3 is used to compile Coremark.

| Processor       | Freq (MHz) | CoreMark     | CoreMark/MHz |
| :-------------- | :--------- | :----------- | ------------ |
| ESP8266         | 80         | 191          | 2.375        |
| ESP32 (2 cores) | 160        | 665.9        | **4.16**     |
|                 | 240        | **999.2**    | **4.16**     |
| ESP32 (1 core)  | 80         | 165.9        | 2.07         |
|                 | 160        | 330.9 (78.1) | 2.07 (0.49)  |
|                 | 240        | 494.6        | 2.06         |
| ESP32 S2        | 80         | 157,5        | 1.97         |
|                 | 160        | 315.2        | 1.97         |
|                 | 240        | 472.8        | 1.97         |
| ...             | ...        | ...          | ...          |

(larger numbers are better)

## How to install
See [Espressif](https://docs.espressif.com/projects/esp-idf/en/v4.0/get-started/index.html#installation-step-by-step) for latest procedure

### Prerequisite (on Ubuntu 18.04)
```
sudo apt-get install git wget flex bison gperf python python-pip python-setuptools cmake ninja-build ccache libffi-dev libssl-dev dfu-util
```
You may have to delete ~/.espressif if you have an old installation

Remove python2.x if you can and type:

```
sudo update-alternatives --set python /usr/bin/python3
```

### Get SDK/IDF (latest)
```
cd
mkdir git
git clone --recursive https://github.com/espressif/esp-idf.git
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
idf.py set-target esp32s2
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

You have to wait about 20 to 30s to get the results.

## Result you should get with default settings (numbers may change)
```
2K performance run parameters for coremark.
CoreMark Size    : 666
Total ticks      : 16920
Total time (secs): 16.920000
Iterations/Sec   : 472.813239
Iterations       : 8000
Compiler version : GCC8.4.0
Compiler flags   : -O3
Memory location  : DRAM
seedcrc          : 0xe9f5
[0]crclist       : 0xe714
[0]crcmatrix     : 0x1fd7
[0]crcstate      : 0x8e3a
[0]crcfinal      : 0x5275
Correct operation validated. See README.md for run and reporting rules.
CoreMark 1.0 : 472.813239 / GCC8.4.0 -O3 / DRAM
```
