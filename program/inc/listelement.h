/*
 * listelement.h
 *
 *  Created on: May 13, 2015
 *      Author: serek8
 */

#ifndef LISTELEMENT_H_
#define LISTELEMENT_H_

/**	@brief klasa ma byc uzywana jako abstrakcyjna do implementacji pojedynczego elemenu listy
 */
template <class MyListElementType>
class ListElement
{
public:

	/// Zawartość pojedynczego elelemntu tablicy
	MyListElementType content;

	virtual ~ListElement(){};

};




#endif /* LISTELEMENT_H_ */
