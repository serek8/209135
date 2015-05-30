/*
 * dfs.h
 *
 *  Created on: May 28, 2015
 *      Author: serek8
 */

#ifndef DFS_H_
#define DFS_H_

#include <iostream>
#include "linkedlist.h"
#include "graph.h"
#define MAX 128

using namespace std;

/** @brief Klasa przedstawia przeszukiwanie grafu za pomocą DFS
 *  Umożliwia wyszukanie najkrótszej trasy do numeru.
 *
 */
class DFS:public Graph
{
public:
  LinkedList<int> currentPath;	/// @obecna znaleziona sciezka
  LinkedList<int> allPaths[MAX]; /// @lista wszystkich ścieżek do liczby
  int allPathsAmount;	///@liczba wszystkich sciezek

  DFS()
  {
		clean();
  }
  ~DFS()   {        }

  /**	@brief Znajduje wszystkie mozliwe sciezki do liczby
   * 	@param u Od tej liczby zaczynam przeszukiwanie
   * 	@param p Liczba rodzica
   */
  void findPath( int u, int p , int searchingValue) {
         colour[u] = 1;
         //cout<<u<<" zmieniam flage na szara\n";
         currentPath.push_back(u);
         if(u == searchingValue)
        	 {
        	 	 // Znalazlem TĄ LICZBE !!!
        	 	 // Dodaje teraz te liste do tablicy list wygranych allPaths
        	 	 allPaths[allPathsAmount++].cloneFrom(currentPath);
        	 	colour[u] = 0;
        	 	 return;
        	 }

         num++;
         for( int v = 0; v < biggestValue; v++ ) if( M[u][v] && v != p )
         {
             if( colour[v] == 0 ) {
            	 //cout<<u<<" -> "<<v<<"\n";
            	 findPath( v, u , searchingValue);
             }
             else if( colour[v] == 1 )
             {
            	 cout<<u<<" znalazlem szare wiec sie cofam\n";

             }
             else
             {
            	 cout<<u<<" znalazlem czarne wiec sie cofam\n";

             }
             currentPath.pop_back();
         }
         //zmieniam flage na czarna;
         colour[u] = 0;

     }

/**	@Znajduje najkrótszą drogę i wypusuje ją na ekran
 * 	@param fromNumber star poszukiwan
 * 	@param endNumber Koniec poszukiwan
 */
void findShortestPath(int fromNumber, int toNumber)
{
	findPath( fromNumber, -1 , toNumber);
	int indexOfSmallestList = 0;

	for(int i=0; i<allPathsAmount; i++)
	{
		if( allPaths[indexOfSmallestList].size() >= allPaths[i].size() )
		{
			indexOfSmallestList = i;
		}
	}
	allPaths[indexOfSmallestList].print();
}


	void clean() {
		//n =0;
		biggestValue = 0;
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				M[i][j] = 0;
		for (int i = 0; i < MAX; i++) {
			colour[i] = 0;
		}
		num = 0;
		allPathsAmount = 0;
	}
};

#endif /* DFS_H_ */
