/**
 * @file	log.h
 * @brief  	abstraction away from printf
 * @author 	Howdy Pierce
 * @note	This file in its entirety is courtesy of Howdy Pierce's course slides
 * 		 	for PES spring 2022
 *
 */


#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>

//To get the debug target, simply uncomment the below line...
//#define DEBUG_ON 1

#ifdef DEBUG_ON
#  define LOG printf
#else
#  define LOG(...)
#endif

#endif /* LOG_H_ */
