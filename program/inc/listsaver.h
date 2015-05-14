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

template <class MyListElementType>
class ListSaver
{
	List<MyListElementType> &list;

	ListSaver(MyList<MyListElementType> &listArgument):
		list(listArgument)
	{}

	/**
	 * @brief Zapisuje liste do pliku
	 * @return Zwraca 0 gdy zapisywanie powiodlo sie
	 */
	int saveToFile(std::string nazwaPliku)
	{
		std::ofstream streamToFile;
		streamToFile.open (nazwaPliku.c_str(), std::ofstream::out);
		for(int i=0; i<list.size() ; i++)
			streamToFile << '{'<<list[i].content<<"} ";

		return 0;
	}

};





#endif /* LISTSAVER_H_ */
