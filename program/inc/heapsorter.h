/*
 * heapsorter.h
 *
 *  Created on: May 12, 2015
 *      Author: serek8
 */

#ifndef HEAPSORTER_H_
#define HEAPSORTER_H_


#include "sorter.h"
#include "list.h"

/// @brief Klasa sluzaca do obslugi sortowania przez kopcowanie
template <class MyListElementType>
class HeapSorter: public Sorter<MyListElementType>
{
public:
	/// Skopiowana lista do przeprowadzania sortowania
	List<MyListElementType> &list;

	/** @brief Konstruktor
	 *  @param &myList lista, która konstruktor kopiuje aby nie naruszać podanej przez uzytkownika
	 */
	HeapSorter(List<MyListElementType> &myList)
	:list(myList.createObjectFromAbstractReference())

	{
		this->list.cloneFrom(myList);
		/*this->sizeOfList = myList.sizeOfList;
		this->firstElement = myList.firstElement;
		this->lastElement = myList.lastElement;
		this->iterator=myList.iterator;
		this->isIteratorAfterPop = myList.isIteratorAfterPop;*/
	}

	virtual ~HeapSorter(){};

	/** @breif Sortuje przez kopcowanie
	 */
	List<MyListElementType> &sort()
	{
		int n = this->list.size();
	    int parent = n/2, index, child, tmp; /* heap indexes */
	    /* czekam az sie posortuje */
	    while (1) {
	        if (parent > 0)
	        {
	            tmp = (this->list)[--parent].content;  /* kobie kopie do tmp */
	        }
	        else {
	            n--;
	            if (n == 0)
	            {
	                return this->list; /* Zwraca posortowane */
	            }
	            tmp = this->list[n].content;
	            this->list[n].content = this->list[0].content;
	        }
	        index = parent;
	        child = index * 2 + 1;
	        while (child < n) {
	            if (child + 1 < n  &&  this->list[child + 1].content > this->list[child].content) {
	                child++;
	            }
	            if (this->list[child].content > tmp) {
	                this->list[index].content = this->list[child].content;
	                index = child;
	                child = index * 2 + 1;
	            } else {
	                break;
	            }
	        }
	        this->list[index].content = tmp;
	    }
	    return this->list;
	}



};


#endif /* HEAPSORTER_H_ */
