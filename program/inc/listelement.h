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
template <class ContentType>
class ListElement
{
public:

	/// Zawartość pojedynczego elelemntu tablicy
	ContentType content;

	virtual ~ListElement(){};

};




#endif /* LISTELEMENT_H_ */
