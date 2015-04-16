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
MyList :: MyListElement :: MyListElement(int arg)
{
	this -> number = arg;
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


void MyList :: scalanieSort(MyList lista)
{
	if(this->sizeOfList > 2)
	{
		MyList tmpLista1, tmpLista2;
		// dziele zbior na nwa podzbiory
		for(int i=0; i<(lista.sizeOfList/2); i++)
			tmpLista1.push_front(lista.pop_front());
		for(int i=0; i<lista.sizeOfList/2; i++)
			tmpLista2.push_front(lista.pop_front());

	}
	else
	{
		int tmp = lista.pop_front().number;
		MyList::MyListElement *elem = new MyList::MyListElement(tmp);
		if(tmp < lista.show_front().number ) lista.push_front(*elem);
		else lista.push_back(*elem);

	}

}

int MyList :: splitList(MyList &tmpLista1, MyList &tmpLista2)
{
	int size = this->sizeOfList;
	std::cout<<"\nRozmiar listy to: "<<size;;
	for(int i=0; i<(size/2); i++)
		tmpLista1.push_back(this->pop_front());

	for(int i=0; i<size/2; i++)
		tmpLista2.push_back(this->pop_front());

	std::cout<<"\nPo podzieleniu listy: ";
	tmpLista1.printList();
	tmpLista2.printList();
	return 0;
}

void  MyList :: printList()
{
	MyList::MyListElement *elem = (this->firstElement);
	std::cout<<"\nWyswietlam liste (size:"<<this->sizeOfList<<"): ";
	for(int i=0; i< this->sizeOfList; i++)
	{
		std::cout<<" "<<elem->number;
		elem = elem->nextElement;
	}
}


MyList MyList::mergeLists(MyList a, MyList b){

    MyList mergedList;

    if (!a.sizeOfList){
        return b;
    }else if (!b.sizeOfList){
        return a;
    }


    if (a.show_front().number <= b.show_front().number){
        mergedList = a;
        MyList::MyListElement elem = a.pop_front();
        mergedList.push_back(elem);
        mergeLists(a, b);

    }else{
        mergedList = b;
        MyList::MyListElement elem = b.pop_front();
         mergedList.push_back(elem);
         mergeLists(a, b);
    }

    return mergedList;

}

void MyList::mergeSort(){

    MyList head = *this;
    MyList a;
    MyList b;

    if(!head.sizeOfList){

        return;

    }

    head.splitList(a, b);

    a.mergeSort();
    b.mergeSort();

    head = mergeLists(a, b);

}





