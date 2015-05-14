/*
 * list.h
 *
 *  Created on: May 13, 2015
 *      Author: serek8
 */

#ifndef LIST_H_
#define LIST_H_

#include "listelement.h"
#include "list.h"

template <class MyListElementType>
class List
{
public:

	int virtual &size() = 0;
	ListElement<MyListElementType> virtual pop_back()	=	0;
	ListElement<MyListElementType> virtual pop_front() 		= 	0;
	void virtual printList()	=	0;
	void virtual push_back(MyListElementType arg)	=	0;
	void virtual push_front(MyListElementType arg)	=	0;
	MyListElement<MyListElementType> virtual &operator[](int numberOfElement)		=	0;
	void virtual insertAfter(MyListElement<MyListElementType> arg, int iteratorID)	=	0;
	MyListElementType virtual &show_front()	=	0;
	MyListElementType virtual &show_back()	=	0;
	//List<MyListElementType> virtual &operator=(const List<MyListElementType> &pattern)	=	0;

	void virtual cloneFrom(List<MyListElementType> &patternList)
	{
		// release memory from main list
		while(this->size()) pop_back();
		for(int i=0; i<patternList.size(); i++)
			this->push_back(patternList[i].content);
	}
	List<MyListElementType> virtual &createObjectFromAbstractReference() = 0;

	void virtual free(){ while(size()) pop_back(); }
	virtual ~List(){};
};



#endif /* LIST_H_ */
