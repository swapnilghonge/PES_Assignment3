/**@file: touch_sensor.h
 * @brief: two functions have been defined
 *  Touch_Init() and Touch_Scan_LH();
 *
   @author: Swapnil Ghonge
 * @date: Feb 10th 2022
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with Arm Cortex-M based Microcontrollers by Alexander G.Dean
 *
 * @Link: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Misc/Touch%20Sense/TSI/src/main.c
 *
 */

#ifndef TOUCH_H_
#define TOUCH_H_

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "clock_config.h"
#include "fsl_debug_console.h"
#include "MKL25Z4.h"
#include "pin_mux.h"
#include "led.h"

/**
 *
 * @brief: this function sets the clock of the touch sensor and port to initialize
 *
 * @param: NULL
 * @return:  NULL
 */
void Touch_Init();
/**
 * @brief: function return the value of change in capcitance  when we touch the sensor
 * It has a offset of 550 to avoid anamolous results
 *
 *
 * @param: NULL
 * @return: difference of scan value and offset
 *
 */
int Touch_Scan_LH(void);
#define TOUCH_OFFSET 550  // offset value to be subtracted
#define TOUCH_DATA (TSI0->DATA & 0xFFFF)//macro for extracting the count from data register
#define TSI_sensor 0u
#define scanning_frequency 31u
#define channel_select 10u
#endif /* TOUCH_H_ */
