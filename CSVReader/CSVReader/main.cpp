#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

void trim(std::string &str)
{
	while (!str.empty() && isspace(str[0]))
	{
		str.erase(0, 1);
	}
	while (!str.empty() && isspace(str[str.size() - 1]))
	{
		str.erase(str.size() - 1, 1);
	}
}

int main()
{
	char del = '|';
	std::string fileName = "data.txt";
	std::ifstream file(fileName);
	std::string lineTmp;
	std::vector<std::string> line;
	std::string dataTmp;
	std::vector<std::vector<std::string>> data;

	std::cout << "Read file\n\n";

	if (file.is_open())
	{
		while (getline(file, lineTmp))
		{
			line.push_back(lineTmp);
		}
	}
	file.close();

	std::cout << "Display file\n";
	
	//Lines
	for (int i = 0; i < line.size(); i++)
	{
		//Line stuff
		std::cout << i << ": " << line[i] << "\n";

		std::vector<std::string> dataTmpLine;

		std::stringstream ss(line[i]);

		while (getline(ss, dataTmp, del))
		{
			trim(dataTmp);
			dataTmpLine.push_back(dataTmp);
		}
		data.push_back(dataTmpLine);
	}

	//Values
	for (auto lineNum : data)
	{
		for (auto lineVal : lineNum)
		{
			std::cout << "<" << lineVal << ">";
		}
		std::cout << std::endl;
	}
	
	std::cout << "\nEnd\n";
	getchar();
	return 0;
}