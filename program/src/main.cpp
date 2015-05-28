/*
 * main.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: serek8
 */
/** @file */
#include <iostream>
#include <unistd.h>
#include "dfs.h"

int main(int argc, char *argv[])
{

	DFS dfs;
	dfs.addEdge(0, 1);

	dfs.addEdge(1, 2); dfs.addEdge(2, 4);
	dfs.addEdge(1, 3); dfs.addEdge(3, 5); dfs.addEdge(5, 6);
	dfs.addEdge(1, 12); dfs.addEdge(12, 16); dfs.addEdge(16, 6);
	dfs.addEdge(12, 6);
	dfs.findShortestPath(0, 6);


	std::cout<<std::endl;

	return 0;
}
