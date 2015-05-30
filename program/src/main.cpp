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
#include "bfs.h"
#include "graph.h"

int main(int argc, char *argv[])
{

	Graph &graf = *new DFS();
	graf.addEdge(0, 1);
	graf.addEdge(1, 2); graf.addEdge(2, 4);
	graf.addEdge(1, 3); graf.addEdge(3, 5); graf.addEdge(5, 6);
	graf.addEdge(1, 12); graf.addEdge(12, 16); graf.addEdge(16, 6);
	graf.addEdge(12, 6);
	graf.findShortestPath(1, 6);
	graf.clean();



	Graph &grafBFS = *new BFS();
	grafBFS.addEdge(1, 2); grafBFS.addEdge(2, 4);
	grafBFS.addEdge(1, 3); grafBFS.addEdge(3, 5); grafBFS.addEdge(5, 6);
	grafBFS.addEdge(1, 12); grafBFS.addEdge(12, 16); grafBFS.addEdge(16, 6);
	grafBFS.addEdge(12, 6);
	grafBFS.findShortestPath(1, 6);


	std::cout<<std::endl;

	return 0;
}
