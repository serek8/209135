/*
 * mylist.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: serek8
 */


#include "mylist.h"

MyList::MyList()
{
	firstElement = lastElement = new MyListElement();
	sizeOfList = 0;
}

MyList :: MyListElement::MyListElement(const MyListElement &myListElement)
{
	this->number = myListElement.number;
	this->nazwa = myListElement.nazwa;
	this->nextElement = myListElement.nextElement;
	this->previousElement = myListElement.previousElement;
}

void MyList :: push_back(MyListElement arg)
{
	MyListElement *newMyListElement = new MyListElement(arg);
	if(!sizeOfList++) {firstElement = lastElement = newMyListElement;}
	//newMyListElement -> nextElement = 0;
	newMyListElement -> previousElement = this -> lastElement;
	this -> lastElement -> nextElement = newMyListElement;
	this->lastElement = newMyListElement;
}
void MyList :: push_front(MyListElement arg)
{
	MyListElement *newMyListElement = new MyListElement(arg);
	if(!sizeOfList++) {firstElement = lastElement = newMyListElement;}
	//newMyListElement -> previousElement =  0;
	newMyListElement -> nextElement = this -> firstElement;
	this -> firstElement -> previousElement = newMyListElement;
	this->firstElement = newMyListElement;
}

MyList::MyListElement  MyList::pop_back()
{
	if(!(sizeOfList--)) { sizeOfList=0; return (*(new MyListElement())); }
	MyListElement tmpNumber = *(this -> lastElement);
	MyListElement *originMyListElement = this -> lastElement;
	this -> lastElement = this -> lastElement -> previousElement;
	delete originMyListElement;
	return tmpNumber;
}
MyList::MyListElement  MyList :: pop_front()
{
	if(!(sizeOfList--)) { sizeOfList=0; return (*(new MyListElement())); }
	MyListElement tmpNumber = *(this -> firstElement);
	MyListElement *originMyListElement = this -> firstElement;
	this -> firstElement = this -> firstElement -> nextElement;

	delete originMyListElement;
	return tmpNumber;
}

MyList :: MyListElement :: MyListElement(int arg, std::string str)
{
	this -> number = arg;
	this -> nazwa = str;
	this -> nextElement =0;
	this -> previousElement =0;
}
MyList :: MyListElement :: MyListElement()
{
	this -> number = 0;
	this -> nazwa = "";
	this -> nextElement =0;
	this -> previousElement =0;
}

MyList::MyListElement &MyList:: show_front(){
	return *firstElement;
}
MyList::MyListElement &MyList:: show_back(){
	return *lastElement;
}

int MyList::size()
{
	return sizeOfList;
}

void MyList::MyListElement::set(int arg, std::string str){
	this -> number = arg;
	this -> nazwa = str;
}
int MyList :: saveDataToFile()
{
	std::ofstream streamToFile;
	streamToFile.open ("myList.log", std::ofstream::out);
	MyListElement el;
	for(int i=0; i<sizeOfList ; i++) {
		el = pop_front();
		streamToFile << '{'<<el.nazwa <<':'<<el.number<<"} ";
	}
	return 0;
}
