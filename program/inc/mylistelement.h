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
template <class ContentType>
class MyListElement : public ListElement<ContentType>{
	///  Liczba przechowywana
public:
	//ContentType content;
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
	 */
	MyListElement(ContentType arg)
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
	/**@brief Ustawia liczbe oraz klucz slowanika dla elementu
	 * @param arg Liczba do zapisania
	 */
	void set(ContentType arg)
	{
		this -> content = arg;
		//this -> nazwa = str;
	}
	//friend class MyList;
};
#endif /* MYLISTELEMENT_H_ */
