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
	virtual double getTimerValue() = 0;
    virtual void receivedStartUpdate() = 0;
    virtual void receivedStopUpdate() = 0;
    virtual void receivedStopUpdateAndSaveToFile() = 0;
	virtual ~Observer(){};
};








#endif /* OBSERVER_H_ */
