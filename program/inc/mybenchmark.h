/*
 * mybenchmark.h
 *
 *  Created on: Mar 6, 2015
 *      Author: serek8
 */
/** @file */
#ifndef MYBENCHMARK_H_
#define MYBENCHMARK_H_

#include <ctime>
#include "observer.h"
#include <iostream>
/**
 * @brief Klasa bazowa/interface do testowania algorytmu
 *
 * Używana jako interface dla wszystkich algorytmow aby
 * testowac czas wykonywanego algorymtu.
 *
 */
class MyBenchmark
{

	/**
	 * @brief Interface metody algorytmu glownego
	 *
	 * Metoda abstrakcyjna, ktora jest interfacem do
	 * implementacji przez glowny algorytm.
	 * To znaczy, ze kazdy algorytm ma byc uruchamiany tą funkcja
	 *
	 */



public:

	/// Czas stopera
	double timerValue;

	MyBenchmark()
	{
		timerValue = 0;
	}



	///  @brief włączam stoper
	void timerStart();

	/**
	 *  @brief wyłączam stoper
	 *  @return Dlugosc dzialania stopera
	 */
	double timerStop();

	/**
	 * @brief Usuwam obiekt test biorąc pod uwage jego prawdziwy typ
	 */
	virtual ~MyBenchmark() {};
	//using DataFrame::operator=;

};


class MyBenchmarkObserver : public MyBenchmark, public Observer
{
public:
	MyBenchmarkObserver(){};
	double getTimerValue() {return this->timerValue;}
	void receivedStartUpdate () {
		//std::cout<<"\nWlaczam stoper...";
		timerStart();
	}

	void receivedStopUpdate () {
		std::cout<<"\nCzas wykonywania operacji: "<<timerStop();
	}
	virtual ~MyBenchmarkObserver(){};

};



#endif /* MYBENCHMARK_H_ */
