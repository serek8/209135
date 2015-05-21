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

#define ILE_WYRAZOW_DO_WSTAWIENIA 100

int main(int argc, char *argv[])
{
	MyList<int> lista;


	lista = NumberGenerator::generateNumbers<int>(100, ILE_WYRAZOW_DO_WSTAWIENIA);
	ObservableAVLTree<int> tree;
	MyBenchmarkObserver *o1 = new MyBenchmarkObserver();
	tree.add(o1);

	for(int i=0; i<lista.size(); i++)
	{
		tree.insert(lista[i].content);
	}
	std::cout<<std::endl;
	return 0;
}
