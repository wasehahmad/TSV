#include "config.h"

// arduino wire (i2c) library
#include <Wire.h>

// ams board library
#include "ams.h"

// arduino character lcd library
#include <LiquidCrystal.h>

#include "Button.h"

// PINOUT
//
// RED Button to digital pin 8
// BLACK Button to digital pin 9
// LCD RS pin to digital pin 12
// LCD Enable pin to digital pin 11
// LCD D4 pin to digital pin 5
// LCD D5 pin to digital pin 4
// LCD D6 pin to digital pin 3
// LCD D7 pin to digital pin 2
// LCD R/W pin to ground
// LCD VSS pin to ground
// LCD VCC pin to 5V

// 0802 character display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// user input switches
byte gpio_switch; //FIXME

bool address_test = false;
/**
* @name 
* @{ */
Button button_ok     = Button(9, BUTTON_PULLUP_INTERNAL);
Button button_cancel = Button(8, BUTTON_PULLUP_INTERNAL);
/**  @} */

void print_lcd(LiquidCrystal* lcd, const char* line1, const char* line2) {
  // clear lcd
  lcd->clear();
  
  // print line 1 to lcd
  lcd->setCursor(0, 0);
  lcd->print(line1);
  
  // print line 2 to lcd
  lcd->setCursor(0, 1);
  lcd->print(line2);
}

byte verify_i2c_addr(byte address) {
  Wire.beginTransmission(address);
  return (Wire.endTransmission() == 0);
}

/**
* @brief 
*
* @return 
*/
byte scan_i2c(void) {
  byte i2c_last = 255;
  byte error, address;
  
  for(address = 1; address < 127; address++ ) {
    // check for i2c device response at address
    // if device is present, update last found address
    if (verify_i2c_addr(address)) i2c_last = address;
  }
  
  // return last valid i2c addr
  return i2c_last;
}



/**
* @brief 
*/
void change_addr(void) {
  // default new address value
  byte new_addr = 0x01;
  
  for(;;) {
    // string to be displayed on lcd
    // +1 is added for null termination
    char lcd_str2[8 + 1];
    
    // parse raw data into string format
    sprintf(&lcd_str2[0], "NEW 0x%02X", new_addr);
    
    // print data to screen for user verification
    print_lcd(&lcd, "SET ADDR", lcd_str2);
    
    // if cancel is pressed, increment address
    if(button_cancel.uniquePress()) {
      // increment new address value
      // if increment would exceed 32, reset to 1
      new_addr = (new_addr < 0x20) ? new_addr + 1 : 0x01;
    }
    // if ok is pressed, set address
    else if(button_ok.uniquePress()) {
      print_lcd(&lcd, "SETTING ", "ADDRESS ");
      delay(500);
      set_address(new_addr);
      
      // address set, exit loop
      break;
    }
    
    // delay 50ms to avoid lcd flicker
    delay(50);
  }
}

/**
* @brief Send two data points from the ADC to calibrate AMS voltage reading. 
* One at 2.7 volts another at 3.7 volts. The AMS will process the values to compute slope and offset values
*/
byte calibrate_voltage(byte ams_addr) {
  int16_t slope = 0;
  int16_t offset = 0;      
  uint16_t data_point1 = 0;
  uint16_t data_point2 = 0;
  
  // prompt user to set voltage for AMS to 2.7 Volts
  print_lcd(&lcd, "SET VOLT", "TO 2.7");

  delay(2000);

  char lcd_str1[8 + 1];
  char lcd_str2[8 + 1];
  
  unsigned long last_millis = 0;
  const uint16_t update_rate_ms = 500;
  do {
    if((millis() - last_millis) >= update_rate_ms) {
      // update last poll time
      last_millis = millis();
      
      struct cell_data ams_data;
      ams_data = get_data(ams_addr);
      
      // parse raw data into string format
      sprintf(&lcd_str1[0], "V:0x%04X", ams_data.voltage);
      print_lcd(&lcd, "VOLTAGE", lcd_str1);

      // save the voltage reading from the ADC at this test point
      data_point1 = ams_data.voltage;
    }
    // wait for user response/verification
  } while (!button_ok.uniquePress() && !button_cancel.uniquePress());

  if(button_cancel.isPressed()) {
    Serial.println("CALIBRATION CANCELLED");
    print_lcd(&lcd, "CAL", "CANCEL");
    delay(1000);
    return FAIL_CALIBRATION;
  }
  
    // prompt user to set voltage for AMS to 3.7 Volts
    print_lcd(&lcd, "SET VOLT", "TO 3.7");
    
    delay(2000);
    last_millis = 0;
    do {
      if((millis() - last_millis) >= update_rate_ms) {
        // update last poll time
        last_millis = millis();
      
        struct cell_data ams_data;
        ams_data = get_data(ams_addr);
      
        // parse raw data into string format
        sprintf(&lcd_str2[0], "V:0x%04X", ams_data.voltage);
        print_lcd(&lcd, "VOLTAGE", lcd_str2);
        
        // save the voltage reading from the ADC at this test point
        data_point2 = ams_data.voltage;
      }
    // wait for user response/verification
    } while (!button_ok.uniquePress() && !button_cancel.uniquePress());

    if(button_cancel.isPressed()) {
      Serial.println("CALIBRATION CANCELLED");
      print_lcd(&lcd, "CAL", "CANCEL");
      delay(1000);
      return FAIL_CALIBRATION;
    }
    
    // send calibration info
     data_point1 = data_point1 * 2 * 3; // Conversion to mV : 2 mV per bit in the AMS ADC & the voltage is divided by 3 at the ADC input
     data_point2 = data_point2 * 2 * 3;

    slope = ((3.7-2.7) * 1000) / (data_point2 - data_point1) * 1024;  // the first term is multiplied by 1000 in order to convert to mV
                                                                      // the overall eq is then multiplied by 1024 in order to store as an int
    float a = (2.7-(((float)slope/1024) * ((float)data_point1/1000))) ;
    
    offset = a * 1024;

    Serial.print("SLOPE: ");
    Serial.println(slope);
    Serial.print("OFFSET: ");
    Serial.println(offset);
    delay(500);
    set_v_cal(ams_addr, slope, offset);
    Serial.println("CALIBRATION COMPLETED");
    print_lcd(&lcd, "CAL", "COMPLETE");
    delay(1000);
    return PASS;
}


