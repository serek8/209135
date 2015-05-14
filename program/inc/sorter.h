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
template <class ContentType>
class Sorter
{
public:

	virtual List<ContentType> &sort() = 0;

	/** @brief Sortuje przez scalanie
	 */
	virtual ~Sorter(){};
};


#endif /* SORTER_H_ */
