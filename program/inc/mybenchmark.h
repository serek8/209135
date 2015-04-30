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
#include "dataframe.h"
#include "observer.h"
#include <iostream>
/**
 * @brief Klasa bazowa/interface do testowania algorytmu
 *
 * Używana jako interface dla wszystkich algorytmow aby
 * testowac czas wykonywanego algorymtu.
 *
 */
class MyBenchmark : public DataFrame
{
protected:
	/**
	 * @brief Interface metody algorytmu glownego
	 *
	 * Metoda abstrakcyjna, ktora jest interfacem do
	 * implementacji przez glowny algorytm.
	 * To znaczy, ze kazdy algorytm ma byc uruchamiany tą funkcja
	 *
	 */
	virtual void executeAlgorithm() = 0;


public:

	/// Czas stopera
	static double timerValue;

	/**
	 * @brief Benchmarkuje algorytm główny
	 *
	 * Obliczam czas wykonywanego algorytmu dzięki zastosowaniu
	 * metody abstrakcyjnej executeAlgorithm() i zaimplementowaniu
	 * tego interfacu w algorytmie głównym
	 *
	 */
	double testAlgorithm(unsigned int repetition);

	/**
	 *  @brief włączam stoper
	 */
	static void timerStart();

	/**
	 *  @brief wyłączam stoper
	 *  @return Dlugosc dzialania stopera
	 */
	static double timerStop();

	/**
	 * @brief Usuwam obiekt test biorąc pod uwage jego prawdziwy typ
	 *
	 */
	virtual ~MyBenchmark() {};
	//using DataFrame::operator=;

};


class MyBenchmarkObserver : public MyBenchmark, public Observer
{
public:
	MyBenchmarkObserver()
	{
		timerStart();
	}

	void update () {
		std::cout<<"\nCzas trwania algorytmu to " <<timerStop();

	}
	void executeAlgorithm(){};

};



#endif /* MYBENCHMARK_H_ */