/**
* @brief 
*
* @return 
*/
byte test_ams(byte ams_addr) {
  // test case variables
  byte error, exit_flag;
  
  // update lcd to inform user test is starting
  print_lcd(&lcd, "STARTING", "TESTING!");

  address_test = false;
  
  //
  // TEST CASE 1
  //
  //   check ams for response on current address
  Wire.beginTransmission(ams_addr);
  error = Wire.endTransmission();

  if (error != PASS) {
    Serial.println("FAILED TEST1");
    delay(500);
    return FAIL_TEST1;
  }
  Serial.println("PASSED TEST1");
  delay(500);
  
  
  //
  // TEST CASE 2
  //
  //   ams only responds to its own address
  for(byte address = 1; address < 127; address++ ) {
    if(address != ams_addr) {
      Wire.beginTransmission(address);
      error = Wire.endTransmission();
  
      if (error == 0) {
        Serial.println("FAILED TEST2");
        delay(500);
        return FAIL_TEST2;
      }
    }
  }
  Serial.println("PASSED TEST2");
  delay(500);
  
  
  //
  // TEST CASE 3
  //
  //   verify PANIC/RELAX commands
  
  // place ams in PANIC mode (ACT LED blinks)
  panic(ams_addr);
  
  // ask user if ACT LED is blinking
  print_lcd(&lcd, "ACT LED", "BLINK? ");
  
  // wait for user response/verification
  while (!button_ok.uniquePress() && !button_cancel.uniquePress()) ;
  
  // user responds w/ test failure, handle
  if(button_cancel.isPressed()) {
    Serial.println("FAILED TEST3");
    delay(500);
    return FAIL_TEST3;
  }
  
  // clear panic mode
  relax(ams_addr);
  delay(500);
  
  print_lcd(&lcd, "ACT LED", "OFF?");
  
  // wait for user response/verification
  while (!button_ok.uniquePress() && !button_cancel.uniquePress());
  
  // user responds w/ test failure, handle
  if(button_cancel.isPressed()) {
      Serial.println("FAILED TEST3");
      delay(500);
    return FAIL_TEST3;
  }
  Serial.println("PASSED TEST3");
  delay(500);
  
  
  //
  // TEST CASE 4
  //
  //   verify bypass mode
  
  // inform user bypass should come on for 3 seconds
  // and then turn off
  print_lcd(&lcd, "BYPASS  ", "ON->OFF?");
  
  // set bypass limit to 3 seconds
  set_bytime(ams_addr, 4 * 3);
  delay(10);
  
  // place ams in bypass mode
  set_bypass(ams_addr);
  delay(10);
  
  // wait for user response/verification
  while (!button_ok.uniquePress() && !button_cancel.uniquePress());
  
  // user responds w/ test failure, handle
  if(button_cancel.isPressed()) {
    Serial.println("FAILED TEST4");
    delay(500);
    return FAIL_TEST4;
  }
  Serial.println("PASSED TEST4");
  delay(500);
  
  //
  // TEST CASE 5
  //
  //   verify reading ams data (temp/voltage)
  
  // string to be displayed on lcd
  // +1 is added for null termination
  char lcd_str1[8 + 1];
  char lcd_str2[8 + 1];
  
  unsigned long last_millis = 0;
  const uint16_t update_rate_ms = 500;
  do {
    if((millis() - last_millis) >= update_rate_ms) {
      // update last poll time
      last_millis = millis();
      
      struct cell_data ams_data;
      ams_data = get_data(ams_addr);
      
      // parse raw data into string format
      sprintf(&lcd_str1[0], "V:0x%04X", ams_data.voltage);
      sprintf(&lcd_str2[0], "T:0x%04X", ams_data.temperature);
      
      // print data to screen for user verification
      print_lcd(&lcd, lcd_str1, lcd_str2);
    }
  // wait for user response/verification
  } while (!button_ok.uniquePress() && !button_cancel.uniquePress());
  
  if(button_cancel.isPressed()) {
    Serial.println("FAILED TEST5");
    delay(500);
    return FAIL_TEST5;
  }
  Serial.println("PASSED TEST5");

  //
  // TEST CASE 6
  //
  //   ams responds when address is changed

  print_lcd(&lcd, "ADDRESS", "  TEST   ");
  address_test = true;   // Indicator that address testing is occuring 
  
  // Random address testing
  for(int i = 1; i < 6; i++) {
    byte rand_addr = random(1,127);
    set_address(rand_addr);
    delay(500);
    
    Wire.beginTransmission(rand_addr);
    error = Wire.endTransmission();
    if (error != 0) {
      
      // parse raw data into string format
      char a[15];
      sprintf(a, "FAILED TEST6-%d",i);
      
      Serial.println(a);
      delay(500);
      return FAIL_TEST6;
    }
    
    // parse raw data into string format
    char b[14];
    sprintf(b, "PASSED TEST6-%d",i);
    delay(500);
    Serial.println(b);
  }

  // Set AMS back to original address
  set_address(ams_addr); delay(500);
  Wire.beginTransmission(ams_addr);
  error = Wire.endTransmission();
    if (error != 0) {
      Serial.println("FAILED TEST6-6");
      delay(500);
      return FAIL_TEST6;
    }
  Serial.println("PASSED TEST6-6");
  delay(500);
  
  address_test = false; // End of address testing


  //
  // TEST CASE 7
  //
  //   verify serial number
    
  last_millis = 0;
  //const uint16_t update_rate_ms = 500;
  do {
    if((millis() - last_millis) >= update_rate_ms) {
      // update last poll time
      last_millis = millis();
      
      struct cell_serial ams_serial;
      ams_serial = get_serial(ams_addr);
      
      // parse raw data into string format
      sprintf(&lcd_str1[0], "SERIAL");
      sprintf(&lcd_str2[0], "%d%d%d%d", ams_serial.serial[3], ams_serial.serial[2], ams_serial.serial[1], ams_serial.serial[0]);
      
      // print data to screen for user verification
      print_lcd(&lcd, lcd_str1, lcd_str2);
    }
  // wait for user response/verification
  } while (!button_ok.uniquePress() && !button_cancel.uniquePress());
  
  if(button_cancel.isPressed()) {
    Serial.println("FAILED TEST7");
    delay(500);
    return FAIL_TEST7;
  }
  Serial.println("PASSED TEST7");

  //
  // TEST CASE 8
  // 
  //    Verify Cal factors
  
  delay(1000);
  last_millis = 0;
  //const uint16_t update_rate_ms = 500;
  do {
    if((millis() - last_millis) >= update_rate_ms) {
      // update last poll time
      last_millis = millis();
      
      struct cell_cal ams_cal;
      ams_cal = get_cal(ams_addr);
      
      // parse raw data into string format
      sprintf(&lcd_str1[0], "S: %d", ams_cal.slope);
      sprintf(&lcd_str2[0], "O: %d", ams_cal.offset);
      
      // print data to screen for user verification
      print_lcd(&lcd, lcd_str1, lcd_str2);
    }
  // wait for user response/verification
  } while (!button_ok.uniquePress() && !button_cancel.uniquePress());
  
  if(button_cancel.isPressed()) {
    Serial.println("FAILED TEST8");
    delay(500);
    return FAIL_TEST8;
  }
  Serial.println("PASSED TEST8");

  //
  // TEST CASE 9
  // 
  //    Print calibrated voltage

  delay(1000);
  struct cell_cal ams_cal;
  ams_cal = get_cal(ams_addr);
  
  float slope  = (float)ams_cal.slope/1024;
  float offset = (float)ams_cal.offset/1024;
  int16_t cal_voltage;
  
  last_millis = 0;
  do {
    if((millis() - last_millis) >= update_rate_ms) {
      // update last poll time
      last_millis = millis();
      
      struct cell_data ams_data;
      ams_data = get_data(ams_addr);

      // slope was multiplied by 1024 to make it an int
      // need to undo before applying

      cal_voltage = ams_data.voltage * 2 * 3 * slope  + offset; 
      // parse raw data into string format
      sprintf(&lcd_str1[0], "VOLTAGE");
      sprintf(&lcd_str2[0], "%d mV", cal_voltage);
      
      // print data to screen for user verification
      print_lcd(&lcd, lcd_str1, lcd_str2);
    }
  // wait for user response/verification
  } while (!button_ok.uniquePress() && !button_cancel.uniquePress());
  
  if(button_cancel.isPressed()) {
    Serial.println("FAILED TEST9");
    delay(500);
    return FAIL_TEST9;
  }
  Serial.println("PASSED TEST9");
  
  return PASS;
}

