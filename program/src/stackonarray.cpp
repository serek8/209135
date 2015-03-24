/*
 * stackonarray.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: serek8
 */

#include "stackonarray.h"


StackOnArray::StackOnArray()
{
	sizeOfTable =1;
	index=0;
	tableOfData = new int[1];
}


void StackOnArray::pushByOneAlloc(int arg)
{
	if(index==0){
		tableOfData[0] = arg;
		++index; // teraz index = 1
		return;
	}
	if(index==sizeOfTable) 
	{
		int *tmpTableOfData = new int[index+1];	//index pokazuje zawsze na nastepny element ktory jest jeszcze pusty
		for(int i =0 ; i<index; i++)
		{
			tmpTableOfData[i] = tableOfData[i];
		}
		delete[] tableOfData;
		tableOfData = tmpTableOfData;
	}
	tableOfData[index] = arg;
	sizeOfTable = ++index ;
	//Po zakonczeniu tej funkcji index i sizeOfTable musza byc sobie rowne
}

void StackOnArray::pushByDoubleAlloc(int arg)
{
	if(index==0){
		tableOfData[0] = arg;
		++index;
		return;
	}
	
	if(sizeOfTable==index)
	{
		
		int *tmpTableOfData = new int[2*index];
		sizeOfTable = 2*index;
		for(int i =0 ; i<index; i++)
		{
			tmpTableOfData[i] = tableOfData[i];
		}
		delete[] tableOfData;
		tableOfData = tmpTableOfData;
	}
	tableOfData[index++] = arg; // powiekszam index po przypisaniu nowej wartosci
}

int StackOnArray::pop()
{
	return tableOfData[--index];
}

StackOnArray:: ~StackOnArray()
{
delete [] 	tableOfData;
}

