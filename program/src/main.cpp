/*
 * main.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: serek8
 */
/** @file */
#include <iostream>
#include <unistd.h>
//#include "numbergenerator.h"
#include "tree.h"

int main(int argc, char *argv[])
{
	int opt;	/// Zmienna uzywana przez GETOPT
	while ((opt = getopt(argc, argv, "n:o:i:gx")) != -1) {
		switch(opt){
		case 'n':	// ilosc liczb do przetworzenia
			//lista = NumberGenerator::generateNumbers<int>(10000000, atoi(optarg));
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


	Tree<int> tree(5);
	tree.add(3);
	tree.add(6);
	tree.print();


	std::cout<<std::endl;
	return 0;
}
