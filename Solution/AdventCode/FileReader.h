#pragma once
#include <fstream>
#include <vector>
class FileReader
{
public:
	FileReader(const char* aFile);
	~FileReader();

	std::string ReadAll();
	std::vector<std::string> ReadLines();

private:
	void Open(const char* aFile);
	void Close();

	std::fstream myFile;
};

