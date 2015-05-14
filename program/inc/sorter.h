/*
 * Sorter.h
 *
 *  Created on: May 13, 2015
 *      Author: serek8
 */

#ifndef SORTER_H_
#define SORTER_H_

#include "list.h"


template <class MyListElementType>
class Sorter
{
public:

	virtual List<MyListElementType> &sort() = 0;
	virtual ~Sorter(){};
};


#endif /* SORTER_H_ */
