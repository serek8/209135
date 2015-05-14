/*
 * observablemergesorter.h
 *
 *  Created on: May 14, 2015
 *      Author: serek8
 */

#ifndef OBSERVABLEMERGESORTER_H_
#define OBSERVABLEMERGESORTER_H_


#include "observable.h"
#include "mergesorter.h"

template <class MyListElementType>
class ObservableMergeSorter : public Observable, public MergeSorter<MyListElementType>
{
public:
	ObservableMergeSorter(MyList<MyListElementType> &myList):
		MergeSorter<MyListElementType>::MergeSorter(myList){}


	List<MyListElementType> &sort()
	{
		sendStartUpdateToObservers();
		MergeSorter<MyListElementType>::sort();
		sendStopUpdateToObservers();
		return this->list;
	}
	virtual ~ObservableMergeSorter(){};


};


#endif /* OBSERVABLEMERGESORTER_H_ */
