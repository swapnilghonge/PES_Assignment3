/**
 * @file: Blinken_lights.c
 * @brief: three functions definition of the function
 * including the main() function namely
 * Touch_Change_Color_On() and Touch_Change_Color_Off()
 *
  * @author: Swapnil Ghonge
 * @date: Feb 10th 2022
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with Arm Cortex-M based Microcontrollers by Alexander G.Dean
 */

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "clock_config.h"
#include "fsl_debug_console.h"
#include "MKL25Z4.h"
#include "pin_mux.h"
#include "led.h"
#include "touch_sensor.h"
#include "led.h"
#include "delay.h"
#include "log.h"

#define time_delay_100 100
uint32_t touch_val = 0;
color colour = WHITE;

/**
 * @brief: function changes the clour of the LED when touched the capacitive sensor
 * Polling function is performed every 100 msec
 * from the capacitive sensor and poll the sensor
 *
 * @param: NULL
 * @return:  NULL
 */
static void color_change_on()
{
	touch_val = Touch_Scan_LH();
	if(touch_val>=100 && touch_val<=350)
	{
#ifdef DEBUG_ON
	LOG("color change to red\r\n"); //when slider is on left
	LOG("slider value %d\r\n ", touch_val);
#endif
		colour = RED; // color changes to RED

	}
	else if(touch_val>350 && touch_val<=700) // when the slider is in middle
	{
#ifdef DEBUG_ON
	LOG("color change to green\r\n");
	LOG("slider value %d \r\n", touch_val);
#endif

		colour = GREEN; // color changes to GREEN

	}
	else if((touch_val>700)) //when slider is on right
	{
#ifdef DEBUG_ON
	LOG("color change to blue\r\n");
	LOG("slider value %d \r\n", touch_val);
#endif

		colour = BLUE; // color changes to BLUE
	}
	Led_select(colour); //turns on the respective LED
	delay(time_delay_100);
}

/**
* @brief: function changes the clour of the LED when touched the capacitive sensor
 * Polling function is performed every 100 msec
 * from the capacitive sensor and poll the sensor
 * is in OFF state.
 *
 * @param: NULL
 * @return: returns NULL
 */
static void color_change_off()
{
	touch_val = Touch_Scan_LH();
	if(touch_val>=100 && touch_val<=350) //when slider is on left
	{
#ifdef DEBUG_ON
	LOG("color change to red\r\n");
	LOG("slider value %d\r\n ", touch_val);
#endif
		colour = RED;

	}
	else if(touch_val>350 && touch_val<=700)//when slider is on center
	{
#ifdef DEBUG_ON
	LOG("color change to green\r\n");
	LOG("slider value %d\r\n ", touch_val);
#endif

		colour = GREEN;

	}
	else if((touch_val>800)) //when slider is on right
	{
#ifdef DEBUG_ON
	LOG("color change to blue\r\n");
	LOG("slider value %d\r\n ", touch_val);
#endif
		colour = BLUE;
	}
	delay(time_delay_100);
}

/**
 * @brief: main() function executes the
 * complete LED blinking sequence along
 * with the implementation.
 *
 * @param: NULL
 * @return: executes the program.
 */
int main(void)
{
	Touch_Init(); //initialize the touch sensor
	Led_initialize();//initialize the LED

	test_led();

	while(1)
	{
#ifdef DEBUG_ON
		LOG("start the timer for 500mssec\r\n");
#endif
		for(int i=0; i<5; i++) // turns on the LED for 500msec
		{
			color_change_on(); //call the function to change the state of LED to red
		}

		Led_select(OFF);
		for(int i=0; i<5; i++) // turns off the LED for 500msec
		{
			color_change_off(); //call the function to change the state of LED to switch off
		}

#ifdef DEBUG_ON
		LOG("start the timer for 1000mssec\r\n");
#endif
		for(int i=0; i<10; i++) // turns on the LED for 1000msec
		{
			color_change_on(); //call the function to change the state of LED to blue
		}

		Led_select(OFF);
		for(int i=0; i<5; i++) // turns off the LED for 500msec
		{
			color_change_off(); //call the function to change the state of LED to switch off
		}
#ifdef DEBUG_ON
		LOG("start the timer for 2000mssec\r\n");
#endif
		for(int i=0; i<20; i++) // turns on the LED for 2000msec
		{
			color_change_on(); //call the function to change the state of LED
		}

		Led_select(OFF);
		for(int i=0; i<5; i++) // turns off the LED for 500msec
		{
			color_change_off(); //call the function to change the state of LED to switch off
		}
#ifdef DEBUG_ON
		LOG("start the timer for 3000mssec\r\n");
#endif

		for(int i=0; i<30; i++)
		{
			color_change_on();
		}

		Led_select(OFF);
		for(int i=0; i<5; i++) // turns off the LED for 500msec
		{
			color_change_off(); //call the function to change the state of LED to switch off
		}
	}
		return 0;
}
