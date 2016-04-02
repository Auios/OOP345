#include "Message.h"

using namespace std;

namespace w5
{
	Message::Message()
	{

	}
	Message::Message(std::ifstream& in, char c)
	{
		string line;
		getline(in, line, c);
		if (in.eof())
		{
			//cout << "EOF\n";
			return;
		}
		auto cr = line.find('\r');
		if (cr != string::npos)
		{
			line.erase(line.begin() + cr);
		}

		//cout << "read -->" << line << "<--\n";

		int index = 0;

		while (index <= line.size() && line[index] != ' ')
		{
			name += line[index];
			index++;
		}
		//cout << "name -->" << name << "<--\n";
		if (index == line.size())
			return;
		index++;
		if (index < line.size() && line[index] == '@')
		{
			index++;
			while (index <= line.size() && line[index] != ' ')
			{
				reply += line[index];
				index++;
			}
		}
		
		//cout << "reply -->" << reply << "<--\n";
		if (index == line.size())
			return;
		//index++;
		
		while (index < line.size())
		{
			tweet += line[index];
			index++;
		}
		
		//cout << "tweet -->" << tweet << "<--\n";
	}
	bool Message::empty() const
	{
		return tweet.empty();
	}
	void Message::display(std::ostream&) const
	{
		if (reply.empty())
		{
			cout << " User  : " << name << "\n" << " Tweet : " << tweet << endl << endl;
		}
		else
		{
			cout << " User  : " << name << "\n Reply : " << reply << "\n Tweet : " << tweet << endl << endl;
		}
		
	}
}