/*
 * stackonarray.h
 *
 *  Created on: Mar 19, 2015
 *      Author: serek8
 */

#ifndef STACKONARRAY_H_
#define STACKONARRAY_H_


class StackOnArray
{
	int sizeOfTable;
	int index;
	int *tableOfData;

public:
	StackOnArray();
	void pushByOneAlloc(int arg);
	void pushByDoubleAlloc(int arg);
	int pop();
};


#endif /* STACKONARRAY_H_ */
