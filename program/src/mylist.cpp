/*
 * mylist.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: serek8
 */


#include "mylist.h"

MyList::MyList()
{
	number=0;
	pMyList=0;
	sizeOfList=0;
}

int MyList::pop()
{
	if(!sizeOfList) return 0;
	//robie kopie objektu kolejnego
	int tmpNumber = this -> number;
	MyList *tmpMyList = this -> pMyList;

	this -> number  = this->pMyList->number;
	this -> pMyList = this->pMyList->pMyList;

	delete tmpMyList;
	--sizeOfList;
	return tmpNumber;
}

void MyList::push(int arg)
{
	MyList *tmpMyList = new MyList;
	tmpMyList -> number = this -> number;
	tmpMyList -> pMyList= this -> pMyList;
	this -> pMyList = tmpMyList;
	this -> number = arg;
	++sizeOfList;
}

int MyList::size()
{
	return sizeOfList;
}
