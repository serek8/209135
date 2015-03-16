/*
 * mystack.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: serek8
 */

#include "mystack.h"

MyStack :: MyStack(int arg) {
	stackSize = arg;
	index = 0;
	stack = new int[arg];
}

void MyStack :: push(int arg) {
	stack[index++] = arg;
}

int MyStack :: pop() {
	return stack[--index];
}

int MyStack :: size() {
	return index;
}
