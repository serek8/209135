/*
 * mylist.h
 *
 *  Created on: Mar 12, 2015
 *      Author: serek8
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <string>
#include "linkedlistelement.h"
#include "observer.h"
#include "list.h"
/**
 * @brief Lista dwukierunkowa
 *
 * Klasa przedstawia liste dwukierunkową dynamiczna
 */
template <class ContentType>
class LinkedList : public List<ContentType>{

public:
	/// liczba elementow listy
	int sizeOfList;


	///  wskaznik do 'malej struktury' ktora jest pierwsza na liscie
	LinkedListElement<ContentType> *firstElement;
	///  wskaznik do 'malej struktury' ktora jest ostatnia na liscie
	LinkedListElement<ContentType> *lastElement;
	LinkedListElement<ContentType> *iterator;
	int iteratorElementId; // nie ruszac !
	int isIteratorAfterPop;
	///  Konstruktor listy

	LinkedList()
	{
		firstElement = lastElement = new LinkedListElement<ContentType>;
		sizeOfList = 0;
		iteratorElementId =0;
		iterator=NULL;
		isIteratorAfterPop = 1; //to znaczy ze jeszcze raz trzeba bedzie sprawdzic pozycje iteratora 1- znaczy ze trzeba sprawdzic
	}

	LinkedList(List<ContentType> &list)
	{
		firstElement = lastElement = new LinkedListElement<ContentType>;
		sizeOfList = 0;
		iteratorElementId =0;
		iterator=NULL;
		isIteratorAfterPop = 1; //to znaczy ze jeszcze raz trzeba bedzie sprawdzic pozycje iteratora 1- znaczy ze trzeba sprawdzic
		for(int i=0; i<list.size(); i++)
		{
			this->push_back(list[i]);
		}
	}
	virtual ~LinkedList(){};

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
	ContentType pop_back()
	{
		if(!(sizeOfList--)) { sizeOfList=0; std::cerr<<"Nie ma takiego elementu\n"; return 0; }
		ContentType tmpNumber = (*(this -> lastElement)).content;
		LinkedListElement<ContentType> *originLinkedListElement = this -> lastElement;
		this -> lastElement = this -> lastElement -> previousElement;
		delete originLinkedListElement;
		isIteratorAfterPop=1;
		return tmpNumber;
	}
	/**
	 * @brief Zwraca element pierwszy w liscie
	 * @return Zwraca element pierwszy w liscie
	 */
	ContentType pop_front()
	{
		if(!(sizeOfList--)) { sizeOfList=0; std::cerr<<"Nie ma takiego elementu\n"; return 0; }
		ContentType tmpNumber = (*(this -> firstElement)).content;
		LinkedListElement<ContentType> *originLinkedListElement = this -> firstElement;
		this -> firstElement = this -> firstElement -> nextElement;
		delete originLinkedListElement;
		isIteratorAfterPop=1;
		return tmpNumber;
	}
	/**
	 * @brief Wklada element na ostatnie miejsce na liscie
	 */
	void push_back(ContentType &arg)
	{
		//std::cerr<<"\n(push_back): arg.content="<<arg.content;
		LinkedListElement<ContentType> *newLinkedListElement = new LinkedListElement<ContentType>(arg);
		if(!sizeOfList++) {firstElement = lastElement = newLinkedListElement;}
		//newLinkedListElement -> nextElement = 0;
		newLinkedListElement -> previousElement = this -> lastElement;
		this -> lastElement -> nextElement = newLinkedListElement;
		this->lastElement = newLinkedListElement;
	}
	/**
	 * @brief Wklada element na pierwsze miejsce na liscie
	 */
	void push_front(ContentType &arg)
	{
		LinkedListElement<ContentType> *newLinkedListElement = new LinkedListElement<ContentType>(arg);
		if(!sizeOfList++) {firstElement = lastElement = newLinkedListElement;}
		//newLinkedListElement -> previousElement =  0;
		newLinkedListElement -> nextElement = this -> firstElement;
		this -> firstElement -> previousElement = newLinkedListElement;
		this->firstElement = newLinkedListElement;
		++iteratorElementId;
	}
	/**
	 * @brief Pokazuje element po poczatku listy
	 * @return zwraca kopie tego elementu
	 */
	ContentType &show_front()
	{
		return firstElement->content;
	}
	/**
	 * @brief Pokazuje element po koncu listy
	 * @return zwraca kopie tego elementu
	 */
	ContentType &show_back()
	{
		return lastElement->content;
	}


