/**@file: Led.h
 * @brief: color select functionality via enum to select and switch off the LED
 * Two functions have been defined Led_Initialize() and Led_select()
 * @author: Swapnil Ghonge
 * @date: Feb 10th 2022
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with Arm Cortex-M based Microcontrollers by Alexander G.Dean
 */

#ifndef LED_H_
#define LED_H_


#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "clock_config.h"
#include "fsl_debug_console.h"
#include "MKL25Z4.h"
#include "pin_mux.h"
#include "delay.h"

#define PORT_PCR_MUX_PIN (8)
#define RED_LED_PIN (18)
#define GREEN_LED_PIN (19)
#define BLUE_LED_PIN (1)
#define time_delay_500 500
#define time_delay_100 100
/*
 * enum to define the LED color
 */
typedef enum
{
	RED,
	GREEN,
	BLUE,
	WHITE,
	OFF
}color;
/**
 * @brief: function includes sets the clock of PORT B and PORT D
 *  the pins set are PSOR, PCOR, PDDR of each port
 * to make three pins GPIO and set LED bits to outputs.
 *
 * @param: NULL
 * @return: returns NULL
 *
 */
void Led_initialize(void);
/**
 * @brief: function is used to turn ON and OFF the LED
 * PCOR and PSOR register respectively.
 *
 * @param: enum color variable is used to turn off the LED
 * @return: NULL.
 */
void Led_select(color colour);
/**
 * @brief: Function to run the basic functionality of LED
 *			RED Led on for 500ms off for 100ms
 *			Green Led on for 500ms off for 100ms
 *			Blue Led on for 500 ms off for 100ms
 *			White Led on for 100ms and off for 100ms
 *
 * @return: NULL.
 */
void test_led();


#endif /* LED_H_ */
