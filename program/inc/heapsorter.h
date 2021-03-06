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
template <class ContentType>
class HeapSorter: public Sorter<ContentType>
{
public:
	/// Skopiowana lista do przeprowadzania sortowania
	List<ContentType> &list;

	/** @brief Konstruktor
	 *  @param &myList lista, która konstruktor kopiuje aby nie naruszać podanej przez uzytkownika
	 */
	HeapSorter(List<ContentType> &myList)
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

	/** @brief Sortuje przez kopcowanie
	 */
	List<ContentType> &sort()
	{
		int n = this->list.size();
	    int parent = n/2, index, child, tmp; /* heap indexes */
	    /* czekam az sie posortuje */
	    while (1) {
	        if (parent > 0)
	        {
	            tmp = (this->list)[--parent];  /* kobie kopie do tmp */
	        }
	        else {
	            n--;
	            if (n == 0)
	            {
	                return this->list; /* Zwraca posortowane */
	            }
	            tmp = this->list[n];
	            //int tmp = this->list[0];
	            this->list[n] = this->list[0];
	        }
	        index = parent;
	        child = index * 2 + 1;
	        while (child < n) {
	            if (child + 1 < n  &&  this->list[child + 1] > this->list[child]) {
	                child++;
	            }
	            if (this->list[child] > tmp) {
	                this->list[index] = this->list[child];
	                index = child;
	                child = index * 2 + 1;
	            } else {
	                break;
	            }
	        }
	        this->list[index] = tmp;
	    }
	    return this->list;
	}



};


#endif /* HEAPSORTER_H_ */
