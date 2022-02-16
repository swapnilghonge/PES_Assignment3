/**@file: led.c
 * @brief: The definitions of the two function
 * namely Led_Initialize() and Led_select() to set the
 * GPIO pin configurations for red, green and blue LED.
 * and for switching ON and OFF the LED respectively.
* @author: Swapnil Ghonge
 * @date: Feb 10th 2022
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with Arm Cortex-M based Microcontrollers by Alexander G.Dean
 * @Links: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_2/Source/main.c
 */


#include "led.h"

/**
 * @brief: function includes sets the clock of PORT B and PORT D
 *  the pins set are PSOR, PCOR, PDDR of each port
 * to make three pins GPIO and set LED bits to outputs.
 *
 * @param: NULL
 * @return: returns NULL
 *
 */
void Led_initialize(void)
{
#ifdef DEBUG_ON
	printf("Inialization LED procedure started");
#endif
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;

	PORTB->PCR[RED_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_LED_PIN] |= (1 << PORT_PCR_MUX_PIN);
	GPIOB->PDDR |= (1 << RED_LED_PIN);
	GPIOB->PSOR |= (1 << RED_LED_PIN);
	PORTB->PCR[GREEN_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_LED_PIN] |= (1 << PORT_PCR_MUX_PIN);
	GPIOB->PDDR |= (1 << GREEN_LED_PIN);
	GPIOB->PSOR |= (1 << GREEN_LED_PIN);
	PORTD->PCR[BLUE_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_LED_PIN] |= (1 << PORT_PCR_MUX_PIN);
	GPIOD->PDDR |= (1 << BLUE_LED_PIN);
	GPIOD->PSOR |= (1 << BLUE_LED_PIN);
#ifdef DEBUG_ON
	printf("Initialization LED procedure completed\r\n");
#endif
}

/**
 * @brief: function is used to turn ON and OFF the LED
 * PCOR and PSOR register respectively.
 *
 * @param: enum color variable is used to turn off the LED
 * @return: NULL.
 */
void Led_select(color colour)
{
#ifdef DEBUG_ON
	printf("selection of colours in switch case\r\n");
#endif
	switch(colour)
		{
		case RED:
			GPIOB->PCOR |= (1 << RED_LED_PIN); // turn on RED LED
			GPIOB->PSOR |= (1 << GREEN_LED_PIN); // turn off GREEN LED
			GPIOD->PSOR |= (1 << BLUE_LED_PIN); // turn off BLUE LED
			break;

		case BLUE:
			GPIOD->PCOR |= (1 << BLUE_LED_PIN); // turn on BLUE LED
			GPIOB->PSOR |= (1 << RED_LED_PIN); // turn off RED LED
			GPIOB->PSOR |= (1 << GREEN_LED_PIN); // turning off GREEN LED
			break;
		case GREEN:
			GPIOB->PCOR |= (1 << GREEN_LED_PIN); // turn on GREEN LED
			GPIOB->PSOR |= (1 << RED_LED_PIN); // turn off RED LED
			GPIOD->PSOR |= (1 << BLUE_LED_PIN); // turn off BLUE LED
			break;
		case WHITE:
			GPIOB->PCOR |= (1 << RED_LED_PIN); // turn on RED LED
			GPIOB->PCOR |= (1 << GREEN_LED_PIN); // turn on GREEN LED
			GPIOD->PCOR |= (1 << BLUE_LED_PIN); // turn on BLUE LED
			break;
		case OFF:
			GPIOB->PSOR |= (1 << RED_LED_PIN); // turn off RED LED
			GPIOB->PSOR |= (1 << GREEN_LED_PIN); // turn off GREEN LED
			GPIOD->PSOR |= (1 << BLUE_LED_PIN); // turn off BLUE LED
			break;
		}
}
/**
 * @brief: Function to run the basic functionality of LED
 *			RED Led on for 500ms off for 100ms
 *			Green Led on for 500ms off for 100ms
 *			Blue Led on for 500 ms off for 100ms
 *			White Led on for 100ms and off for 100ms
 * @param: enum color variable is used to turn off the LED
 * @return: NULL.
 */
void test_led()
{
	Led_select(RED); // turns on RED LED for 500msec
	delay(time_delay_500);
	Led_select(OFF); // turns off RED LED for 100msec
	delay(time_delay_100);

	Led_select(GREEN); // turns on GREEN LED for 500msec
	delay(time_delay_500);
	Led_select(OFF); // turns off GREEN LED for 100msec
	delay(time_delay_100);

	Led_select(BLUE); // turns on BLUE LED for 500msec
	delay(time_delay_500);
	Led_select(OFF); // turns off BLUE LED for 100msec
	delay(time_delay_100);

	Led_select(WHITE); // turns on WHITE LED for 100msec
	delay(time_delay_100);;
	Led_select(OFF); // turns off WHITE LED for 100msec
	delay(time_delay_100);

	Led_select(WHITE); // turns on WHITE LED for 100msec
	delay(time_delay_100);
	Led_select(OFF); // turns off WHITE LED for 100msec
	delay(time_delay_100);
}
