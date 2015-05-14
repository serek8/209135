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

template <class MyListElementType>
class MergeSorter: public Sorter<MyListElementType> {
public:

	MyList<MyListElementType> &list;

	MergeSorter(MyList<MyListElementType> &listArg)
	:list(listArg)	{}

	virtual ~MergeSorter(){}


	MyList<MyListElementType> merge(MyList<MyListElementType> left, MyList<MyListElementType> right)
	{
		MyList<MyListElementType> result;
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
	MyList<MyListElementType> mergeSort(MyList<MyListElementType> m)
	{
		if (m.size() <= 1) return m; // gdy juz nic nie ma do sotrowania
		MyList<MyListElementType> left, right, result;
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


	List<MyListElementType> &sort()
	{
		this->list=mergeSort(this->list);
		return this->list;
	}

};

#endif /* MERGESORT_H_ */
