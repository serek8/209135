/*
 * stackonarray.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: serek8
 */




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
		++index;
		return;
	}
	int *tmpTableOfData = new int[sizeOfTable+1];
	for(int i =0 ; i<index)



}
