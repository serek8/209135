/*
 * mergesort.h
 *
 *  Created on: May 11, 2015
 *      Author: serek8
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "sorter.h"
#include "list.h"

/// @brief Klasa sluzaca do obslugi sortowania przez Scalanie
template <class ContentType>
class MergeSorter: public Sorter<ContentType> {
public:

	/// Skopiowana lista do przeprowadzania sortowania
	MyList<ContentType> &list;

	/** @brief Konstruktor
	 *  @param listArg lista, która konstruktor kopiuje aby nie naruszać podanej przez uzytkownika
	 */
	MergeSorter(MyList<ContentType> &listArg)
	:list(listArg)	{}

	virtual ~MergeSorter(){}

	/**
	 * @brief Scalanie list
	 * @param left lewa lista do scalania
	 * @param right prawa lista do scalania
	 * @return zwraca posotrowana liste
	 */
	MyList<ContentType> merge(MyList<ContentType> left, MyList<ContentType> right)
	{
		MyList<ContentType> result;
		//Gdy jest jeszcze cos do sortowania
		while (left.size() > 0 || right.size() > 0)
		{
			// Jak oba to zamieniamy
			if (left.size() > 0 && right.size() > 0)
			{
				// Sprawdzam czy zamieniac
				if (left.show_front() <= right.show_front())
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
				for (int i = 0; i < left.size(); i++) result.push_back(left[i].content); break;
			}
			// pojedyncze listy (nieparzyse- taka sama sytuacja jak wyzej)
			else if ((int)right.size() > 0)
			{
				for (int i = 0; i < (int)right.size(); i++) result.push_back(right[i].content); break;
			}
		}
		return result;
	}
	/**
	 * @brief Sortuje liste przez scalanie
	 * @param m Lista do posotrowania
	 * @return zwraca posotrowana liste
	 */
	MyList<ContentType> mergeSort(MyList<ContentType> m)
	{
		if (m.size() <= 1) return m; // gdy juz nic nie ma do sotrowania
		MyList<ContentType> left, right, result;
		int middle = (m.size()+ 1) / 2; // anty-nieparzyscie
		for (int i = 0; i < middle; i++)
			{
				left.push_back(m[i].content);
			}
		for (int i = middle; i < m.size(); i++)
			{
				right.push_back(m[i].content);
			}
		left = mergeSort(left);
		right = mergeSort(right);
		result = merge(left, right);
		return result;
	}


	/** @brief Sortuje przez scalanie
	 */
	List<ContentType> &sort()
	{
		this->list=mergeSort(this->list);
		return this->list;
	}

};

#endif /* MERGESORT_H_ */
