/*
 * mybenchmark.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: serek8
 */
/** @file */

#include "mybenchmark.h"


void MyBenchmark :: timerStart()
{
	timerValue = (( (double)clock() ) /CLOCKS_PER_SEC);
}

double MyBenchmark :: timerStop()
{
	return (( (double)clock() ) /CLOCKS_PER_SEC) - timerValue;
}
