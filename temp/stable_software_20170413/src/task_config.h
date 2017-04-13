#ifndef TASK_CONFIG_H
#define TASK_CONFIG_H

#include <stdint.h>

void task_config(uint32_t data);

// STORES INFORMATION FOR THE FAULT CONDITION: COND - WHY THE FAULT IS IN PLACE (CELL_V, CELL_T, ETC.)
/* struct flt_cond { */
/*   uint8_t active; */
/*   uint8_t cond; */
/*   uint8_t area; */
/*   uint16_t val; */
/* }; */



#endif /*TASK_CONFIG_H*/
