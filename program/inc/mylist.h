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
#include "mylistelement.h"
#include "observer.h"
#include "list.h"
#include "listelement.h"
/**
 * @brief Lista dwukierunkowa
 *
 * Klasa przedstawia liste dwukierunkową dynamiczna
 */
template <class ContentType>
class MyList : public List<ContentType>{

public:
	/// liczba elementow listy
	int sizeOfList;


	///  wskaznik do 'malej struktury' ktora jest pierwsza na liscie
	MyListElement<ContentType> *firstElement;
	///  wskaznik do 'malej struktury' ktora jest ostatnia na liscie
	MyListElement<ContentType> *lastElement;
	MyListElement<ContentType> *iterator;
	int iteratorElementId; // nie ruszac !
	int isIteratorAfterPop;
	///  Konstruktor listy

	MyList()
	{
		firstElement = lastElement = new MyListElement<ContentType>;
		sizeOfList = 0;
		iteratorElementId =0;
		iterator=NULL;
		isIteratorAfterPop = 1; //to znaczy ze jeszcze raz trzeba bedzie sprawdzic pozycje iteratora 1- znaczy ze trzeba sprawdzic
	}

	MyList(List<ContentType> &list)
	{
		firstElement = lastElement = new MyListElement<ContentType>;
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
	/*MyListElement<ContentType> &pop_back()
	{
		if(!(sizeOfList--)) { sizeOfList=0; return (*(new MyListElement<ContentType>)); }
		MyListElement<ContentType> tmpNumber = *(this -> lastElement);
		MyListElement<ContentType> *originMyListElement = this -> lastElement;
		this -> lastElement = this -> lastElement -> previousElement;
		delete originMyListElement;
		isIteratorAfterPop=1;
		return tmpNumber;
	}*/
	ListElement<ContentType> pop_back()
	{
		if(!(sizeOfList--)) { sizeOfList=0; return (*(new MyListElement<ContentType>)); }
		MyListElement<ContentType> tmpNumber = *(this -> lastElement);
		MyListElement<ContentType> *originMyListElement = this -> lastElement;
		this -> lastElement = this -> lastElement -> previousElement;
		delete originMyListElement;
		isIteratorAfterPop=1;
		return tmpNumber;
	}
	/**
	 * @brief Zwraca element pierwszy w liscie
	 * @return Zwraca element pierwszy w liscie
	 */
	ListElement<ContentType> pop_front()
	{
		if(!(sizeOfList--)) { sizeOfList=0; return (*(new MyListElement<ContentType>())); }
		MyListElement<ContentType> tmpNumber = *(this -> firstElement);
		MyListElement<ContentType> *originMyListElement = this -> firstElement;
		this -> firstElement = this -> firstElement -> nextElement;

		delete originMyListElement;
		isIteratorAfterPop=1;
		return tmpNumber;
	}
	/**
	 * @brief Wklada element na ostatnie miejsce na liscie
	 */
	void push_back(ContentType arg)
	{
		//std::cerr<<"\n(push_back): arg.content="<<arg.content;
		MyListElement<ContentType> *newMyListElement = new MyListElement<ContentType>(arg);
		if(!sizeOfList++) {firstElement = lastElement = newMyListElement;}
		//newMyListElement -> nextElement = 0;
		newMyListElement -> previousElement = this -> lastElement;
		this -> lastElement -> nextElement = newMyListElement;
		this->lastElement = newMyListElement;
	}
	/**
	 * @brief Wklada element na pierwsze miejsce na liscie
	 */
	void push_front(ContentType arg)
	{
		MyListElement<ContentType> *newMyListElement = new MyListElement<ContentType>(arg);
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
	void  printList()
	{
		MyListElement<ContentType> *elem = (this->firstElement);
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
	MyListElement<ContentType> &operator[](int numberOfElement)
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
	void insertAfter(MyListElement<ContentType> arg, int iteratorID)
	{
		if(iteratorID==0 && this->sizeOfList==0)  {push_front(arg.content); return;}
		if(iteratorID==this->sizeOfList-1)  {push_back(arg.content); return;}
		MyListElement<ContentType> *newMyListElement = new MyListElement<ContentType>(arg);
		MyListElement<ContentType> &tmpThis=(*this)[iteratorID], &tmpNext=(*this)[iteratorID+1];
		if(!sizeOfList++) {firstElement = lastElement = newMyListElement;}
		newMyListElement -> nextElement = tmpThis.nextElement;
		newMyListElement -> previousElement = &tmpThis;
		tmpThis.nextElement = newMyListElement;
		tmpNext.previousElement = newMyListElement;
		isIteratorAfterPop=1;
	}


	//MyListElement operator[](int numberOfElement);
	//virtual MyList<ContentType> sort()
	//{
	//	std::cerr<<"\nError: Sortowanie z klasy MyList !!!";
	//	//return m;
	//}

	MyList<ContentType> &operator=(const MyList<ContentType> &pattern)
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

/*	void cloneFrom(MyList<ContentType> patternList)
	{
		MyList<ContentType> &clonedList = *new MyList<ContentType>;
		// release memory from main list
		while(this->size()) pop_back();
		for(int i=0; i<patternList.size(); i++)
			clonedList.push_back(patternList[i]);
		*this = clonedList;
	}
*/

	List<ContentType> &createObjectFromAbstractReference(/*MyList<ContentType> abstractPattern*/)
	{
		return *new MyList<ContentType>;
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
