/*
 * observable.h
 *
 *  Created on: May 14, 2015
 *      Author: serek8
 */

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <iostream>
#include "mylist.h"

class Observable {
public:
	//MyList<int> observaterswww;
	MyList<Observer*> observaters;

    void add(Observer *o) {
    	observaters.push_back(o);
    }

    void sendStartUpdateToObservers () {
    	for(int i=0; i<observaters.size(); i++)
    	{
    		//std::cout<<"Wysylam start update";
    		observaters[i].content->receivedStartUpdate();
    	}
    }
    void sendStopUpdateToObservers () {
    	for(int i=0; i<observaters.size(); i++)
    		observaters[i].content->receivedStopUpdate();
    }
    void sendStopUpdateToObserversAndSaveToFile () {
    	for(int i=0; i<observaters.size(); i++)
    		observaters[i].content->receivedStopUpdateAndSaveToFile();
    }


	virtual ~Observable(){}



};

#endif /* OBSERVABLE_H_ */
