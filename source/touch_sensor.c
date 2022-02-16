/**@file: touch.c
 * @brief: two functions have been implemented
 * namely Touch_Init() and Touch_Scan_LH() to initialize touch sensor.
 *
 * @author: Swapnil Ghonge
 * @date: Feb 10th 2022
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with Arm Cortex-M based Microcontrollers by Alexander G.Dean
 * @Link: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Misc/Touch%20Sense/TSI/src/main.c
 */

#include "touch_sensor.h"

/**
 *
 * @brief: this function sets the clock of the touch sensor and port to initialize
 *
 * @param: NULL
 * @return:  NULL
 */
void Touch_Init(void)
{
#if DEBUG
	printf("touch sensor initialization started");
#endif
			SIM->SCGC5 |= SIM_SCGC5_TSI_MASK; // enabling the clock

			TSI0->GENCS = TSI_GENCS_MODE(TSI_sensor) | 					//operating in non-noise mode
			TSI_GENCS_REFCHRG(TSI_sensor) | 							//reference oscillator charge and discharge value 500nA
			TSI_GENCS_DVOLT(TSI_sensor) | 								// oscillator voltage rails set to default
			TSI_GENCS_EXTCHRG(TSI_sensor) |								// electrode oscillator charge and discharge value 500nA
			TSI_GENCS_PS(TSI_sensor) | 									// frequency clock divided by one
			TSI_GENCS_NSCN (scanning_frequency) | 								// scanning the electrode 32 times
			TSI_GENCS_TSIEN_MASK | 								//enabling the TSI module
			TSI_GENCS_EOSF_MASK; 								// writing one to clear the end of scan flag
#if DEBUG
	printf("touch sensor initialization completed");
#endif
}

/**
 * @brief: function return the value of change in capcitance  when we touch the sensor
 * It has a offset of 550 to avoid anamolous results
 *
 *
 * @param: NULL
 * @return: difference of scan value and offset
 *
 */
int Touch_Scan_LH(void)
{
#if DEBUG
	printf("scanning by touch sensor started\r\n");
#endif
			unsigned int scan=0;						// initializing the value of scan as '0'
			TSI0->DATA = TSI_DATA_TSICH(channel_select); 			// selecting channel 10
			TSI0->DATA |= TSI_DATA_SWTS_MASK; 			// software trigger to start the scan
			while(!(TSI0->GENCS & TSI_GENCS_EOSF_MASK)); //waiting for the scan to complete 32 times
			scan = TSI0->DATA & 0xFFFF; 				// macro for extracting the count from data register
			TSI0->GENCS |= TSI_GENCS_EOSF_MASK; 		// writing one to clear the end of the flag
			return scan-TOUCH_OFFSET;
#if DEBUG
	printf("scanning by touch sensor completed\r\n");
#endif
}
