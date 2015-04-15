/*
 * main.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: serek8
 */
/** @file */
#include <iostream>
#include <unistd.h>
#include "numbergenerator.h"
#include "dataframe.h"
#include "hashowanie.h"
#include "mylist.h"
#include "mybenchmark.h"
#include "dictionary.h"
#include <string>

int main(int argc, char *argv[])
{
	DataFrame podstawoweInfoIO;

	int opt;	/// Zmienna uzywana przez GETOPT
	bool isSetNumberGenerator=false; /// Flaga ktora mowi o tym czy wlaczyc generator liczb losowych
	//bool isTest=false;

	while ((opt = getopt(argc, argv, "n:o:i:gx")) != -1) {
		switch(opt){
		case 'n':	// ilosc liczb do przetworzenia
			podstawoweInfoIO.sizeOfTable = atoi(optarg);
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


		case '?':
		default:
			std::cout<<"\nPodano zly argument";
			return -1;
		}
	}


	// na potrzeby slownika wlaczam generowanie automatyczne
	isSetNumberGenerator = true;
	if(isSetNumberGenerator) {
		NumberGenerator generator;
		std::cout<<"\n+ - - - - Tworzenie tablicy i generacja losowych liczb - - - +\n";
		generator= podstawoweInfoIO;
		MyBenchmark::timerStart();
			generator.generateNumbers();
		std::cout<<"Generuje losowe liczby:"<<MyBenchmark::timerStop()<<'\n';
		podstawoweInfoIO = generator;
		podstawoweInfoIO.saveDataToFile();
	}

	Dictionary dict;
	std::cout<<"\nHashuje pierwsze "<<LICZBA_ZNAKOW_DO_HASHU<< " znaki.";
	std::string *str = NumberGenerator::generateStrings(podstawoweInfoIO.sizeOfTable);
	MyBenchmark::timerStart();
		for(unsigned int i=0; i<podstawoweInfoIO.sizeOfTable; i++)
		{
			dict[str[i]] = podstawoweInfoIO.tableOfData[i];
		}
	std::cout<<"\nCzas alokowania slownika:"<<MyBenchmark::timerStop()<<'\n';

	std::cout<<std::endl;
	return 0;
}
