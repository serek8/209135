/*
 * numbergenerator.h
 *
 *  Created on: Mar 11, 2015
 *      Author: serek8
 */
/** @file */
#ifndef NUMBERGENERATOR_H_
#define NUMBERGENERATOR_H_

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include "dataframe.h"
#include <string>

#define MAX_HEX_ASCII_KOD 127
#define ROZMIAR_STRINGU 20
/**
 * @brief Klasa generujaca losowe liczby
 *
 * Klasa generujaca losowe liczby na podstawie czasu maszyny na ktorym jest uruchomiona
 * Wszystkie funkcje zapisu pliku dziedziczy z klasy DataFrame
 *
 */
class NumberGenerator : public DataFrame
{
public:
/**
 * @brief Generuje losowe liczby
 * Generuje losowe liczby na podstawie czasu maszyny
 *
 * @param zakres Zakres liczb do wygenerowania
 */
void generateNumbers(int zakres=10000000)
{
	time_t randomTime = clock();
	this->tableOfData = new int[sizeOfTable];
	for(unsigned int i=0; i<sizeOfTable ; i++)
	{
		srand (randomTime = clock());
		this->tableOfData[i] = rand()%zakres;
		randomTime = clock();
	}
}

/**
 * @brief Generuje losowe stringi
 *
 * @param ileStringow Ilosc stringow do stworzenia
 * Generuje losowe stringi na podstawie czasu maszyny
 */
static std::string *generateStrings(int ileStringow);



using DataFrame::operator=;
 ~NumberGenerator() {}
};

#endif /* NUMBERGENERATOR_H_ */
