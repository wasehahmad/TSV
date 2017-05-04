#ifndef CONFIG_H
#define CONFIG_H

/**
* @name 
* @{ */
#define CLR_BY            0x00
#define SET_BY            0x01
#define PANIC             0x02
#define RELAX             0x03
#define SET_ADDR          0x04
#define SET_BYTIME        0x05
#define SET_V_CAL         0x06
#define SET_SERIAL        0x07
#define CHANGE_READ_TYPE  0x30

// i2c read types
#define READ_VOLTAGE  0x00
#define READ_SERIAL   0x01
#define READ_CAL_DATA 0x02
#define READ_MAGIC    0x03
/**  @} */

/**
* @name 
* @{ */
#define PASS 0
#define FAIL_TEST1 1
#define FAIL_TEST2 2
#define FAIL_TEST3 3
#define FAIL_TEST4 4
#define FAIL_TEST5 5
#define FAIL_TEST6 6
#define FAIL_TEST7 7
#define FAIL_TEST8 8
#define FAIL_TEST9 9

#define FAIL_CALIBRATION 1
#define FAIL_SERIAL 1
/**  @} */

/**
* @name 
* @{ */
#define STATE_VERIFY_AMS          0
#define STATE_CHANGE_ADDR         1
#define STATE_CALIBRATE_VOLTAGE   2
/**  @} */

#endif /*CONFIG_H*/

