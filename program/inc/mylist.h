/*
 * mylist.h
 *
 *  Created on: Mar 12, 2015
 *      Author: serek8
 */

#ifndef MYLIST_H_
#define MYLIST_H_

class MyList{

private:
	int number;
	MyList *pMyList;;
	int sizeOfList;

public:
	MyList();
	int pop();
	void push(int arg);

	int size();

};



#endif /* MYLIST_H_ */
