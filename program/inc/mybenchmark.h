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
#include <fstream>
//#include "filestreamer.h"
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
	std::ofstream streamToFile;
	double  timerValueStatic;
	MyBenchmark()
	{
		timerValue = 0;
		streamToFile.open ("log.txt", std::ofstream::out  | std::ofstream::trunc);
			streamToFile.close();
		streamToFile.open ("log.txt", std::ofstream::app);
		streamToFile << std::fixed;
	}
	void newL();
	void tab();

	///  @brief włączam stoper
	void  timerStart();

	/**
	 *  @brief wyłączam stoper
	 *  @return Dlugosc dzialania stopera
	 */
	double  timerStop();
	double  timerStopAndSaveToFile();
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

	void receivedStopUpdateAndSaveToFile () {
		timerStop();
		streamToFile<<timerValue<<std::endl;

	}

	virtual ~MyBenchmarkObserver(){streamToFile.close();};

};



#endif /* MYBENCHMARK_H_ */
