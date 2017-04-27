#ifndef ATOMUTILS_H
#define ATOMUTILS_H

// RTOS includes
#include "atomport.h"
#include "atomtimer.h"

/**
* @brief AtomThreads Milliseconds Delay
* 
* Delays the RTOS by the given number of milliseconds.
*
* @param delay_ms The number of miliseconds to delay
*
* @return 
*/
static inline uint8_t atom_delay_ms(uint32_t delay_ms) {
	return atomTimerDelay(delay_ms * SYSTEM_TICKS_PER_SEC / 1000UL);
}

/**
* @brief AtomThreads Seconds Delay
*
* Delays the RTOS by the given number of milliseconds.
*
* @param delay_s The number of seconds to delay
*
* @retval ATOM_OK Successful delay
* @retval ATOM_ERR_PARAM Bad parameter (ticks must be non-zero)
* @retval ATOM_ERR_CONTEXT Not called from thread context
*/
static inline uint8_t atom_delay(uint32_t delay_s) {
	return atomTimerDelay(SYSTEM_TICKS_PER_SEC * delay_s);
}

/**
* @brief Time in Milliseconds to Tick Count
*
* Converts a time specified in milliseconds into an AtomThreads tick count.
*
* @param time_ms System time in milliseconds
*
* @return AtomThreads tick count
*/
static inline uint32_t atom_time_ms(uint32_t time_ms) {
	return (time_ms * SYSTEM_TICKS_PER_SEC / 1000UL);
}

/**
* @brief AtomThreads System Time in Seconds
*
* Converts a time specified in seconds into an AtomThreads tick count.
*
* @param time_ms System time in seconds
*
* @return AtomThreads tick count
*/
static inline uint32_t atom_time_s(uint32_t time_s) {
	return (time_s * SYSTEM_TICKS_PER_SEC);
}
#endif /*ATOMUTILS_H*/
