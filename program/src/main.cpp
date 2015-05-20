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
#include "avltree.h"

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


	AVL tree;
	AVLNode *node;

	node= new AVLNode();	node->key = 3;
	tree.insert(node);
	tree.walk(tree.root);

	node= new AVLNode();	node->key = 5;
	tree.insert(node);
	tree.walk(tree.root);

	node= new AVLNode();	node->key = 5;
	tree.insert(node);
	tree.walk(tree.root);

	tree.search(5);

	std::cout<<std::endl;
	return 0;
}
