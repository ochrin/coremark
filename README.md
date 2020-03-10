# CoreMark
Starts a FreeRTOS task to run CoreMark benchmark.

See [EEMBC](https://github.com/eembc/coremark) for more details.

## Current results

| Processor     | CoreMark      | CoreMark/MHz  |
| ------------- | :-----------: | ------------: |
| ESP8266       | 191           | 2.375         |
| ESP32         | TBD           |   TBD         |
| ...           | ...           |   ...         |

(larger numbers are better)

## How to install
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
git clone --recursive https://github.com/espressif/ESP8266_RTOS_SDK.git
cd ESP8266_RTOS_SDK
git checkout release/v3.3 
python -m pip install --user -r ./requirements.txt
cd ..
```

### Get Coremark
```
cd 
cd git
git clone https://github.com/Ochrin/coremark.git
git branch 
```

## How to compile
```
export IDF_PATH=~/git/ESP8266_RTOS_SDK
export PATH=~/xtensa-lx106-elf/bin:$PATH
make menuconfig
```
You may adjust CoreMark settings in _CoreMark configuration_ else simply exit.

```
make all
```

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
