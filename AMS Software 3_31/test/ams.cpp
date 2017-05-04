#include "config.h"
#include "ams.h"
#include <Arduino.h>
#include <Wire.h>

void ams_init(void) {
  Wire.begin();
}

void clear_bypass(byte address) {
  Wire.beginTransmission(address);
  Wire.write(CLR_BY);
  Wire.endTransmission();
  Serial.print("CLR_BYPASS 0x");
  Serial.println(address, HEX);
}

void set_bypass(byte address) {
  Wire.beginTransmission(address);
  Wire.write(SET_BY);
  Wire.endTransmission();
  Serial.print("SET_BYPASS 0x");
  Serial.println(address, HEX);
}

void panic(byte address) {
  Wire.beginTransmission(address);
  Wire.write(PANIC);
  Wire.endTransmission();
  Serial.print("PANIC 0x");
  Serial.println(address, HEX);
}

void relax(byte address) {
  Wire.beginTransmission(address);
  Wire.write(RELAX);
  Wire.endTransmission();
  Serial.print("RELAX 0x");
  Serial.println(address, HEX);
}

void set_address(byte new_addr) {
  Wire.beginTransmission(0x00);
  Wire.write(SET_ADDR);
  Wire.write(new_addr);
  Wire.endTransmission();
  Serial.print("SET_ADDR 0x");
  Serial.println(new_addr, HEX);
}

void set_bytime(byte address, uint16_t bytime) {
  Wire.beginTransmission(address);
  Wire.write(SET_BYTIME);
  Wire.write(bytime >> 8);
  Wire.write(bytime & 0xFF);
  Wire.endTransmission();
  Serial.print("SET_BYTIME 0x");
  Serial.println(address, HEX);
}

void set_v_cal(byte address, int16_t slope, uint16_t offset) {
  Wire.beginTransmission(address);
  Wire.write(SET_V_CAL);
  Wire.write(slope >> 8);
  Wire.write(slope & 0xFF);
  Wire.write(offset >> 8);
  Wire.write(offset & 0xFF);
  Wire.endTransmission();
  Serial.print("SET_V_CAL 0x");
  Serial.println(address, HEX);

  Serial.println(slope >> 8,    BIN);
  Serial.println(slope & 0xFF,  BIN);
  Serial.println(offset >> 8,   BIN);
  Serial.println(offset & 0xFF, BIN);
}

void set_serial(byte address, uint8_t serial[4]) {
  Wire.beginTransmission(address);
  Wire.write(SET_SERIAL);
  Wire.write(serial[3]); 
  Wire.write(serial[2]); 
  Wire.write(serial[1]);
  Wire.write(serial[0]);
  Wire.endTransmission();
  Serial.print("SET_SERIAL 0x");
  Serial.println(address, HEX);  
}


struct cell_data get_data(byte address) {
  // Tell AMS we want voltage/temp
  Wire.beginTransmission(address);
  Wire.write(CHANGE_READ_TYPE);
  Wire.write(READ_VOLTAGE);
  Wire.endTransmission();
  
  struct cell_data raw_data;
  Wire.requestFrom((int)address, 4);

  byte volt_h, volt_l;
  byte temp_h, temp_l;
  
  while (Wire.available())
  {
    temp_h = Wire.read();
    temp_l = Wire.read();
    volt_h = Wire.read();
    volt_l = Wire.read();
  }
  
  raw_data.voltage = (volt_h << 8) | volt_l;
  raw_data.temperature = (temp_h << 8) | temp_l;

  Serial.print("GET_CELL_DATA 0x");
  Serial.println(address, HEX);
  return raw_data;
}


struct cell_magic get_magic(byte address) {
  // Tell AMS we want the Magic number
  Wire.beginTransmission(address);
  Wire.write(CHANGE_READ_TYPE);
  Wire.write(READ_MAGIC);
  Wire.endTransmission();
  
  struct cell_magic raw_data;
  Wire.requestFrom((int)address, 2);

  byte magic_h, magic_l;
  
  while (Wire.available())
  {
    magic_h = Wire.read();
    magic_l = Wire.read();
  }

  raw_data.magic = (magic_h << 8) | magic_l;
  
  Serial.print("GET_CELL_MAGIC 0x");
  Serial.println(address, HEX);
  return raw_data;
}


struct cell_cal get_cal(byte address) {
    // Tell AMS we want cal data
  Wire.beginTransmission(address);
  Wire.write(CHANGE_READ_TYPE);
  Wire.write(READ_CAL_DATA);
  Wire.endTransmission();
  
  struct cell_cal raw_data;
  Wire.requestFrom((int)address, 4);

  byte cal_3, cal_2, cal_1, cal_0;
  
  while (Wire.available())
  {
    cal_3 = Wire.read();
    cal_2 = Wire.read(); 
    cal_1 = Wire.read();
    cal_0 = Wire.read();
  }
   
  raw_data.slope =  (cal_3 << 8) | cal_2;
  raw_data.offset = (cal_1 << 8) | cal_0;
  
  Serial.print("GET_CELL_CAL_DATA 0x");
  Serial.println(address, HEX);
  return raw_data;
}

struct cell_serial get_serial(byte address) {
  // Tell AMS we want serial number
  Wire.beginTransmission(address);
  Wire.write(CHANGE_READ_TYPE);
  Wire.write(READ_SERIAL);
  Wire.endTransmission();
  
  struct cell_serial raw_data;
  Wire.requestFrom((int)address, 4);

  byte serial_3, serial_2, serial_1, serial_0;
  
  while (Wire.available())
  {
    serial_3 = Wire.read();
    serial_2 = Wire.read();
    serial_1 = Wire.read();
    serial_0 = Wire.read();   
  }

  raw_data.serial[3] = serial_3;
  raw_data.serial[2] = serial_2; 
  raw_data.serial[1] = serial_1;
  raw_data.serial[0] = serial_0;

  Serial.print("GET_CELL_SERIAL 0x");
  Serial.println(address, HEX);
  return raw_data;
}





