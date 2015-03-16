/*
 * mystack.h
 *
 *  Created on: Mar 16, 2015
 *      Author: serek8
 */

#ifndef MYSTACK_H_
#define MYSTACK_H_
/**
 * @brief Klasa reprezentuje stos
 *
 * Stos dziala na tablicy dynamicznej
 * Stos, którego index po pushu pokazuje na miejsce nastepne(nastepne za tym elementem)
 *
 */
class MyStack
{
	int stackSize;
	int index;
	int *stack;

	MyStack(int arg);
	void push(int arg);
	int pop();
	int size();

};

#endif /* MYSTACK_H_ */
