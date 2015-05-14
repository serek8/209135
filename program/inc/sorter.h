/*
 * Sorter.h
 *
 *  Created on: May 13, 2015
 *      Author: serek8
 */

#ifndef SORTER_H_
#define SORTER_H_

#include "list.h"

/// @brief interfejs kazdego sortowania
template <class MyListElementType>
class Sorter
{
public:

	virtual List<MyListElementType> &sort() = 0;

	/** @breif Sortuje przez scalanie
	 */
	virtual ~Sorter(){};
};


#endif /* SORTER_H_ */
