/*
 * observablequicksort.h
 *
 *  Created on: May 14, 2015
 *      Author: serek8
 */

#ifndef OBSERVABLEQUICKSORTER_H_
#define OBSERVABLEQUICKSORTER_H_


#include "observable.h"
#include "quicksorter.h"

/** @brief Klasa sluzaca do obslugi sortowania przez Sortowanie szybkie z dodaniem obserwatora
 */
template <class ContentType>
class ObservableQuickSorter : public Observable, public QuickSorter<ContentType>
{
public:
	ObservableQuickSorter(List<ContentType> &list):
		QuickSorter<ContentType>::QuickSorter(list){}

	/** @brief sortuje przez scalanie
	 */
	List<ContentType> &sort()
	{
		sendStartUpdateToObservers();
		QuickSorter<ContentType>::sort();
		sendStopUpdateToObservers();
		return this->list;
	}
	virtual ~ObservableQuickSorter(){};


};


#endif /* OBSERVABLEQUICKSORTER_H_ */