/**
* @brief 
*/
void setup() {
  // Begin Serial Communication
  Serial.begin(9600);

  // Start AMS I2C Bus
  ams_init();
  
  // Initialize LCD Display
  lcd.begin(8,2);
  lcd.home();

 // Generate random seed for address testing
 randomSeed(analogRead(0));
}

void loop() { 
  
  print_lcd(&lcd, "NO AMS" , "FOUND");
  
  // scan for AMS
  byte addr = scan_i2c();
 
  if(addr != 255) {
    
    byte state = STATE_VERIFY_AMS;
    
    // while ams is present, check buttons
    while(verify_i2c_addr(addr) || (address_test == true)) {
      if(state == STATE_VERIFY_AMS) {
        // string to be displayed on lcd
        // +1 is added for null termination
        char lcd_str1[8 + 1];

        // parse raw data into string format
        sprintf(&lcd_str1[0], "AMS 0x%02X", addr);
        
        // display ams addr on lcd
        // ask user for test
        print_lcd(&lcd, lcd_str1, "VERIFY? ");


        // Set Serial
        // ENTER "SERIAL" into the serial monitor 9600 baud and no line ending
        // Then enter the serial number slower than 1 digit/sec to allow parseInt() to read input
        if (Serial.available()) {
          String str = "";
          uint8_t serial[4] = {0, 0, 0, 0};

          str = Serial.readString();

          if(str == "SERIAL") {
            Serial.print("Please slowly enter the 4-digit serial number one digit at a time: ");
            for(int i = 0; i < 4; i++){
              while(Serial.available() == 0) {}
              serial[3-i] = Serial.parseInt();
              Serial.print(serial[3-i]);
            }
            Serial.println();
            Serial.print("Serial: ");
            Serial.print(serial[3], DEC);
            Serial.print(serial[2], DEC);
            Serial.print(serial[1], DEC);
            Serial.print(serial[0], DEC);
            Serial.println();
            
          }
          // check if the serial array is empty
          int j = 0;
          for(int i = 0; i < 4; i++){
            if(serial[i] == 0) {
              j++;
            }
          }

          // only send  the serial is if isn't all zeros
          if(j!=4) {
            set_serial(addr, serial);
          }

          // clear the serial array
          for(int i = 0; i < 4; i++){
            serial[i] = 0;
          }
        }else{}

        
        // begin testing on button_ok press
        if(button_ok.uniquePress()) {
          if(test_ams(addr) == PASS) {
            print_lcd(&lcd, "  TEST  ", " PASSED ");
          }
          else {
            print_lcd(&lcd, "  TEST  ", " FAILED ");
          }
          // wait before clearing lcd
          delay(1000);
        }
        
        // transition state on button_cancel press
        else if(button_cancel.uniquePress()) {
          state = STATE_CHANGE_ADDR;
        }
      }
      else if(state == STATE_CHANGE_ADDR) {
        // button_cancel pressed, handle
        print_lcd(&lcd, "CHANGE", "ADDR?");
        
        if(button_ok.uniquePress()) {
          change_addr();
          
          // address change complete, move to calibrate voltage
          state = STATE_CALIBRATE_VOLTAGE;
        }
        
        // transition state on button_cancel press
        else if(button_cancel.uniquePress()) {
          state = STATE_CALIBRATE_VOLTAGE;
        }
        
      }
      else if(state == STATE_CALIBRATE_VOLTAGE) {
        print_lcd(&lcd, "CAL", "VOLTAGE?");

        if(button_ok.uniquePress()) {
          calibrate_voltage(addr);
          state = STATE_VERIFY_AMS;
        }

        else if(button_cancel.uniquePress()) {
          state = STATE_VERIFY_AMS;
        }
      }   
      else state = STATE_VERIFY_AMS;
      // delay 50ms, so we are not flooding the bus
      delay(50);
      }
    }

    // delay 50ms so lcd does not blink
    delay(50);
}
