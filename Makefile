# Arduino-Makefile Vars
ARDUINO_DIR=/usr/share/arduino
ARDMK_DIR=./Arduino-Makefile
AVR_TOOLS_DIR=/usr
ARDUINO_LIBS=
BOARD_TAG=nano328
MONITOR_PORT=/dev/
LOCAL_CPP_SRCS=$(PWD)/src/ATime.cpp $(PWD)/saitama.cpp

include ./Arduino-Makefile/Arduino.mk