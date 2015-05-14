/*
 * observableheapsorter.h
 *
 *  Created on: May 14, 2015
 *      Author: serek8
 */

#ifndef OBSERVABLEHEAPSORTER_H_
#define OBSERVABLEHEAPSORTER_H_


#include "observable.h"
#include "heapsorter.h"

template <class MyListElementType>
class ObservableHeapSorter : public Observable, public HeapSorter<MyListElementType>
{
public:
	ObservableHeapSorter(List<MyListElementType> &myList):
		HeapSorter<MyListElementType>::HeapSorter(myList){}


	List<MyListElementType> &sort()
	{
		sendStartUpdateToObservers();
		HeapSorter<MyListElementType>::sort();
		sendStopUpdateToObservers();
		return this->list;
	}
	virtual ~ObservableHeapSorter(){};


};


#endif /* OBSERVABLEHEAPSORTER_H_ */
