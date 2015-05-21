/*
 * observableavltree.h
 *
 *  Created on: May 21, 2015
 *      Author: serek8
 */

#ifndef OBSERVABLEAVLTREE_H_
#define OBSERVABLEAVLTREE_H_

#include "observable.h"
#include "avltree.h"


template <class ContentType>
class ObservableAVLTree : public Observable, public AVLTree<ContentType>
{
public:
	void insert(int newKey)
	{
		sendStartUpdateToObservers();
			AVLTree<ContentType>::insert(newKey);
		sendStopUpdateToObserversAndSaveToFile();
	}

	~ObservableAVLTree(){}
};



#endif /* OBSERVABLEAVLTREE_H_ */
