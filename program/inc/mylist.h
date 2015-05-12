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
#include "observer.h"
/**
 * @brief Lista dwukierunkowa
 *
 * Klasa przedstawia liste dwukierunkową dynamiczna
 */
template <typename MyListElementType>
class MyList{

public:
	/// liczba elementow listy
	int sizeOfList;
public:
	/// @brief Klasa 'malych struktur' gdzie jest numer i wskaznik do nas elementu
	class MyListElement {
		///  Liczba przechowywana
	public:
		MyListElementType content;
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
		friend class MyList;
	};

	///  wskaznik do 'malej struktury' ktora jest pierwsza na liscie
	MyListElement *firstElement;
	///  wskaznik do 'malej struktury' ktora jest ostatnia na liscie
	MyListElement *lastElement;
	///  Konstruktor listy
public:
	MyList()
	{
		firstElement = lastElement = new MyListElement();
		sizeOfList = 0;
		iteratorElementId =0;
		iterator=NULL;
		isIteratorAfterPop = 1; //to znaczy ze jeszcze raz trzeba bedzie sprawdzic pozycje iteratora 1- znaczy ze trzeba sprawdzic
	}
	virtual ~MyList(){};
	MyListElement *iterator;
	int iteratorElementId; // nie ruszac !
	int isIteratorAfterPop;
	/**
	 * @brief Zwraca ilosc elementow listy
	 * @return ilosc elementow tablicy
	 */
	int size()
	{
		return sizeOfList;
	}
	/**
	 * @brief Zwraca element ostatni w liscie
	 * @return Zwraca element ostatni w liscie
	 */
	MyListElement pop_back()
	{
		if(!(sizeOfList--)) { sizeOfList=0; return (*(new MyListElement())); }
		MyListElement tmpNumber = *(this -> lastElement);
		MyListElement *originMyListElement = this -> lastElement;
		this -> lastElement = this -> lastElement -> previousElement;
		delete originMyListElement;
		isIteratorAfterPop=1;
		return tmpNumber;
	}
	/**
	 * @brief Zwraca element pierwszy w liscie
	 * @return Zwraca element pierwszy w liscie
	 */
	MyListElement pop_front()
	{
		if(!(sizeOfList--)) { sizeOfList=0; return (*(new MyListElement())); }
		MyListElement tmpNumber = *(this -> firstElement);
		MyListElement *originMyListElement = this -> firstElement;
		this -> firstElement = this -> firstElement -> nextElement;

		delete originMyListElement;
		isIteratorAfterPop=1;
		return tmpNumber;
	}
	/**
	 * @brief Wklada element na ostatnie miejsce na liscie
	 */
	void push_back(MyListElement arg)
	{
		//std::cerr<<"\n(push_back): arg.content="<<arg.content;
		MyListElement *newMyListElement = new MyListElement(arg);
		if(!sizeOfList++) {firstElement = lastElement = newMyListElement;}
		//newMyListElement -> nextElement = 0;
		newMyListElement -> previousElement = this -> lastElement;
		this -> lastElement -> nextElement = newMyListElement;
		this->lastElement = newMyListElement;
	}
	/**
	 * @brief Wklada element na pierwsze miejsce na liscie
	 */
	void push_front(MyListElement arg)
	{
		MyListElement *newMyListElement = new MyListElement(arg);
		if(!sizeOfList++) {firstElement = lastElement = newMyListElement;}
		//newMyListElement -> previousElement =  0;
		newMyListElement -> nextElement = this -> firstElement;
		this -> firstElement -> previousElement = newMyListElement;
		this->firstElement = newMyListElement;
		++iteratorElementId;
	}
	/**
	 * @brief Pokazuje element po poczatku listy
	 * @return zwraca kopie tego elementu
	 */
	MyListElement &show_front()
	{
		return *firstElement;
	}
	/**
	 * @brief Pokazuje element po koncu listy
	 * @return zwraca kopie tego elementu
	 */
	MyListElement &show_back()
	{
		return *lastElement;
	}
	/**
	 * @brief Zapisuje liste do pliku
	 * @return Zwraca 0 gdy zapisywanie powiodlo sie
	 */
	int saveDataToFile()
	{
		std::ofstream streamToFile;
		streamToFile.open ("myList.log", std::ofstream::out);
		MyListElement el;
		for(int i=0; i<sizeOfList ; i++) {
			el = pop_front();
			streamToFile << '{'<<el.content<<"} ";
		}
		return 0;
	}

