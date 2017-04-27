#include "atmel/can_lib.h"
#include "atmel/can_drv.h"
#include "params.h"
#include "atomutils.h"
//#include "i2c.h"

/* #ifndef PACK_NUM */
/* #define PACK_NUM 0x003 */
/* #endif */


void task_can_init(void);
void task_can(uint32_t data);
