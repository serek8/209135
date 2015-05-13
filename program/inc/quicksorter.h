/*
 * quicksort.h
 *
 *  Created on: May 12, 2015
 *      Author: serek8
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "sorter.h"
#include <iostream>
/**
 * Szybkie sortowanie Janka
 *
 */
template <typename MyListElementType>
class QuickSorter : public Sorter<MyListElementType>
{
public:
	int enablePivot;


	QuickSorter(MyList<MyListElementType> &myList)
	{
		this->cloneFrom(myList);
		this->enablePivot=1;
	}

	QuickSorter(int isEnablePivot)
	{
		this->enablePivot = isEnablePivot;
	}
	virtual ~QuickSorter(){};
	//void quicksort(int lewy, int prawy, int enablePivot)
	void quicksort(int lewy, int prawy)
	{
	    int pivot=(*this)[(int)(lewy+prawy)/2].content;
	    int i,j,x;
	    i=lewy;
	    j=prawy;
	    if(enablePivot) pivot=((*this)[(int)(lewy+prawy)/2].content + (*this)[lewy].content + (*this)[prawy].content)/3;
	    do
	    {
	        while((*this)[i].content<pivot) {i++; }
	        while((*this)[j].content>pivot) {j--; }
	        if(i<=j)
	        {
	            x=(*this)[i].content;
	            (*this)[i].content=(*this)[j].content;
	            (*this)[j].content=x;
	            i++;
	            j--;
	        }
	    }
	    while(i<=j);
	    if(j>lewy) quicksort(lewy, j);
	    if(i<prawy) quicksort(i, prawy);
	}
public:
	MyList<MyListElementType> sort()
	{
		std::cout<<"(QuickSort)";
		quicksort(0, this->sizeOfList-1);
		return (*this);
	}
};



#endif /* QUICKSORT_H_ */
