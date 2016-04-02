
#include <iostream>
#include <string>
#include <fstream>
#include <sstream> // stringstream
#include <vector>
#include <cctype>
#include "util.h"

using namespace std;
class Task{
	string taskname, slots, passed, failed;
public:
	Task(std::vector<std::string> &fields){
		/*for (size_t field = 0; field < fields.size(); field++){
			cout << fields[field] << '$';
		}
		cout << "\n";*/
		auto isTaskName = [](std::string s) -> bool {
			if (isalpha(s[0]) || s[0] == '_'){
				for (size_t i = 1; i < s.size(); i++){
					if (!(isalnum(s[i]) || s[i] == ' ' || s[i] == '_'))
						return false;
				}
			}
			else{
				return false;
			}
			return true;
		};
		auto error = [](string& errorType, string& expected, string& found){
			throw errorType + " expected " + expected + " found " + found;
		};
		auto isNumber = [](string& s) -> bool{
			std::stringstream ss(s);
			int i;
			if (ss >> i)
				return true;
			else
				return false; 
		};
		switch (fields.size()){
		case 4:
			if (fields[3].empty() && isTaskName(fields[3])){
				failed = fields[3];
			}
			else
				error(string ("looking for 'failed'"), string("task name"), fields[3]);
		case 3:
			if (fields[2].empty() && isTaskName(fields[2])){
				failed = fields[2];
			}
			else
				error(string("looking for 'passed'"), string("task name"), fields[2]);
		case 2:
			if (fields[1].empty() && isNumber(fields[1])){
				failed = fields[1];
			}
			else
				error(string("looking for 'slots'"), string("task name"), fields[1]);
		case 1:
			if (fields[0].empty() && isTaskName(fields[0])){
				failed = fields[0];
			}
			else
				error(string("looking for 'task name'"), string("task name"), fields[0]);
			break;
		default:
			error(string("Field count not correct"), string("1,2,3, or 4 fields"), to_string(fields.size()) + "fields");
			;

		}
	}
};
class TaskManager {
	std::vector<Task> taskList;
public:
	TaskManager(vector<vector<string> >& d){
		try{
			for (size_t line = 0; line < d.size(); line++){
				Task t(d[line]);
			}
		}
		catch (std::string e) {
			std::cerr << e << "\n";
		}
	}
};

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
		TaskManager tm(data);
	}
	catch (string &e)
	{
		cerr << e << "\n";
	}

	return 0;
}
