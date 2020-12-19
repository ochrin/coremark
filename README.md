[![Build Status](https://travis-ci.com/ochrin/coremark.svg?branch=master)](https://travis-ci.com/ochrin/coremark)

# CoreMark
Starts a FreeRTOS task to run CoreMark benchmark.

See [EEMBC](https://github.com/eembc/coremark) for more details.

## Current results
In parenthesis result with -O0 for comparaison, otherwise -O3 is used to compile Coremark.

| Processor       | Freq (MHz) | CoreMark     | CoreMark/MHz |
| :-------------- | :--------- | :----------- | ------------ |
| ESP8266         | 80         | 191          | 2.375        |
| ESP32 (2 cores) | 160        | 664.6        | 4.15         |
|                 | 240        | **997.0**    | 4.15         |
| ESP32 (1 core)  | 80         | 165.7        | 2.07         |
|                 | 160        | 331.7 (78.1) | 2.07 (0.49)  |
|                 | 240        | 497.8        | 2.07         |
| ...             | ...        | ...          | ...          |

(larger numbers are better)

## How to install
See [Espressif](https://docs.espressif.com/projects/esp-idf/en/v4.0/get-started/index.html#installation-step-by-step) for latest procedure

### Prerequisite (on Ubuntu)
```
sudo apt-get install git wget flex bison gperf python python-pip python-setuptools cmake ninja-build ccache libffi-dev libssl-dev dfu-util
```
You may have to delete ~/.espressif if you have an old installation

Python3 should be used when calling python. You may have problem if you are still using python2.x.

```
sudo update-alternatives --install /usr/bin/python python /usr/bin/python3 10
```

### Get SDK
```
cd
mkdir git
git clone --recursive --branch release/v4.2 https://github.com/espressif/esp-idf.git
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

You have to wait about 20 to 30s to get the results.

## Result you should get with default settings (numbers may change)
```
2K performance run parameters for coremark.
CoreMark Size    : 666
Total ticks      : 30270
Total time (secs): 30.270000
Iterations/Sec   : 660.720185
Iterations       : 20000
Compiler version : GCC8.2.0
Compiler flags   : -O3
Parallel FreeRTOS : 2
Memory location  : DRAM
seedcrc          : 0xe9f5
[0]crclist       : 0xe714
[1]crclist       : 0xe714
[0]crcmatrix     : 0x1fd7
[1]crcmatrix     : 0x1fd7
[0]crcstate      : 0x8e3a
[1]crcstate      : 0x8e3a
[0]crcfinal      : 0x988c
[1]crcfinal      : 0x988c
Correct operation validated. See README.md for run and reporting rules.
CoreMark 1.0 : 660.720185 / GCC8.2.0 -O3 / DRAM / 2:FreeRTOS
```
