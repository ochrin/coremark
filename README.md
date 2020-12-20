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
See [Espressif](https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html#setup-toolchain) for latest procedure

### Prerequisite (on Ubuntu)
```
sudo apt install gcc git wget make libncurses-dev flex bison gperf python python-serial screen
```

### Get compiler
```
cd 
wget https://dl.espressif.com/dl/xtensa-lx106-elf-linux64-1.22.0-100-ge567ec7-5.2.0.tar.gz
tar xvzf xtensa-lx106-elf-linux64-1.22.0-100-ge567ec7-5.2.0.tar.gz
```

### Get SDK
```
cd
mkdir git
git clone --recursive --branch release/v3.3 https://github.com/espressif/ESP8266_RTOS_SDK.git
cd ESP8266_RTOS_SDK 
python -m pip install --user -r ./requirements.txt
cd ..
```

### Get Coremark
```
cd 
cd git
git clone https://github.com/ochrin/coremark.git 
```

## How to build
```
export IDF_PATH=~/git/ESP8266_RTOS_SDK
export PATH=~/xtensa-lx106-elf/bin:$PATH
make all
```
## How to configure CoreMark (optional)
```
make menuconfig
```
You may adjust CoreMark settings in _CoreMark configuration_ else simply exit.  
Number of iterations should not be too long to avoid watchdog error.  
You will need to build afterward.

## How to run
```
make flash; screen /dev/ttyUSB0 115200
```
Ctrl-a + k then y to exit screen

## Result you should get with default settings
```
2K performance run parameters for coremark.
CoreMark Size    : 666
Total ticks      : 1309
Total time (secs): 13.090000
Iterations/Sec   : 190.985485
Iterations       : 2500
Compiler version : GCC5.2.0
Compiler flags   : -O3
Memory location  : STACK
seedcrc          : 0xe9f5
[0]crclist       : 0xe714
[0]crcmatrix     : 0x1fd7
[0]crcstate      : 0x8e3a
[0]crcfinal      : 0x5275
Correct operation validated. See README.md for run and reporting rules.
CoreMark 1.0 : 190.985485 / GCC5.2.0 -O3 / STACK
```
