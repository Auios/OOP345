#include "util.h"

using namespace std;

string trim(string &s)

{
	while (!s.empty() && isspace(s[0]))
	{
		s.erase(0, 1);
	}
	while (!s.empty() && isspace(s[s.size() - 1]))
	{
		s.erase(s.size() - 1, 1);
	}

	return s;
}

void csvRead(string fileName, char delimiter, vector<vector<string>> &data)
{
	ifstream is(fileName.c_str());

	if (is.is_open())
	{
		string line;
		while (getline(is, line))
		{
			auto cr = line.find('\r');
			if (cr != string::npos)
			{
				line.erase(cr, 1);
			}
			//cout << line << "\n";
			stringstream ss(line);

			vector<string> fields;
			string field;
			while (getline(ss, field, delimiter))
			{
				trim(field);
				fields.push_back(field);
			}

			data.push_back(fields);
		}
	}
	else
	{
		throw string("Cannot open csv file ") + fileName;
	}
}