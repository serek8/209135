/*
 * list.h
 *
 *  Created on: May 13, 2015
 *      Author: serek8
 */

#ifndef LIST_H_
#define LIST_H_

#include "listelement.h"
#include "list.h"

/** Interface dla klasy przedstawiających listy
 */
template <class ContentType>
class List
{
public:
	/**	@brief Pobiera rozmiar listy
	 *	@return Rozmiar listy
	 */
	int virtual &size() = 0;

	// Zaczerpnite z wzorca projektowego Budowniczy

	/**	@brief Zwraca ostatni element z listy
	 *	@return ostatni element z listy
	 */
	ListElement<ContentType> virtual pop_back()	=	0;

	/**	@brief Zwraca pierwszy element z listy
	 *	@return pierwszy element z listy
	 */
	ListElement<ContentType> virtual pop_front() 		= 	0;

	/**	@brief Wyswietla liste
	 */
	void virtual printList()	=	0;
	void virtual push_back(ContentType arg)	=	0;

	/**	@brief Wsadza ContentType do listy na poczatek
	 */
	void virtual push_front(ContentType arg)	=	0;

	/**	@brief Wsadza ContentType do listy na koniec
	 */
	MyListElement<ContentType> virtual &operator[](int numberOfElement)		=	0;

	/**	@brief Wsadza ContentType po elemencie
	 * 	@param arg Element do wsadzenia
	 * 	@param iteratorID id elementu do wsadzenia
	 */
	void virtual insertAfter(MyListElement<ContentType> arg, int iteratorID)	=	0;

	/**	@brief Pokazue pierwszy element na liscie
	 */
	ContentType virtual &show_front()	=	0;

	/**	@brief Pokazue ostatni element na liscie
	 */
	ContentType virtual &show_back()	=	0;


	//List<ContentType> virtual &operator=(const List<ContentType> &pattern)	=	0;

	/**	@brief Klonuje listy przydzielajac dla nowej nową pamięć dla każdego z jej elementu
	 */
	void virtual cloneFrom(List<ContentType> &patternList)
	{
		// release memory from main list
		while(this->size()) pop_back();
		for(int i=0; i<patternList.size(); i++)
			this->push_back(patternList[i].content);
	}

	/**	@brief Wzorzec projektowy - fabryki abstrakcyjnej
	 */
	List<ContentType> virtual &createObjectFromAbstractReference() = 0;

	/**	@brief Zwalnia zasoby listy
	 */
	void virtual free(){ while(size()) pop_back(); }
	virtual ~List(){};
};



#endif /* LIST_H_ */
