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
/** @brief Klasa bazowa/interface do testowania algorytmu
 *
 * Używana jako interface dla wszystkich algorytmow aby
 * testowac czas wykonywanego algorymtu.
 *
 */
class MyBenchmark
{
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

/** @brief Mybenchmark obserwator
 * Używana jako obserwator klasa
 * sprawdzajaca odpowiednie objekty
 */
class MyBenchmarkObserver : public MyBenchmark, public Observer
{
public:
	MyBenchmarkObserver(){};

	/** @brief pobiera czas trwania algorytmu
	 * @return czas trwania algorytmu
	 */
	double getTimerValue() {return this->timerValue;}

	/** @brief Odbiera powiadomienie o rozpoczeciu dzialania algorytmu
	 */
	void receivedStartUpdate () {
		timerStart();
	}

	/** @brief Odbiera powiadomienie o zakonczeniu dzialania algorytmu
	 */
	void receivedStopUpdate () {
		// std::cout<<"\nCzas wykonywania operacji: "<<timerStop();
	}
	virtual ~MyBenchmarkObserver(){};

};



#endif /* MYBENCHMARK_H_ */
