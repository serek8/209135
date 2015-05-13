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
#include "mylistelement.h"
#include "observer.h"
#include "list.h"
#include "listelement.h"
/**
 * @brief Lista dwukierunkowa
 *
 * Klasa przedstawia liste dwukierunkową dynamiczna
 */
template <typename MyListElementType>
class MyList : public List<MyListElementType>{

public:
	/// liczba elementow listy
	int sizeOfList;


	///  wskaznik do 'malej struktury' ktora jest pierwsza na liscie
	MyListElement<MyListElementType> *firstElement;
	///  wskaznik do 'malej struktury' ktora jest ostatnia na liscie
	MyListElement<MyListElementType> *lastElement;
	MyListElement<MyListElementType> *iterator;
	int iteratorElementId; // nie ruszac !
	int isIteratorAfterPop;
	///  Konstruktor listy

	MyList()
	{
		firstElement = lastElement = new MyListElement<MyListElementType>;
		sizeOfList = 0;
		iteratorElementId =0;
		iterator=NULL;
		isIteratorAfterPop = 1; //to znaczy ze jeszcze raz trzeba bedzie sprawdzic pozycje iteratora 1- znaczy ze trzeba sprawdzic
	}

	MyList(List<MyListElementType> &list)
	{
		firstElement = lastElement = new MyListElement<MyListElementType>;
		sizeOfList = 0;
		iteratorElementId =0;
		iterator=NULL;
		isIteratorAfterPop = 1; //to znaczy ze jeszcze raz trzeba bedzie sprawdzic pozycje iteratora 1- znaczy ze trzeba sprawdzic
		for(int i=0; i<list.size(); i++)
		{
			this->push_back(list[i]);
		}
	}
	virtual ~MyList(){};

	/**
	 * @brief Zwraca ilosc elementow listy
	 * @return ilosc elementow tablicy
	 */
	int &size()
	{
		return sizeOfList;
	}
	/**
	 * @brief Zwraca element ostatni w liscie
	 * @return Zwraca element ostatni w liscie
	 */
	/*MyListElement<MyListElementType> &pop_back()
	{
		if(!(sizeOfList--)) { sizeOfList=0; return (*(new MyListElement<MyListElementType>)); }
		MyListElement<MyListElementType> tmpNumber = *(this -> lastElement);
		MyListElement<MyListElementType> *originMyListElement = this -> lastElement;
		this -> lastElement = this -> lastElement -> previousElement;
		delete originMyListElement;
		isIteratorAfterPop=1;
		return tmpNumber;
	}*/
	ListElement<MyListElementType> pop_back()
	{
		if(!(sizeOfList--)) { sizeOfList=0; return (*(new MyListElement<MyListElementType>)); }
		MyListElement<MyListElementType> tmpNumber = *(this -> lastElement);
		MyListElement<MyListElementType> *originMyListElement = this -> lastElement;
		this -> lastElement = this -> lastElement -> previousElement;
		delete originMyListElement;
		isIteratorAfterPop=1;
		return tmpNumber;
	}
	/**
	 * @brief Zwraca element pierwszy w liscie
	 * @return Zwraca element pierwszy w liscie
	 */
	ListElement<MyListElementType> pop_front()
	{
		if(!(sizeOfList--)) { sizeOfList=0; return (*(new MyListElement<MyListElementType>())); }
		MyListElement<MyListElementType> tmpNumber = *(this -> firstElement);
		MyListElement<MyListElementType> *originMyListElement = this -> firstElement;
		this -> firstElement = this -> firstElement -> nextElement;

		delete originMyListElement;
		isIteratorAfterPop=1;
		return tmpNumber;
	}
	/**
	 * @brief Wklada element na ostatnie miejsce na liscie
	 */
	void push_back(MyListElementType arg)
	{
		//std::cerr<<"\n(push_back): arg.content="<<arg.content;
		MyListElement<MyListElementType> *newMyListElement = new MyListElement<MyListElementType>(arg);
		if(!sizeOfList++) {firstElement = lastElement = newMyListElement;}
		//newMyListElement -> nextElement = 0;
		newMyListElement -> previousElement = this -> lastElement;
		this -> lastElement -> nextElement = newMyListElement;
		this->lastElement = newMyListElement;
	}
	/**
	 * @brief Wklada element na pierwsze miejsce na liscie
	 */
	void push_front(MyListElementType arg)
	{
		MyListElement<MyListElementType> *newMyListElement = new MyListElement<MyListElementType>(arg);
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
	MyListElement<MyListElementType> &show_front()
	{
		return *firstElement;
	}
	/**
	 * @brief Pokazuje element po koncu listy
	 * @return zwraca kopie tego elementu
	 */
	MyListElement<MyListElementType> &show_back()
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
		MyListElement<MyListElementType> el;
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
		MyListElement<MyListElementType> *elem = (this->firstElement);
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
	MyListElement<MyListElementType> &operator[](int numberOfElement)
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
			iteratorElementId = 0;
			for (; iteratorElementId< numberOfElement ; iteratorElementId++)
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
	void insertAfter(MyListElement<MyListElementType> arg, int iteratorID)
	{
		if(iteratorID==0 && this->sizeOfList==0)  {push_front(arg.content); return;}
		if(iteratorID==this->sizeOfList-1)  {push_back(arg.content); return;}
		MyListElement<MyListElementType> *newMyListElement = new MyListElement<MyListElementType>(arg);
		MyListElement<MyListElementType> &tmpThis=(*this)[iteratorID], &tmpNext=(*this)[iteratorID+1];
		if(!sizeOfList++) {firstElement = lastElement = newMyListElement;}
		newMyListElement -> nextElement = tmpThis.nextElement;
		newMyListElement -> previousElement = &tmpThis;
		tmpThis.nextElement = newMyListElement;
		tmpNext.previousElement = newMyListElement;
		isIteratorAfterPop=1;
	}


	//MyListElement operator[](int numberOfElement);
	//virtual MyList<MyListElementType> sort()
	//{
	//	std::cerr<<"\nError: Sortowanie z klasy MyList !!!";
	//	//return m;
	//}

	MyList<MyListElementType> &operator=(const MyList<MyListElementType> &pattern)
	{
		this->sizeOfList = pattern.sizeOfList;
		this->firstElement = pattern.firstElement;
		this->lastElement = pattern.lastElement;
		this->iterator=pattern.iterator;
		this->isIteratorAfterPop = pattern.isIteratorAfterPop;
		return *this;
	}

/*	void cloneFrom(MyList<MyListElementType> patternList)
	{
		MyList<MyListElementType> &clonedList = *new MyList<MyListElementType>;
		// release memory from main list
		while(this->size()) pop_back();
		for(int i=0; i<patternList.size(); i++)
			clonedList.push_back(patternList[i]);
		*this = clonedList;
	}
*/

	List<MyListElementType> &createObjectFromAbstractReference(/*MyList<MyListElementType> abstractPattern*/)
	{
		return *new MyList<MyListElementType>;
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
