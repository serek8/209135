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
	MyBenchmark::timerValueStatic = (( (double)clock() ) /CLOCKS_PER_SEC);
}

double MyBenchmark :: timerStop()
{
	return (( (double)clock() ) /CLOCKS_PER_SEC) - MyBenchmark::timerValueStatic;
}

double MyBenchmark :: timerStopAndSaveToFile()
{
	double x= timerStop();
			streamToFile<<x;
			return x;
}
void MyBenchmark :: tab()
{
	streamToFile<<" ";

}
void MyBenchmark :: newL()
{
	streamToFile<<"\n";

}
