/*
 * mylistelement.h
 *
 *  Created on: May 11, 2015
 *      Author: serek8
 */

#ifndef LINKEDLISTELEMENT_H_
#define LINKEDLISTELEMENT_H_

#include "linkedlist.h"

/// @brief Klasa 'malych struktur' gdzie jest numer i wskaznik do nas elementu
template <class ContentType>
class LinkedListElement{
	///  Liczba przechowywana
public:
	//ContentType content;
	///  wskaznik do nastepnej 'malej struktury' w liscie
	LinkedListElement *nextElement;
	///  wskaznik do poprzedniej 'malej struktury' w liscie
	LinkedListElement *previousElement;
	ContentType content;
		/**
	 * @brief Konstruktor wewnetrznej klasy 'malych struktur'
	 */
	LinkedListElement()
	{
		this -> nextElement =0;
		this -> previousElement =0;
	}
	/**
	 * @brief Konstruktor wewnetrznej klasy 'malych struktur'
	 * @param arg liczba do zapisania w kolejnym elemencie listy
	 */
	LinkedListElement(ContentType &arg)
	{
		this -> content = arg;
		this -> nextElement =0;
		this -> previousElement =0;
		//std::cerr<<"\n(konstruktor LinkedListElement): content="<<arg;
	}
	/**
	 * @brief Konstruktor kopiujacy wewnetrznej klasy 'malych struktur'
	 * @param linkedListElement Element o przekopiowania
	 */
	LinkedListElement(const LinkedListElement &linkedListElement)
	{
		this->content = linkedListElement.content;
		this->nextElement = linkedListElement.nextElement;
		this->previousElement = linkedListElement.previousElement;
		//std::cerr<<"\n(konstruktor kopiujacy LinkedListElement): content="<<content;
	}
	/**@brief Ustawia liczbe oraz klucz slowanika dla elementu
	 * @param arg Liczba do zapisania
	 */
	void set(ContentType arg)
	{
		this -> content = arg;
	}
	//friend class LinkedList;
};
#endif /* LINKEDLISTELEMENT_H_ */
