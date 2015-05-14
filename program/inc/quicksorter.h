/*
 * quicksort.h
 *
 *  Created on: May 12, 2015
 *      Author: serek8
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "sorter.h"
#include "list.h"
#include <iostream>


/// @brief Klasa sluzaca do obslugi sortowania przez Scalanie
template <class MyListElementType>
class QuickSorter : public Sorter<MyListElementType>
{
public:
	int enablePivot;
	/// Skopiowana lista do przeprowadzania sortowania
	List<MyListElementType> &list;

	/** @brief Konstruktor
	 *  @param &myList lista, która konstruktor kopiuje aby nie naruszać podanej przez uzytkownika
	 */
	QuickSorter(List<MyListElementType> &list)
	:list(list.createObjectFromAbstractReference())
	{
		this->list.cloneFrom(list);
		this->enablePivot=1;
	}

	virtual ~QuickSorter(){};

	/**
	 * @brief Szuka liczb do porownaia z pivotem
	 * @param lewy brzeg poszukiwan
	 * @param prawy brzeg poszukiwan
	 */
	void quicksort(int lewy, int prawy)
	{
	    int pivot=list[(int)(lewy+prawy)/2].content;
	    int i,j,x;
	    i=lewy;
	    j=prawy;
	    if(enablePivot) pivot=(list[(int)(lewy+prawy)/2].content + list[lewy].content + list[prawy].content)/3;
	    do
	    {
	        while(list[i].content<pivot) {i++; }
	        while(list[j].content>pivot) {j--; }
	        if(i<=j)
	        {
	            x=list[i].content;
	            list[i].content=list[j].content;
	            list[j].content=x;
	            i++;
	            j--;
	        }
	    }
	    while(i<=j);
	    if(j>lewy) quicksort(lewy, j);
	    if(i<prawy) quicksort(i, prawy);
	}

	/** @breif Sortuje przez Sortowanie szybkie
	 */
	List<MyListElementType> &sort()
	{
		//std::cout<<"(QuickSort)";
		quicksort(0, list.size()-1);
		return list;
	}
};



#endif /* QUICKSORT_H_ */