	/**
	 * @brief Wyswietla elementy listy
	 */
	void  print()
	{
		LinkedListElement<ContentType> *elem = (this->firstElement);
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
	ContentType &operator[](int numberOfElement)
	{
		//std::cerr<<"\nJestem w ["<<numberOfElement<<"] iterator="<<iteratorElementId;
		if(numberOfElement > (sizeOfList-1)) // jezeli wyszedlem poza liste
			{
				std::cerr<<"\n! Error indeks o numerze: "<<numberOfElement<<" nie istnieje !";
				return (*iterator).content;
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
		return (*iterator).content;
	}

	LinkedListElement<ContentType> &getLinkedListElementById(int numberOfElement)
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
	void insertAfter(ContentType &arg, int iteratorID)
	{
		if(iteratorID==0 && this->sizeOfList==0)  {push_front(arg); return;}
		if(iteratorID==this->sizeOfList-1)  {push_back(arg); return;}
		LinkedListElement<ContentType> *newLinkedListElement = new LinkedListElement<ContentType>(arg);
		LinkedListElement<ContentType>
			&tmpThis=(*this).getLinkedListElementById(iteratorID),
			&tmpNext=(*this).getLinkedListElementById(iteratorID+1);
		if(!sizeOfList++) {firstElement = lastElement = newLinkedListElement;}
		newLinkedListElement -> nextElement = tmpThis.nextElement;
		newLinkedListElement -> previousElement = &tmpThis;
		tmpThis.nextElement = newLinkedListElement;
		tmpNext.previousElement = newLinkedListElement;
		isIteratorAfterPop=1;
	}


	//LinkedListElement operator[](int numberOfElement);
	//virtual LinkedList<ContentType> sort()
	//{
	//	std::cerr<<"\nError: Sortowanie z klasy LinkedList !!!";
	//	//return m;
	//}

	LinkedList<ContentType> &operator=(const LinkedList<ContentType> &pattern)
	{
		//std::cerr<<" @@@";
		this->sizeOfList = pattern.sizeOfList;
		this->firstElement = pattern.firstElement;
		this->lastElement = pattern.lastElement;
		this->iterator=pattern.iterator;
		this->isIteratorAfterPop = pattern.isIteratorAfterPop;
		return *this;
	}
//	List<ContentType> &operator=(const List<ContentType> &pattern)
//	{
//		std::cerr<<" ###";
////		this->sizeOfList = pattern.sizeOfList;
////		this->firstElement = pattern.firstElement;
////		this->lastElement = pattern.lastElement;
////		this->iterator=pattern.iterator;
////		this->isIteratorAfterPop = pattern.isIteratorAfterPop;
//		//this->cloneFrom(pattern);
//		return *this;
//	}

/*	void cloneFrom(LinkedList<ContentType> patternList)
	{
		LinkedList<ContentType> &clonedList = *new LinkedList<ContentType>;
		// release memory from main list
		while(this->size()) pop_back();
		for(int i=0; i<patternList.size(); i++)
			clonedList.push_back(patternList[i]);
		*this = clonedList;
	}
*/

	List<ContentType> &createObjectFromAbstractReference(/*LinkedList<ContentType> abstractPattern*/)
	{
		return *new LinkedList<ContentType>;
	}



};
////////////

//////////////



/*class LinkedListObserved : public LinkedList, public Observed
{
public:
	void mergeSort(LinkedList m)
	{
	LinkedList::mergeSort(m);
	powiadom();

	}
	LinkedListObserved(){};
	~LinkedListObserved(){};


};*/

#endif /* MYLIST_H_ */
