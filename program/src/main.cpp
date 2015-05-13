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
#include "mergesorter.h"
#include "heapsorter.h"
#include "mybenchmark.h"
#include "quicksorter.h"
//#include "dictionary.h"
#include <string>
#include "observer.h"

int main(int argc, char *argv[])
{
	MyList<int> lista;

	int opt;	/// Zmienna uzywana przez GETOPT
	while ((opt = getopt(argc, argv, "n:o:i:gx")) != -1) {
		switch(opt){
		case 'n':	// ilosc liczb do przetworzenia
			lista = NumberGenerator::generateNumbers<int>(10000000, atoi(optarg));
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



		(lista).printList();
		std::cout<<"\n+ - - - - Zaczynam sortowanie - - - +\n";

		MyBenchmark::timerStart();
		std::cout<<"\n! ! !";
		MergeSorter<int> heapSorter(lista);
		std::cout<<"\n! ! !";
		heapSorter.sort();
		std::cout<<"\nPOrownanie";
		(heapSorter).printList();
		lista.printList();
		//std::cout<<"Generuje losowe liczby:"<<MyBenchmark::timerStop()<<'\n';



	std::cout<<std::endl;
	return 0;
}
