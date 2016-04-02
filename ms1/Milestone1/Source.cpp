/*

#include <iostream>
#include <string>
#include <fstream>
#include <sstream> // stringstream
#include <vector>
#include <cctype>
#include "util.h"

using namespace std;



int main(int argc, char *argv[]) //char** argv
{
	if (argc != 3)
	{
		cerr << "Usage: " << argv[0] << " csv-file-name csv-delimiter-char\n";
		return 1;
	}
	string fileName = argv[1];
	char delimiter = argv[2][0];

	try
	{
		vector<vector<string>>data;
		csvRead(fileName, delimiter, data);

		for (size_t line = 0; line < data.size(); line++)
		{
			cout << line << ": ";
			for (size_t field = 0; field < data[line].size(); field++)
			{
				cout << "<" << data[line][field] << "> ";
			}
			cout << "\n";
		}
	}
	catch (string &e)
	{
		cerr << e << "\n";
	}

	return 0;
}
*/