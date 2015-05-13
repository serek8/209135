/*
 * mylistelement.h
 *
 *  Created on: May 11, 2015
 *      Author: serek8
 */

#ifndef MYLISTELEMENT_H_
#define MYLISTELEMENT_H_

#include "mylist.h"
#include "listelement.h"

/// @brief Klasa 'malych struktur' gdzie jest numer i wskaznik do nas elementu
template <typename MyListElementType>
class MyListElement : public ListElement<MyListElementType>{
	///  Liczba przechowywana
public:
	//MyListElementType content;
	///  wskaznik do nastepnej 'malej struktury' w liscie
	MyListElement *nextElement;
	///  wskaznik do poprzedniej 'malej struktury' w liscie
	MyListElement *previousElement;
public:
		/**
	 * @brief Konstruktor wewnetrznej klasy 'malych struktur'
	 */
	MyListElement()
	{
		this -> nextElement =0;
		this -> previousElement =0;
	}
	/**
	 * @brief Konstruktor wewnetrznej klasy 'malych struktur'
	 * @param arg liczba do zapisania w kolejnym elemencie listy
	 * @param str klucz tablicy asocjacyjnej
	 */
	MyListElement(MyListElementType arg)
	{
		this -> content = arg;
		this -> nextElement =0;
		this -> previousElement =0;
		//std::cerr<<"\n(konstruktor MyListElement): content="<<arg;
	}
	/**
	 * @brief Konstruktor kopiujacy wewnetrznej klasy 'malych struktur'
	 * @param myListElement Element o przekopiowania
	 */
	MyListElement(const MyListElement &myListElement)
	{
		//this->number = myListElement.number;
		//this->nazwa = myListElement.nazwa;
		this->content = myListElement.content;
		this->nextElement = myListElement.nextElement;
		this->previousElement = myListElement.previousElement;
		//std::cerr<<"\n(konstruktor kopiujacy MyListElement): content="<<content;
	}
	/**
	 * @brief Ustawia liczbe oraz klucz slowanika dla elementu
	 * @param arg Liczba do zapisania
	 * @param str String do zapisania
	 */
	void set(MyListElementType arg)
	{
		this -> content = arg;
		//this -> nazwa = str;
	}
	//friend class MyList;
};
#endif /* MYLISTELEMENT_H_ */
