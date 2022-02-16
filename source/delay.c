/**@file: delay.c
 * @brief: the function is used to set delay of the of msec
 *
 * @author: Swapnil Ghonge
 * @date: Feb 10th 2022
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with Arm Cortex-M based Microcontrollers by Alexander G.Dean
 */

/**
 * @brief: delay function to set the time delay using
 * nested for loops.
 *
 * @param: input to be the time of data type int in milliseconds
 * @return: returns NULL
 */
void delay(int msec)
{
	int i,j;
	for(i=0;i<msec;i++)
	{
		for(j=0;j<1650;j++)
		{
		}
	}
}
