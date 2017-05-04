#ifndef AMS_H
#define AMS_H

#include <Arduino.h>
#include <stdint.h>

/**
* @brief 
*/
struct cell_data {
  uint16_t voltage;
  uint16_t temperature; 
};

/**
* @brief 
*/
struct cell_magic {
  uint16_t magic; 
};

/**
* @brief 
*/
struct cell_cal {
  int16_t slope;
  int16_t offset;
};


/**
* @brief 
*/
struct cell_serial {
  uint8_t serial[4]; 
};


/**
* @brief 
*/
void ams_init(void);


/**
* @brief 
*
* @param address
*/
void clear_bypass(byte address);


/**
* @brief 
*
* @param address
*/
void set_bypass(byte address);


/**
* @brief 
*
* @param address
*/
void panic(byte address);


/**
* @brief 
*
* @param address
*/
void relax(byte address);


/**
* @brief 
*
* @param new_addr
*/
void set_address(byte new_addr);


/**
* @brief 
*
* @param address
* @param bytime
*/
void set_bytime(byte address, uint16_t bytime);


/**
* @brief 
*
* @param address
* @param slope
* @param offset
*/
void set_v_cal(byte address, int16_t slope, uint16_t offset);

/**
* @brief 
*
* @param address
* @param serial
*/
void set_serial(byte address, uint8_t serial[4]);


/**
* @brief 
*
* @param address
*
* @return 
*/
struct cell_data get_data(byte address);


/**
* @brief 
*
* @param address
*
* @return 
*/
struct cell_magic get_magic(byte address);


/**
* @brief 
*
* @param address
*
* @return 
*/
struct cell_cal get_cal(byte address);


/**
* @brief 
*
* @param address
*
* @return 
*/
struct cell_serial get_serial(byte address);

#endif /*AMS_H*/
