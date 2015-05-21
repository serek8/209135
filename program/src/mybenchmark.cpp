/*
 * mybenchmark.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: serek8
 */
/** @file */

#include "mybenchmark.h"

double MyBenchmark::timerValueStatic=0;
void MyBenchmark :: timerStart()
{
	MyBenchmark::timerValueStatic = (( (double)clock() ) /CLOCKS_PER_SEC);
}

double MyBenchmark :: timerStop()
{
	return (( (double)clock() ) /CLOCKS_PER_SEC) - MyBenchmark::timerValueStatic;
}
