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
#define MAX 128

using namespace std;

/** @brief Klasa przedstawia przeszukiwanie grafu za pomocą DFS
 *  Umożliwia wyszukanie najkrótszej trasy do numeru.
 *
 */
class DFS
{
public:
  bool M[MAX][MAX];   /// @macierz liczb
  bool colour[MAX];   /// @kolory do oznaczania wizyt 1-bialy, 2-szary, 3-czarny
  int biggestValue;	  //  @najwieksza liczba jaka zostala uzyta - optymalizacja
  int num; // po tylku krokach znajdujemy wszystkie sciezki

  LinkedList<int> currentPath;	/// @obecna znaleziona sciezka

  LinkedList<int> allPaths[MAX]; /// @lista wszystkich ścieżek do liczby
  int allPathsAmount;	///@liczba wszystkich sciezek

  DFS()
  {
	  //n =0;
	  biggestValue = 0;
	  for(int i=0; i<MAX; i++)
		  for(int j=0; j<MAX; j++)
			  M[i][j] = 0;
	  for(int i=0; i<MAX; i++)
		  {
		  colour[i] = 0;
		  }
	  num=0;

	  allPathsAmount=0;
  }

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




/** @Dodaje połączenia miedzy elementami
 *  Dodaje je obustronne powiązenie między nimi aby łatwiej bylo potem generować dane do testowania
 *	@param a jedna krawędz
 *	@param b druga krawędz
 */
  void addEdge(int a, int b)
  {
	  M[a][b] = 1;
	  M[b][a] = 1;
	  //n++;
	  if(a>=biggestValue) biggestValue=a+1;
	  if(b>=biggestValue) biggestValue=b+1;
  }

  void print()
  {
	  cout<<"\t";
	  for(int i=0; i<biggestValue; i++)	cout<<i<<"\t";
	  cout<<"\n";
	  for(int i=0; i<biggestValue; i++)
	  {
		  cout<<i<<"\t";
		  for(int j=0; j<biggestValue; j++)
		  {
			  cout<<M[i][j]<<"\t";
		  }
		  cout<<"\n";
	  }

  }
};

#endif /* DFS_H_ */
