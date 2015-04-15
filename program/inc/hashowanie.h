/*
 * hashowanie.h
 *
 *  Created on: Apr 9, 2015
 *      Author: serek8
 */

#ifndef HASHOWANIE_H_
#define HASHOWANIE_H_
#include <string>
#include <iostream>
using namespace std;
class Hashowanie
{
public:
	static int str2int(const char* str){
		int hash;
		hash = (int)str[0]+(int)str[1]+(int)str[2];
		std::cout<<"\nHash:"<<hash;
		return hash;
	}



};





#endif /* HASHOWANIE_H_ */
