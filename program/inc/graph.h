/*
 * graph.h
 *
 *  Created on: May 30, 2015
 *      Author: serek8
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
#define MAX 128
using namespace std;

class Graph
{
public:
	 bool M[MAX][MAX];  /// macierz numerów/indexów
	 int colour[MAX];	/// tablica kolorów
	 int biggestValue;	  //  @najwieksza liczba jaka zostala uzyta - optymalizacja
	 int num; // po tylku krokach znajdujemy wszystkie sciezki

	 /**	@Znajduje najkrótszą drogę i wypusuje ją na ekran
	  * 	@param fromNumber star poszukiwan
	  * 	@param endNumber Koniec poszukiwan
	  */
	 void virtual findShortestPath(int fromNumber, int toNumber) = 0;

	 virtual ~Graph() {}

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

/**	@brief Wyświetla graf
 *
 */
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
	  /**
	   * @brief Zwalniam zasoby i przygotowuje do nowego rozruchu
	   */
	  void virtual clean() = 0 ;
};


#endif /* GRAPH_H_ */
