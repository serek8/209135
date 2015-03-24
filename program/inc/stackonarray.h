/*
 * stackonarray.h
 *
 *  Created on: Mar 19, 2015
 *      Author: serek8
 */

#ifndef STACKONARRAY_H_
#define STACKONARRAY_H_

/**
 * Klasa przedstawia stos stworzony na tablicy dynamicznej.
 * Powiekszanie tablicy przeprowadza sie albo o jeden element albo o polowe dotychczasowego rozmiatu
 *
 */
class StackOnArray
{
public:
	/// rozmiar tablicy
	int sizeOfTable;
	/// index zawsze pokazuje na pozycje poprzedzającą ostatni dodany element
	int index;
	/// wskaznik do tablicy w ktorej przechowuje liczby
	int *tableOfData;

public:
/**
 * Konstruktor tablicy
 */
	StackOnArray();
	/**
	 * @brief Dodaje do stosu kolejny element
	 * 
	 * Gdy brakuje w tablicy stosu miejsca alokuje nową większą o jeden i kopiuje tam dane
	 */
	void pushByOneAlloc(int arg);
	
	/**
	 *  @brief Dodaje do stosu kolejny element
	 * Gdy brakuje w tablicy stosu miejsca alokuje nową większą o 2 razy i kopiuje tam dane
	 */
	void pushByDoubleAlloc(int arg);
	/**
	 *  @brief Pobiera jeden element ze stosu
	 */
	int pop();
	~StackOnArray();
};


#endif /* STACKONARRAY_H_ */
