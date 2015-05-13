/*
 * heapsorter.h
 *
 *  Created on: May 12, 2015
 *      Author: serek8
 */

#ifndef HEAPSORTER_H_
#define HEAPSORTER_H_


#include "sorter.h"

template <typename MyListElementType>
class HeapSorter: public Sorter<MyListElementType>
{
public:
	HeapSorter(MyList<MyListElementType> &myList)
	{
		this->cloneFrom(myList);
		/*this->sizeOfList = myList.sizeOfList;
		this->firstElement = myList.firstElement;
		this->lastElement = myList.lastElement;
		this->iterator=myList.iterator;
		this->isIteratorAfterPop = myList.isIteratorAfterPop;*/
	}

	virtual ~HeapSorter(){};

	MyList<MyListElementType> sort()
	{
		int n = this->sizeOfList;
	    int parent = n/2, index, child, tmp; /* heap indexes */
	    /* czekam az sie posortuje */
	    while (1) {
	        if (parent > 0)
	        {
	            tmp = (*this)[--parent].content;  /* kobie kopie do tmp */
	        }
	        else {
	            n--;
	            if (n == 0)
	            {
	                return *this; /* Zwraca posortowane */
	            }
	            tmp = (*this)[n].content;
	            (*this)[n].content = (*this)[0].content;
	        }
	        index = parent;
	        child = index * 2 + 1;
	        while (child < n) {
	            if (child + 1 < n  &&  (*this)[child + 1].content > (*this)[child].content) {
	                child++;
	            }
	            if ((*this)[child].content > tmp) {
	                (*this)[index].content = (*this)[child].content;
	                index = child;
	                child = index * 2 + 1;
	            } else {
	                break;
	            }
	        }
	        (*this)[index].content = tmp;
	    }
	    return *this;
	}



};


#endif /* HEAPSORTER_H_ */
