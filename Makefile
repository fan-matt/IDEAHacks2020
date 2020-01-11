# Arduino-Makefile Vars
ARDUINO_DIR=/usr/share/arduino
ARDMK_DIR=./Arduino-Makefile
AVR_TOOLS_DIR=/usr
AVRDUDE=/usr/bin/avrdude
AVRDUDE_CONF=/etc/avrdude.conf
ARDUINO_LIBS=
BOARD_TAG=nano328
MONITOR_PORT=/dev/				# TODO: Always set this before upload
LOCAL_CPP_SRCS=$(PWD)/src/ATime.cpp $(PWD)/saitama.cpp

include ./Arduino-Makefile/Arduino.mk