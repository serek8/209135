/*
 * main.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: serek8
 */
/** @file */
#include <iostream>
#include <unistd.h>
#include "numbergenerator.h"
#include "observableavltree.h"
#include "mybenchmark.h"
#include "mylist.h"

#define ILE_WYRAZOW_DO_WSTAWIENIA 100000000

int main(int argc, char *argv[])
{

	MyList<int> lista;
	MyBenchmark benchmark;
	benchmark.timerStart();
	lista = NumberGenerator::generateNumbers<int>(100000, ILE_WYRAZOW_DO_WSTAWIENIA/10);
	cout<<"Wygenerowalem losowe liczby w "<<benchmark.timerStop()<<" sekund\n";
	AVLTree<int> tree;
	int x=0;

	///////////////////////////////////
	for(int j=10; j<ILE_WYRAZOW_DO_WSTAWIENIA; j=j*10)
		{

		benchmark.timerStart();
			for(int i=0; i<j-x; i++)
			{
				tree.insert(lista[i].content);
			}
			cout<<j<<" "<<benchmark.timerStopAndSaveToFile()<<" ";
			benchmark.tab();
			//szukanie
		benchmark.timerStart();
			for(int i=0; i<j-x; i++)
			{
				tree.find(lista[i].content);
			}
			cout<<benchmark.timerStopAndSaveToFile()<<endl;
			benchmark.newL();
			//szukanie end
			x+=j;
		}
}
