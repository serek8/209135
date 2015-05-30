/*
 * bsf.h
 *
 *  Created on: May 28, 2015
 *      Author: serek8
 */

#ifndef BSF_H_
#define BSF_H_

#include <iostream>
#include "linkedlist.h"
#include "graph.h"
#define MAX 128

using namespace std;

class BFS : public Graph
{
public:
	int pi[MAX];       /// rodzic nadego elementu
    LinkedList<int> q;  ///  Reprezentuje kolejnke elementów po wizycie

    BFS()
    {
		clean();
    }
    virtual ~BFS()   {        }

    void bfs(int fromNumber, int toNumber)
    {
    	colour[fromNumber] = 1;
    	pi[fromNumber]     = 1; // czyli brak rodzica
    	q.push_back( fromNumber );
    	while ( q.size() ) {
    		int u = q[0];
    		q.pop_front();
    		for( int v = 0; v < biggestValue; v++ ) {
    			//cout<<"(test) colour:"<<colour[v]<<"\t"<<M[u][v]<<endl;
    			if( colour[v] == 0 && M[u][v] ) {
    				colour[v] = 1;
    				pi[v] = u;         // zapisuje gdzie znajduje sie rodzic danej liczby
    				if(toNumber == v) return;
    				q.push_back( v );
    			}
    		}
    		colour[u] = 2;
    	}
    }

    void findShortestPath(int fromNumber, int toNumber)
    {
    	LinkedList<int> listaDoZmianyKolejnosci;
    	int tmp=toNumber;
    	bfs(fromNumber, toNumber);
    	listaDoZmianyKolejnosci.push_front(toNumber);
    	while(1)
    	{
    		listaDoZmianyKolejnosci.push_front(pi[tmp]);
    		tmp = pi[tmp];
    		if(tmp == fromNumber) break;
    	}
    	listaDoZmianyKolejnosci.print();
    }



    void clean()
    {
    	num = 0;
    	biggestValue = 0;
    	for (int i = 0; i < MAX; i++)
    	{
    		for (int j = 0; j < MAX; j++)	M[i][j] = 0;

    		colour[i] = 0;    // ustawia numery jako biale
    		pi[i] = 1;   // ustawia rodzicow na 1

    	}
    }
};

#endif /* BSF_H_ */
