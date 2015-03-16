/*
 * myqueue.h
 *
 *  Created on: Mar 16, 2015
 *      Author: serek8
 */

#ifndef MYQUEUE_H_
#define MYQUEUE_H_


class MyQueue
{
	int headNumber, tailNumber;
	MyQueue *beforeHead;
	MyQueue NextElement;

	int sizeOfQueue;

public:
	MyQueue();
	void push(int arg);
	int pop();
	int size();




};




#endif /* MYQUEUE_H_ */
