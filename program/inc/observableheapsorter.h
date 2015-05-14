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

/** @brief Klasa sluzaca do obslugi sortowania przez kopcowanie z dodaniem obserwatora
 */
template <class ContentType>
class ObservableHeapSorter : public Observable, public HeapSorter<ContentType>
{
public:
	ObservableHeapSorter(List<ContentType> &myList):
		HeapSorter<ContentType>::HeapSorter(myList){}

	/** @brief sortuje przez kopcowanie
	 */
	List<ContentType> &sort()
	{
		sendStartUpdateToObservers();
		HeapSorter<ContentType>::sort();
		sendStopUpdateToObservers();
		return this->list;
	}
	virtual ~ObservableHeapSorter(){};


};


#endif /* OBSERVABLEHEAPSORTER_H_ */
