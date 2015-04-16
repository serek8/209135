/*
 * mylist.h
 *
 *  Created on: Mar 12, 2015
 *      Author: serek8
 */

#ifndef MYLIST_H_
#define MYLIST_H_

#include <iostream>
#include <string>
#include <fstream>
/**
 * @brief Lista dwukierunkowa
 *
 * Klasa przedstawia liste dwukierunkową dynamiczna
 */
class MyList{

private:
	/// liczba elementow listy
	int sizeOfList;
public:
	/// @brief Klasa 'malych struktur' gdzie jest numer i wskaznik do nas elementu
	class MyListElement {
		///  Liczba przechowywana
	public:
		int  number;
		std::string nazwa;
		///  wskaznik do nastepnej 'malej struktury' w liscie
		MyListElement *nextElement;
		///  wskaznik do poprzedniej 'malej struktury' w liscie
		MyListElement *previousElement;
	public:
		/**
		 * @brief Konstruktor wewnetrznej klasy 'malych struktur'
		 */
		MyListElement();
		/**
		 * @brief Konstruktor wewnetrznej klasy 'malych struktur'
		 * @param arg liczba do zapisania w kolejnym elemencie listy
		 * @param str klucz tablicy asocjacyjnej
		 */
		MyListElement(int arg, std::string str);
		/**
		 * @brief Konstruktor kopiujacy wewnetrznej klasy 'malych struktur'
		 * @param myListElement Element o przekopiowania
		 */
		MyListElement(const MyListElement &myListElement);
		/**
		 * @brief Ustawia liczbe oraz klucz slowanika dla elementu
		 * @param arg Liczba do zapisania
		 * @param str String do zapisania
		 */
		MyListElement(int arg);
		void set(int arg, std::string str);
		friend class MyList;
	};

	///  wskaznik do 'malej struktury' ktora jest pierwsza na liscie
	MyListElement *firstElement;
	///  wskaznik do 'malej struktury' ktora jest ostatnia na liscie
	MyListElement *lastElement;
	///  Konstruktor listy
public:
	MyList();


	/**
	 * @brief Zwraca ilosc elementow listy
	 * @return ilosc elementow tablicy
	 */
	int size();
	/**
	 * @brief Zwraca element ostatni w liscie
	 * @return Zwraca element ostatni w liscie
	 */
	MyListElement pop_back();
	/**
	 * @brief Zwraca element pierwszy w liscie
	 * @return Zwraca element pierwszy w liscie
	 */
	MyListElement pop_front();
	/**
	 * @brief Wklada element na ostatnie miejsce na liscie
	 */
	void push_back(MyListElement arg);
	/**
	 * @brief Wklada element na pierwsze miejsce na liscie
	 */
	void push_front(MyListElement arg);
	/**
	 * @brief Pokazuje element po poczatku listy
	 * @return zwraca kopie tego elementu
	 */
	MyListElement &show_front();
	/**
	 * @brief Pokazuje element po koncu listy
	 * @return zwraca kopie tego elementu
	 */
	MyListElement &show_back();

	int saveDataToFile();
	void scalanieSort(MyList lista);
	int splitList(MyList &tmpLista1, MyList &tmpLista2);
	void  printList();
	MyList mergeLists(MyList a, MyList b);
	void mergeSort();
};



#endif /* MYLIST_H_ */
