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

/** @brief Klasa sluzaca do obslugi sortowania przez Scalanie z dodaniem obserwatora
 */
template <class MyListElementType>
class ObservableMergeSorter : public Observable, public MergeSorter<MyListElementType>
{
public:
	ObservableMergeSorter(MyList<MyListElementType> &myList):
		MergeSorter<MyListElementType>::MergeSorter(myList){}

	/** @brief sortuje przez scalanie
	 */
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
