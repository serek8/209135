/*
 * numbergenerator.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: serek8
 */
#include "numbergenerator.h"


/*std::string *NumberGenerator::generateStrings(int ileStringow){
	std::string *tablicaStringow = new std::string[ileStringow];
	NumberGenerator liczby;

	liczby.sizeOfTable = 1; // bede generowac tylko jedna liczbe

	int i, j, k;
	for(i=0 ; i<ileStringow ; i++)
	{
		// generuje jedna liczbe z zakresu od 0 do 12, która mowi nam ile ma byc w tekscie znakow
		liczby.generateNumbers(ROZMIAR_STRINGU);
		while(liczby.tableOfData[0]<2) liczby.generateNumbers(ROZMIAR_STRINGU);
		k = liczby.tableOfData[0];
		for(j=0; j<k ; j++)
		{
			liczby.generateNumbers(MAX_HEX_ASCII_KOD);
			while(liczby.tableOfData[0]<48) liczby.generateNumbers(MAX_HEX_ASCII_KOD);
			tablicaStringow[i] += (char)liczby.tableOfData[0];

		}

	}

	return tablicaStringow;
}*/
