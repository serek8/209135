/*
 * ListIO.h
 *
 *  Created on: May 14, 2015
 *      Author: serek8
 */

#ifndef LISTSAVER_H_
#define LISTSAVER_H_

#include <string>
#include <fstream>

template <class ContentType>
class ListSaver
{
	/** @brief Klasa pozwalająca na zapis Listy do pliku
	 */
	List<ContentType> &list;

	/**	@brief Konstruktor pobierajacy referencje do listy do zapisu
	 *	@param listArgument lista do zapisu
	 */
	ListSaver(MyList<ContentType> &listArgument):
		list(listArgument)
	{}

	/**
	 * @brief Zapisuje liste do pliku
	 * @return Zwraca 0 gdy zapisywanie powiodlo sie
	 */
	void saveToFile(std::string nazwaPliku)
	{
		std::ofstream streamToFile;
		streamToFile.open (nazwaPliku.c_str(), std::ofstream::out);
		for(int i=0; i<list.size() ; i++)
			streamToFile << '{'<<list[i].content<<"} ";
		streamToFile.close();
	}

};





#endif /* LISTSAVER_H_ */
