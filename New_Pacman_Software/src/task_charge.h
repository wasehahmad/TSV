#ifndef TASK_CHARGE_H
#define TASK_CHARGE_H

#include <stdint.h>
#include "lcd.h"
#include "i2c.h"
#include "params.h"
#include "config.h"

void task_charge(uint32_t data);
int8_t read_SOC(void);
void save_SOC(void);

#endif /*TASK_CHARGE_H*/