	/**
	 * @brief Wyswietla elementy listy
	 */
	void  printList()
	{
		MyList::MyListElement *elem = (this->firstElement);
		std::cout<<"\nWyswietlam liste (size:"<<this->sizeOfList<<"): ";
		for(int i=0; i< this->sizeOfList; i++)
		{
			std::cout<<" "<<elem->content;
			elem = elem->nextElement;
		}
	}

	/**
	 * @brief Pobiera element z listy
	 * @return Zwraca 0 gdy zapisywanie powiodlo sie
	 */
	MyListElement &operator[](int numberOfElement)
	{
		//std::cerr<<"\nJestem w ["<<numberOfElement<<"] iterator="<<iteratorElementId;
		if(numberOfElement > (sizeOfList-1)) // jezeli wyszedlem poza liste
			{
				std::cerr<<"\n! Error indeks o numerze: "<<numberOfElement<<" nie istnieje !";
				return *iterator;
			}
		if(isIteratorAfterPop)
			{
				iteratorElementId=0;  // czyli iterator byl zpopowany
				iterator = firstElement;
				isIteratorAfterPop=0;
			}
		//std::cerr<<"\nsprawdzam w ["<<numberOfElement<<"] iterator="<<iteratorElementId;
		if((numberOfElement <= iteratorElementId-numberOfElement) &&(iteratorElementId-numberOfElement>=0))
		{
			//std::cerr<<"\nJestem w if_1";
			iterator = (this->firstElement);
			for (int i =0; i< numberOfElement ; i++)
				iterator = (iterator->nextElement);
		}
		else if(numberOfElement > iteratorElementId)
		{
			//std::cerr<<"\nJestem w if_2";
			for (; iteratorElementId< numberOfElement ; iteratorElementId++)
						iterator = (iterator->nextElement);
		}
		else if( numberOfElement < iteratorElementId)
		{
			//std::cerr<<"\nJestem w if_3";
			for (; iteratorElementId> numberOfElement ; iteratorElementId--)
						iterator = (iterator->previousElement);
		}
		return *iterator;
	}

	/**
	 * @brief Wsadza element po obiekcie iteratora
	 */
	void insertAfter(MyListElement arg, int iteratorID)
	{
		if(iteratorID==0 && this->sizeOfList==0)  {push_front(arg); return;}
		if(iteratorID==this->sizeOfList-1)  {push_back(arg); return;}
		MyListElement *newMyListElement = new MyListElement(arg);
		MyListElement &tmpThis=(*this)[iteratorID], &tmpNext=(*this)[iteratorID+1];
		if(!sizeOfList++) {firstElement = lastElement = newMyListElement;}
		newMyListElement -> nextElement = tmpThis.nextElement;
		newMyListElement -> previousElement = &tmpThis;
		tmpThis.nextElement = newMyListElement;
		tmpNext.previousElement = newMyListElement;
		isIteratorAfterPop=1;
	}


	//MyListElement operator[](int numberOfElement);
	virtual MyList sort(MyList m)
	{
		std::cerr<<"\nError: Sortowanie z klasy MyList !!!";
		return m;
	}

};
////////////

//////////////



/*class MyListObserved : public MyList, public Observed
{
public:
	void mergeSort(MyList m)
	{
	MyList::mergeSort(m);
	powiadom();

	}
	MyListObserved(){};
	~MyListObserved(){};


};*/

#endif /* MYLIST_H_ */
