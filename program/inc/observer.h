/*
 * observer.h
 *
 *  Created on: Apr 30, 2015
 *      Author: serek8
 */



#ifndef OBSERVER_H_
#define OBSERVER_H_



/** @brief obserwator
 *
 * Interfejs obserwatora
 */
class Observer {
public:
	/** @brief pobiera czas trwania algorytmu
	 * @return czas trwania algorytmu
	 */
	virtual double getTimerValue() = 0;

	/** @brief Odbiera powiadomienie o rozpoczeciu dzialania algorytmu
	 */
    virtual void receivedStartUpdate() = 0;

	/** @brief Odbiera powiadomienie o zakonczeniu dzialania algorytmu
	 */
    virtual void receivedStopUpdate() = 0;
	virtual ~Observer(){};
};








#endif /* OBSERVER_H_ */
