/*
 * dictionary.cpp
 *
 *  Created on: Apr 14, 2015
 *      Author: serek8
 */

#include "dictionary.h"


	int &Dictionary::operator[](string str)
	{
		MyList tmpList;
		MyList::MyListElement tmpListElement;
		int id = str2int(str);
		// jezeli sa elementy na liscie
		//std::cerr<<"\nSize listy na wejsciu do funkcji []: "<<kolumnaList[id].size();
		while(kolumnaList[id].size())
		{
		//std::cerr<<"\nSize listy na wejsciu do while I []: "<<kolumnaList[id].size();
		//std::cerr<<"\nhash id:"<<id;
		tmpListElement = kolumnaList[id].pop_front();
		//std::cerr<<"\nWyjalem klucz z liczba: "<<tmpListElement.number;
			if( !(tmpListElement.nazwa.compare(str)) ) // znalazlem taki sam klucz w slowniku
				{
				//std::cerr<<"\nZnalazlem takie same klucze";
					while(tmpList.size())
					{
						kolumnaList[id].push_front(tmpList.pop_back());
					}
					kolumnaList[id].push_front(tmpListElement);
					return (kolumnaList[id]).show_front().number;
				}
			else
			{
				tmpList.push_front(tmpListElement);
			}
		}
		//Czyli nie znalazlem takiego elementu, to go tworze
		tmpListElement.number=0;
		tmpListElement.nazwa=str;
		tmpList.push_front(tmpListElement);
		kolumnaList[id] = tmpList;
		//std::cerr<<"\nZapisalem nowy element: "<<kolumnaList[id].show_front().number;
		return kolumnaList[id].show_front().number;
	}




	int Dictionary::str2int(string str){
		int hash=0;
		for(unsigned int i=0; ( i<LICZBA_ZNAKOW_DO_HASHU && i<str.size() );i++)
			hash += (int)str[i];
		//std::cout<<"\nHash:"<<hash;
		return hash;
	}


