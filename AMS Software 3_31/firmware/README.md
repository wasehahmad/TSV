# AMS Firmware
Lafayette Formula Electric Vehicle Accumulator Mangement System Software

## Overview
This repository contains the PICLF1827 firmware. 

## Software Requirements
**OPTION A (Recommended)**
- Oracle VirtualBox

**OPTION B**
- MPLABX IDE 2.x or earlier
- MicroChip XC8 Compiler

### OPTION B: Oracle VirtualBox
The recommended way of building the system image is to use the pre-built VirtualBox environment. You will need to download VirtualBox, which can be found [here](https://www.virtualbox.org/wiki/Downloads).  

Go to the downloads page of the AMS repository, and download the latest virtual machine image. This image contains LXLE Ubuntu, and the MPLABX IDE and XC8 Compiler already installed. Simply mount the project folder on your host machine, and enable USB passthrough of the PICkit3 device.

### OPTION B: MicroChip MPLABX
This project was created using MicroChip proprietary IDE MPLABX. You can download a version of this IDE from [here](www.microchip.com/mplabx). However it should be noted that issues the PICkit3 and version 3.0 of the IDE may prevent programming of the PIC. A downgrade to version 2.x was required to successfully upload the software image.  
  
You will also need the MicroChip XC8 Compiler, which can be downloaded [here](www.microchip.com/compilers).

### Potential Problems
1. The PICkit3 has trouble with the MPLABX 3.x IDE, it complains that the firmware on the device is too old. Attempting to update the firmware either in the latest IDE, or an older one does not appear to have any effect.
2. If you are using the Virtual Machine Method, you must enable a USB Filter. Simply selecting Devices->USB Devices->PICkit3 is not enough. The PICkit3 re-uploads its firmware image upon each code upload. This causes the device to disconnect and re-connect itself. If a USB filter is not used, the host will take control of the PICkit3 immediately after it disconnects itself.


## Hardware Requirements
- PICkit3 Programmer

The PICkit3 Programmer is used to upload software images to the AMS microcontroller. The programmer can be purchased from MicroChip [Here](www.microchip.com/pickit3).

## Building the Image
Open MPLABX, click build... you're done

## Uploading the Image
Open MPLAB, click build, click program device... it should upload

If it did not upload verify that you have USB

##Additional Resources
Listed below are some additional resources for writing software for the AMS PIC.

### Power Saving Techniques
[PIC Microcontroller Low Power Techniques](http://ww1.microchip.com/downloads/en/DeviceDoc/01146B_chapter%202.pdf)
