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
#include "linkedlist.h"
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

class NumberGenerator
{
public:
/**@brief Generuje losowe liczby
 */
template <typename ContentType>
LinkedList<ContentType> static &generateNumbers(int range, int quantity)
{
	LinkedList<ContentType> &myList = *new LinkedList<ContentType>();
	time_t randomTime = clock();
	int randomNumber;
	for(int i=0; i<quantity ; i++)
	{
		srand (randomTime = clock());
		randomNumber = rand()%range;
		myList.push_back(randomNumber);
		randomTime = clock();
	}
	return myList;
}

/**
 * @brief Generuje losowe stringi
 *
 * @param ileStringow Ilosc stringow do stworzenia
 * Generuje losowe stringi na podstawie czasu maszyny
 */
static std::string *generateStrings(int ileStringow);



//using DataFrame::operator=;

};

#endif /* NUMBERGENERATOR_H_ */
