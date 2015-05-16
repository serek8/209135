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
#include "linkedlist.h"
#include "mybenchmark.h"
#include "observable.h"
#include "observer.h"
#include "observableheapsorter.h"
#include "observablequicksorter.h"
#include "observablemergesorter.h"
#include "filestreamer.h"

#define ILOSC_LICZB_DO_SORTOWANIA 1000

int main(int argc, char *argv[])
{
	LinkedList<int> lista;
	//int isSetN = 0;
	int opt;	/// Zmienna uzywana przez GETOPT
	while ((opt = getopt(argc, argv, "n:o:i:gx")) != -1) {
		switch(opt){
		case 'n':	// ilosc liczb do przetworzenia
			lista = NumberGenerator::generateNumbers<int>(10000000, atoi(optarg));
			//isSetN = 1;
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


		std::cout<<"\n -> Prosze czekac trwa sortowanie\n";

		clearFile("log.txt");
		writeStringToFile("log.txt", "Ilosc\t");
		writeStringToFile("log.txt", "HeapS.\t");
		writeStringToFile("log.txt", "QuickS.\t");
		writeStringToFile("log.txt", "MergeS.\n");
		for(int i=ILOSC_LICZB_DO_SORTOWANIA; i<ILOSC_LICZB_DO_SORTOWANIA*10; i+=ILOSC_LICZB_DO_SORTOWANIA)
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


		writeStringToFile("log.txt", i);
		writeStringToFile("log.txt", "\t");

		heapSorter.sort();
		writeStringToFile("log.txt", heapSorter.observaters[0]->getTimerValue());
		writeStringToFile("log.txt", "\t");
		heapSorter.list.free();

		quickSorter.sort();
		writeStringToFile("log.txt", quickSorter.observaters[0]->getTimerValue());
		writeStringToFile("log.txt", "\t");
		quickSorter.list.free();

		mergeSorter.sort();
		writeStringToFile("log.txt", mergeSorter.observaters[0]->getTimerValue());
		writeStringToFile("log.txt", "\n");
		mergeSorter.list.free();
		}

	std::cout<<" -> Sortowanie zakonczone\n";
	std::cout<<" -> Zapisano do pliku log.txt\n";
	std::cout<<std::endl;
	return 0;
}
