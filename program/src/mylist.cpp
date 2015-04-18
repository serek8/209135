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
MyList::MyListElement  MyList::operator[](int numberOfElement)
{
	MyList::MyListElement elem;
	elem = *(this->firstElement);
	for (int i =0; i< numberOfElement ; i++)
	{
		elem = *(elem.nextElement);
	}
	return elem;
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


MyList MyList::merge(MyList left, MyList right)
{
	MyList result;
	//Gdy jest jeszcze cos do sortowania
	while (left.size() > 0 || right.size() > 0)
	{
		// Jak oba to zamieniamy
		if (left.size() > 0 && right.size() > 0)
		{
			// Sprawdzam czy zamieniac
			if (left.show_front().number <= right.show_front().number)
				{
					result.push_back(left.show_front()); left.pop_front();
				}
			else
			{
				result.push_back(right.show_front()); right.pop_front();
			}
		}
		// pojedyncze listy (nieparzyse)
		else if (left.size() > 0)
		{
			for (int i = 0; i < left.size(); i++) result.push_back(left[i]); break;
		}
		// pojedyncze listy (nieparzyse- taka sama sytuacja jak wyzej)
		else if ((int)right.size() > 0)
		{
			for (int i = 0; i < (int)right.size(); i++) result.push_back(right[i]); break;
		}
	}
	return result;
}

MyList MyList::mergeSort(MyList m)
{
	if (m.size() <= 1) return m; // gdy juz nic nie ma do sotrowania
	MyList left, right, result;
	int middle = (m.size()+ 1) / 2; // anty-nieparzyscie
	for (int i = 0; i < middle; i++)
		{
			left.push_back(m[i]);
		}
	for (int i = middle; i < m.size(); i++)
		{
			right.push_back(m[i]);
		}
	left = mergeSort(left);
	right = mergeSort(right);
	result = merge(left, right);
	return result;
}





