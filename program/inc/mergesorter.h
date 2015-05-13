/*
 * mergesort.h
 *
 *  Created on: May 11, 2015
 *      Author: serek8
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "sorter.h"

template <typename MyListElementType>
class MergeSorter: public MyList<MyListElementType> {
public:


	MergeSorter(){};
	MergeSorter(MyList<MyListElementType> &myList)
	{
		this->sizeOfList = myList.sizeOfList;
		this->firstElement = myList.firstElement;
		this->lastElement = myList.lastElement;
		this->iterator=myList.iterator;
		this->isIteratorAfterPop = myList.isIteratorAfterPop;
	}
	virtual ~MergeSorter(){}


	MergeSorter<MyListElementType> merge(MergeSorter<MyListElementType> left, MergeSorter<MyListElementType> right)
	{
		MergeSorter<MyListElementType> result;
		//Gdy jest jeszcze cos do sortowania
		while (left.size() > 0 || right.size() > 0)
		{
			// Jak oba to zamieniamy
			if (left.size() > 0 && right.size() > 0)
			{
				// Sprawdzam czy zamieniac
				if (left.show_front().content <= right.show_front().content)
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
	/**
	 * @brief Sortuje liste przez scalanie
	 * @param m Lista do posotrowania
	 * @return zwraca posotrowana liste
	 */
	MergeSorter<MyListElementType> mergeSort(MergeSorter<MyListElementType> &m)
	{
		if (m.size() <= 1) return m; // gdy juz nic nie ma do sotrowania
		MergeSorter<MyListElementType> left, right, result;
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
		//(MyList<MyListElementType>)(*this)=result;
		//result = merge(left, right);
		// zapisuje do oryginalu
		//(*this) = result;
		return result;
	}


	MyList<MyListElementType> sort()
	{	std::cerr<<"\nSortowanie z MergeSort";
		MergeSorter <MyListElementType> result;
		result= mergeSort(*this);
		*this = result;
		std::cout<<"\n(MergeSort - exit)";
		return result;
	}

};

#endif /* MERGESORT_H_ */
