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
template <class ContentType>
class QuickSorter : public Sorter<ContentType>
{
public:
	int enablePivot;
	/// Skopiowana lista do przeprowadzania sortowania
	List<ContentType> &list;

	/** @brief Konstruktor
	 *  @param &list lista, która konstruktor kopiuje aby nie naruszać podanej przez uzytkownika
	 */
	QuickSorter(List<ContentType> &list)
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
	    int pivot=list[(int)(lewy+prawy)/2];
	    int i=lewy,j=prawy, x;
	    if(enablePivot) pivot=(list[(int)(lewy+prawy)/2] + list[lewy] + list[prawy])/3;
	    do
	    {
	        while(list[i]<pivot) {i++; }
	        while(list[j]>pivot) {j--; }
	        if(i<=j)
	        {
	        	x =list[i];
	            list[i]=list[j];
	            list[j]=x;
	            i++;
	            j--;
	        }
	    }
	    while(i<=j);
	    if(j>lewy) quicksort(lewy, j);
	    if(i<prawy) quicksort(i, prawy);
	}

	/** @brief Sortuje przez Sortowanie szybkie
	 */
	List<ContentType> &sort()
	{
		//std::cout<<"(QuickSort)";
		quicksort(0, list.size()-1);
		return list;
	}
};



#endif /* QUICKSORT_H_ */
