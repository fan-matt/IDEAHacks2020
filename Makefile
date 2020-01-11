# Arduino-Makefile Vars
ARDUINO_DIR=/usr/share/arduino
ARDMK_DIR=./Arduino-Makefile
AVR_TOOLS_DIR=/usr
AVRDUDE=/usr/bin/avrdude
AVRDUDE_CONF=/etc/avrdude.conf
ARDUINO_LIB_PATH=/usr/share/arduino/libraries
USER_LIB_PATH=$(PWD)
ARDUINO_LIBS=
BOARD_TAG=nano328
MONITOR_PORT=/dev/				# TODO: Always set this before upload
LOCAL_CPP_SRCS=$(PWD)/Keypad/src/Key.cpp $(PWD)/Keypad/src/Keypad.cpp $(PWD)/src/ATime.cpp $(PWD)/src/Accel.cpp $(PWD)/src/UserInput.cpp $(PWD)/saitama.cpp

include ./Arduino-Makefile/Arduino.mk