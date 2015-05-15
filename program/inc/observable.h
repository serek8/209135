/*
 * observable.h
 *
 *  Created on: May 14, 2015
 *      Author: serek8
 */

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <iostream>
#include "linkedlist.h"

	/** @brief Klasa abstrakcyjna- bazowa dla objektow do obserowania
	 */
class Observable {
public:
	/// Lista obserwatorow
	LinkedList<Observer*> observaters;

	/** @brief Dodaje sie jako obiekt do obserowania dla danego obserwatora
	 */
    void add(Observer *obserwator) {
    	observaters.push_back(obserwator);
    }

	/** @brief Wysyla powiadomienie do obserwatorow o rozpoczeciu algorytmu
	 */
    void sendStartUpdateToObservers () {
    	for(int i=0; i<observaters.size(); i++)
    	{
    		//std::cout<<"Wysylam start update";
    		observaters[i]->receivedStartUpdate();
    	}
    }

    /** @brief Wysyla powiadomienie do obserwatorow o zakonczeniu algorytmu
     */
    void sendStopUpdateToObservers () {
    	for(int i=0; i<observaters.size(); i++)
    		observaters[i]->receivedStopUpdate();
    }

	virtual ~Observable(){}



};

#endif /* OBSERVABLE_H_ */
