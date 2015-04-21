/*
 * dictionary.h
 *
 *  Created on: Apr 9, 2015
 *      Author: serek8
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_
#define LICZBA_ZNAKOW_DO_HASHU 5

#include <string>
#include <iostream>
#include "mylist.h"
#include "numbergenerator.h"
using namespace std;

/**
 * @brief Klasa tworzy tablicy asocjacyjną - słownik
 *
 * Tworzy tablice asocjacyjną, na podstawie kluczba podanego przez operator []
 * Gdy element o danym kluczu nie istnieje, a użytkownik próbuje sie do niego odwołać
 * to dany element jest tworzony i dodawany do tablicy
 */
class Dictionary
{
	/**
	 * @brief Tablica list
	 */
	MyList *kolumnaList;

public:
	/**
	 * @brief Konstruktor tworzacy kolumneList
	 * Tworze 367 miejsc bo mam tylko trzy pierwsze znaki uzywane przy hashowaniu
	 */
	Dictionary() {	kolumnaList = new MyList[ LICZBA_ZNAKOW_DO_HASHU * MAX_HEX_ASCII_KOD+1]; }

	/**
	 * @brief Funkcja hashująca trzy pierwsze znaki
	 * @param str Obiekt string do zhashowania
	 */
	static int str2int(string str);
	/**
	 * @brief Funkcja hashująca wszystkie  znaki
	 * @param str Obiekt string do zhashowania
	 */
	static int str2intAll(string str);
	/**
	 * @brief Operator pozwalajacy odnosic sie do slownika
	 * Gdy element o danym kluczu nie istnieje, a użytkownik próbuje sie do niego odwołać
	 * to dany element jest tworzony i dodawany do tablicy
	 *
	 * @param str Klucz elementu do odwolania
	 */
	int &operator[](string str);
	static int alfabetyczneSprawdzanieKolejnosci(string str_1, string str_2);
};






#endif /* DICTIONARY_H_ */
