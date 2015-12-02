#include "stdafx.h"

#include "FileReader.h"
#include <sstream>

FileReader::FileReader(const char* aFile)
{
	Open(aFile);
}


FileReader::~FileReader()
{
	Close();
}

std::string FileReader::ReadAll()
{
	std::stringstream ss;
	std::string line;
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			ss << line << '\n';
		}
	}
	return ss.str();
}

std::vector<std::string> FileReader::ReadLines()
{
	std::vector<std::string> returnValue;
	std::string line;
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			returnValue.push_back(line);
		}
	}
	return returnValue;
}

void FileReader::Open(const char* aFile)
{
	myFile.open(aFile, std::ios::in);
}

void FileReader::Close()
{
	myFile.close();
}
