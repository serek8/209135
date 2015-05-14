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
#include "mylist.h"
#include "mybenchmark.h"
#include "observable.h"
#include "observer.h"
#include "observableheapsorter.h"
#include "observablequicksorter.h"
#include "observablemergesorter.h"
#include "filestreamer.h"

int main(int argc, char *argv[])
{
	MyList<int> lista;
	int isSetN = 0;
	int opt;	/// Zmienna uzywana przez GETOPT
	while ((opt = getopt(argc, argv, "n:o:i:gx")) != -1) {
		switch(opt){
		case 'n':	// ilosc liczb do przetworzenia
			lista = NumberGenerator::generateNumbers<int>(10000000, atoi(optarg));
			isSetN = 1;
			break;

		case 'o':
			//podstawoweInfoIO.outputFileName = optarg;
			break;

		case 'i':
			//podstawoweInfoIO.inputFileName=optarg;
			break;

		case '?':	default:
			std::cout<<"\nPodano zly argument";
			return -1;
		}
	}
	//if(!isSetN) {std::cerr<<"\nNie podano argumentu: -n X\n"; return -1;}


		std::cout<<"\n+ - - - - Zaczynam sortowanie - - - +\n";

		clearFile("log.txt");
		writeStringToFile("log.txt", "HeapSort\t");
		writeStringToFile("log.txt", "QuickSort\t");
		writeStringToFile("log.txt", "MergeSort\n");
		for(int i=1000; i<10000; i+=1000)
		{
			lista.free();
			lista = NumberGenerator::generateNumbers<int>(10000000, i);
		MyBenchmarkObserver *o1 = new MyBenchmarkObserver();
		ObservableHeapSorter<int> heapSorter(lista);
		ObservableQuickSorter<int> quickSorter(lista);
		ObservableMergeSorter<int> mergeSorter(lista);
		heapSorter.add(o1);
		quickSorter.add(o1);
		mergeSorter.add(o1);



		heapSorter.sort();
		writeStringToFile("log.txt", heapSorter.observaters[0].content->getTimerValue());
		writeStringToFile("log.txt", "\t");

		quickSorter.sort();
		writeStringToFile("log.txt", heapSorter.observaters[0].content->getTimerValue());
		writeStringToFile("log.txt", "\t");

		mergeSorter.sort();
		writeStringToFile("log.txt", heapSorter.observaters[0].content->getTimerValue());
		writeStringToFile("log.txt", "\n");
		}

	std::cout<<std::endl;
	return 0;
}
