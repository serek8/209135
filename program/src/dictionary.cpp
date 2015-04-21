/*
 * dictionary.cpp
 *
 *  Created on: Apr 14, 2015
 *      Author: serek8
 */

#include "dictionary.h"


	int &Dictionary::operator[](string str)
	{
		int id = str2int(str);
		//std::cerr<<"\nI fun: ";kolumnaList[id].printList();
		// jezeli sa elementy na liscie
		//std::cerr<<"\nSize listy na wejsciu do funkcji []: "<<kolumnaList[id].size();
		for(int i=0; i<kolumnaList[id].size(); i++)
		{
			if( !(kolumnaList[id][i].nazwa.compare(str)) ) // znalazlem taki sam klucz w slowniku
				return kolumnaList[id][i].number;
		}

		MyList::MyListElement elementDoWstawienia;
		elementDoWstawienia.nazwa = str;
		kolumnaList[id].push_back(elementDoWstawienia);
		return kolumnaList[id].show_back().number;

	}




	int Dictionary::str2int(string str){
		int hash=0;
		for(unsigned int i=0; ( i<LICZBA_ZNAKOW_DO_HASHU && i<str.size() );i++)
			hash += (int)str[i];
		//std::cout<<"\nHash:"<<hash;
		return hash;
	}

	int Dictionary::alfabetyczneSprawdzanieKolejnosci(string str_1, string str_2)
	{
		unsigned int dlugoscWyrazu=str_1.size();
		if(str_2.size() < str_1.size() ) dlugoscWyrazu=str_2.size();
		for(unsigned int i=0; i<dlugoscWyrazu; i++)
		{
			if((int)str_1[i] > (int)str_2[i]) return 2;
			if((int)str_1[i] < (int)str_2[i]) return 1;
		}
		if(str_1.size()>str_2.size()) return 2;
		if(str_1.size()<str_2.size()) return 1;
		else return 0;
	}


