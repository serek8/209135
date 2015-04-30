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
	iteratorElementId =0;
	iterator=NULL;
	isIteratorAfterPop = 1; //to znaczy ze jeszcze raz trzeba bedzie sprawdzic pozycje iteratora 1- znaczy ze trzeba sprawdzic
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
	++iteratorElementId;
}

void MyList :: insertAfter(MyListElement arg, int iteratorID)
{
	if(iteratorID==0 && this->sizeOfList==0)  {push_front(arg); return;}
	if(iteratorID==this->sizeOfList-1)  {push_back(arg); return;}
	MyListElement *newMyListElement = new MyListElement(arg);
	MyListElement &tmpThis=(*this)[iteratorID], &tmpNext=(*this)[iteratorID+1];
	if(!sizeOfList++) {firstElement = lastElement = newMyListElement;}
	newMyListElement -> nextElement = tmpThis.nextElement;
	newMyListElement -> previousElement = &tmpThis;
	tmpThis.nextElement = newMyListElement;
	tmpNext.previousElement = newMyListElement;
	isIteratorAfterPop=1;
}

MyList::MyListElement  MyList::pop_back()
{
	if(!(sizeOfList--)) { sizeOfList=0; return (*(new MyListElement())); }
	MyListElement tmpNumber = *(this -> lastElement);
	MyListElement *originMyListElement = this -> lastElement;
	this -> lastElement = this -> lastElement -> previousElement;
	delete originMyListElement;
	isIteratorAfterPop=1;
	return tmpNumber;
}
MyList::MyListElement  MyList :: pop_front()
{
	if(!(sizeOfList--)) { sizeOfList=0; return (*(new MyListElement())); }
	MyListElement tmpNumber = *(this -> firstElement);
	MyListElement *originMyListElement = this -> firstElement;
	this -> firstElement = this -> firstElement -> nextElement;

	delete originMyListElement;
	isIteratorAfterPop=1;
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
MyList::MyListElement &MyList::operator[](int numberOfElement)
{
	//std::cerr<<"\nJestem w ["<<numberOfElement<<"] iterator="<<iteratorElementId;
	if(numberOfElement > (sizeOfList-1)) // jezeli wyszedlem poza liste
		{
			std::cerr<<"\n! Error indeks o numerze: "<<numberOfElement<<" nie istnieje !";
			return *iterator;
		}
	if(isIteratorAfterPop)
		{
			iteratorElementId=0;  // czyli iterator byl zpopowany
			iterator = firstElement;
			isIteratorAfterPop=0;
		}
	//std::cerr<<"\nsprawdzam w ["<<numberOfElement<<"] iterator="<<iteratorElementId;
	if((numberOfElement <= iteratorElementId-numberOfElement) &&(iteratorElementId-numberOfElement>=0))
	{
		//std::cerr<<"\nJestem w if_1";
		iterator = (this->firstElement);
		for (int i =0; i< numberOfElement ; i++)
			iterator = (iterator->nextElement);
	}
	else if(numberOfElement > iteratorElementId)
	{
		//std::cerr<<"\nJestem w if_2";
		for (; iteratorElementId< numberOfElement ; iteratorElementId++)
					iterator = (iterator->nextElement);
	}
	else if( numberOfElement < iteratorElementId)
	{
		//std::cerr<<"\nJestem w if_3";
		for (; iteratorElementId> numberOfElement ; iteratorElementId--)
					iterator = (iterator->previousElement);
	}
	return *iterator;
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
	// zapisuje do oryginalu
	(*this) = result;
	return result;
}
