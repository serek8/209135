/*
 * main.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: serek8
 */
/** @file */
#include <iostream>
#include <unistd.h>
#include "multiplybytwo.h"
#include "numbergenerator.h"
#include "dataframe.h"
#include "mystack.h"
#include "myqueue.h"


int main(int argc, char *argv[])
{
	DataFrame podstawoweInfoIO;
	int quantityRepetitionOfAlgorithm = 0;	/// Ilosc powtorzen przez algorytmu

	int opt;	/// Zmienna uzywana przez GETOPT
	bool isSetNumberGenerator=false; /// Flaga ktora mowi o tym czy wlaczyc generator liczb losowych
	bool isTest=false;

	while ((opt = getopt(argc, argv, "n:t:o:i:gx")) != -1) {
		switch(opt){
		case 'n':	// ilosc liczb do przetworzenia
			podstawoweInfoIO.sizeOfTable = atoi(optarg);
			break;

		case 't':	// wlacza benchmark i przyjmuje liczbe powtorzen dla benchmarka
			quantityRepetitionOfAlgorithm = atoi(optarg);
			break;

		case 'o':
			podstawoweInfoIO.outputFileName = optarg;
			break;

		case 'i':
			podstawoweInfoIO.inputFileName=optarg;
			break;

		case 'g':	// wlacza generator liczb, po zakonczeniu generowania konczy program
			isSetNumberGenerator=true;
			break;

		case 'x':	// miejsce dla programisty dla sprawdzania kodu
			isTest =1;
			break;

		case '?':
		default:
			std::cout<<"\nPodano zly argument";
			return -1;
		}
	}
	/**
	 * Czesc testowa programu
	 */
	if(isTest)
	{
		MyQueue stack;
		stack.push(1); stack.push(2); stack.push(3);
		std::cout<<stack.pop();
		std::cout<<stack.pop();
		std::cout<<stack.pop();
		return 0;
	}


	/*
	 * Sprawdzam czy program zostal uzyty tylko do wygenerowania liczb losowych
	 * jesli tak to tworze te liczby zgodnie quantityNumber i zamykam program
	 */
	if(isSetNumberGenerator) {
	NumberGenerator generator;
	generator= podstawoweInfoIO;
	generator.generateNumbers();
	generator.saveDataToFile();
	std::cout<<"\nZapisane.\n";
	return 0;
	}


	MultiplyByTwo algorytm_x2 ;
	algorytm_x2= podstawoweInfoIO;

	/*
	 *  Wczytuje liczby z pliku do przeprowadzenia algorytmu
	 */
	if(algorytm_x2.loadDataFromFile()) {
		std::cout<<"\nNie istnieje tyle liczb w pliku !\nKoncze program";
		return 1;
	}

	/*
	 * Sprawdzam czy otrzymalem agrument o testowaniu algorytmu,
	 * a nastepnie przeprawadzam test albo uruchamiam normalnie algorytm
	 */
	if(quantityRepetitionOfAlgorithm){
		std::cout<<"\nCzas algorytmu: "<<algorytm_x2.testAlgorithm(quantityRepetitionOfAlgorithm)<<'\n';
	}
	else {
		algorytm_x2.executeAlgorithm();
	}

	/*
	 * Zapisuje wyniki do pliku
	 */
	algorytm_x2.saveDataToFile();

	return 0;
}
