# LFEV Pack Mangement System
# Copyright © 2015 John Gehrig
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.



#################################################
#                                               #
#           MAKEFILE SETTINGS                   #
#                                               #
#################################################

# AVR Device Settings
AVR_AVRD=c128
AVR_GCC=at90can128

# AVRDude Settings
AVRDUDE=avrdude
PRGMR=atmelice

# Compiler Settings
CC=avr-gcc
SIZE=avr-size
CFLAGS=-g -Os -mmcu=$(AVR_GCC) -Wall -Werror -std=c99
OBJCOPY=avr-objcopy
SIZE=avr-size

# RTOS Kernel Source Directory
KERNEL_DIR=./kernel

# Project Source Directory
SRC_DIR=src

# Library Source Directory
LIB_DIR=lib

# Build Directory Path
BUILD_DIR=build

# Application Object Files
APP_OBJECTS = main.o i2c.o lcd.o task_button.o task_i2c.o task_can.o task_gui.o task_watchdog.o task_charge.o task_safety.o task_config.o task_heartbeat.o tasklist.o

# RTOS Object Files
KERNEL_ASM_OBJECTS = atomport-asm.o
KERNEL_OBJECTS = atomkernel.o atomsem.o atommutex.o atomtimer.o atomqueue.o atomport.o

# Library Object Files
LIBRARY_OBJECTS = atmel/TWI_Master.o atmel/can_lib.o atmel/can_drv.o#i2c_lcd/i2c_lcd.o

# Collection of Built Objects
ALL_OBJECTS = $(APP_OBJECTS) $(KERNEL_ASM_OBJECTS) $(KERNEL_OBJECTS) $(LIBRARY_OBJECTS)
BUILT_OBJECTS = $(patsubst %,$(BUILD_DIR)/%,$(ALL_OBJECTS))

# Program Target Name
TARGET_NAME=pacman

# Hex/Elf File Extensions
TARGET_HEX=$(TARGET_NAME).hex
TARGET_ELF=$(TARGET_NAME).elf




#################################################
#                                               #
#           PROJECT MAKEFILE RULES              #
#                                               #
#################################################

all: $(BUILD_DIR) $(TARGET_HEX) size

# Make build/output directory
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

# Test HEX files (one application build for each test)
$(TARGET_HEX): %.hex: %.elf
	@echo Building $@
	$(OBJCOPY) -j .text -j .data -O ihex $(BUILD_DIR)/$< $(BUILD_DIR)/$@

# Test ELF files (one application build for each test)
$(TARGET_ELF): %.elf: $(ALL_OBJECTS)
	#$(CC) $(CFLAGS) $(BUILD_DIR)/$(notdir $<) $(BUILT_OBJECTS) -o $(BUILD_DIR)/$@ -Wl,-Map,$(BUILD_DIR)/$(basename $@).map
	echo $(BUILT_OBJECTS)
	$(CC) $(CFLAGS) $(BUILT_OBJECTS) -o $(BUILD_DIR)/$@ -Wl,-Map,$(BUILD_DIR)/$(basename $@).map

# Kernel objects builder
$(KERNEL_OBJECTS): %.o: $(KERNEL_DIR)/%.c
	$(CC) -c $(CFLAGS) -I. -I$(SRC_DIR) $< -o $(BUILD_DIR)/$(notdir $@)

# Application C objects builder
$(APP_OBJECTS): %.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -I$(SRC_DIR) -I$(KERNEL_DIR) -I$(LIB_DIR) $< -o $(BUILD_DIR)/$(notdir $@)

# Application asm objects builder
$(KERNEL_ASM_OBJECTS): %.o: $(KERNEL_DIR)/%.s
	$(CC) -c $(CFLAGS) -x assembler-with-cpp -I$(SRC_DIR) -I$(KERNEL_DIR) $< -o $(BUILD_DIR)/$(notdir $@)
	
# Library objects builder
$(LIBRARY_OBJECTS): %.o: $(LIB_DIR)/%.c
	$(CC) -c $(CFLAGS) -I. -I$(SRC_DIR) -I$(KERNEL_DIR) -I$(LIB_DIR) $< -o $(BUILD_DIR)/atmel/$(notdir $@)

size: $(TARGET_HEX)
	$(SIZE) -C --mcu=${AVR_GCC} $(BUILD_DIR)/${TARGET_ELF}
# Upload hex file
program : $(BUILD_DIR)/$(TARGET_HEX)
	$(SIZE) -A $(BUILD_DIR)/$(TARGET_HEX)
	$(AVRDUDE) -F -V -c $(PRGMR) -p $(AVR_AVRD) -U flash:w:$(BUILD_DIR)/$(TARGET_HEX)

#doxygen:
#sudo apt-get install gcc-avr binutils-avr gdb-avr avr-libc avrdude
#	doxygen $(KERNEL_DIR)/Doxyfile
#	doxygen ./Doxyfile

# Build a
ctags:
	ctags -R $(SRC_DIR) $(KERNEL_DIR)

fuse:
	#see http://www.engbedded.com/fusecalc/ for details on what these settings do
	$(AVRDUDE) -F -V -c $(PRGMR) -p $(AVR_AVRD) -U lfuse:w:0xcf:m -U hfuse:w:0x99:m -U efuse:w:0xff:m

# Clean
clean:
	rm -rf doxygen-kernel
	rm -rf doxygen-avr
	rm -rf build

.PHONY: clean fuse
