/*
 * observer.h
 *
 *  Created on: Apr 30, 2015
 *      Author: serek8
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer {
public:
	Observer();
    virtual void update() = 0;
	virtual ~Observer();
};


class Observed {
public:

	Observer *obserwator;

    void dodaj(Observer *o) {
    	obserwator=o;
    }

    void powiadom () {

    	obserwator -> update();
    }

	Observed(){}
	virtual ~Observed(){}



};





#endif /* OBSERVER_H_ */
