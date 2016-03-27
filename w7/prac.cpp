//Practice
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void resetFile(std::fstream &file)
{
	file.clear();
	file.seekg(0);
}

int getLineCount(std::fstream &file)
{
	int lineCount = 0;
	std::string line;

	while(getline(file,line))
	{
		lineCount++;
	}

	return lineCount;
}

void readfileToVec(std::fstream &file, std::vector<std::string> &vec)
{
	
}

int main(int argc, char* argv[])
{
	std::string fileName = argv[1];
	std::fstream file(fileName.c_str());
	int lineCount = getLineCount(file);
	std::vector<std::string> data(lineCount);
	
	//std::string line;

	if(file.is_open())
	{
		std::cout << fileName << " has " << lineCount << " lines\n";
		resetFile(file);

		std::cout << data.end() << "\n";

		file.close();
	}
	else
	{
		std::cout << "Error\n";
	}

	return 0;
}

/*
file.clear();
file.seekg(0);
file.close();
*/