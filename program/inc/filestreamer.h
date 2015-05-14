/*
 * filestreamer.h
 *
 *  Created on: May 14, 2015
 *      Author: serek8
 */

#ifndef FILESTREAMER_H_
#define FILESTREAMER_H_

#include <string>
#include <fstream>
#include <iomanip>

void writeStringToFile(std::string fileName, std::string textToSave)
{
	std::ofstream streamToFile;
	streamToFile.open (fileName.c_str(), std::ofstream::app);
	streamToFile << std::fixed;
	streamToFile << std::setprecision(5) <<textToSave;
	streamToFile.close();
}
void writeStringToFile(std::string fileName, double textToSave)
{
	std::ofstream streamToFile;
	streamToFile.open (fileName.c_str(), std::ofstream::app);
	streamToFile << std::fixed;
	streamToFile<<std::setprecision(5)  << textToSave;
	streamToFile.close();
}

void writeStringToFile(std::string fileName, int textToSave)
{
	std::ofstream streamToFile;
	streamToFile.open (fileName.c_str(), std::ofstream::app);
	streamToFile << std::fixed;
	streamToFile <<std::setprecision(5) << textToSave;
	streamToFile.close();
}

void clearFile(std::string fileName)
{
	std::ofstream streamToFile;
	streamToFile.open (fileName.c_str(), std::ofstream::out  | std::ofstream::trunc);
	streamToFile.close();
}

#endif /* FILESTREAMER_H_ */
