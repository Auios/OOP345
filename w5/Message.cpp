#include "Message.h"

namespace w5
{

	bool Message::empty()
	{
		return tweet.empty();
	}

	void Message::display(std::ostream& os)
	{
        /*
		os << " Name  : " << name << "\n";
		os << " Reply : " << reply << "\n";
		os << " Tweet : " << tweet << "\n";
        */
	}

	Message::Message(std::ifstream& in, char c)
	{
		std::string line;
		getline(in, line, c);
		if (in.eof())
		{
			//std::cout << "EOF\n";
			return;
		}

		auto cr = line.find("\r");
		if (cr != std::string::npos)
		{
			line.erase(line.begin() + cr);
		}

		//std::cout << "read -->" << line << "<==\n";

		int index = 0;

		while (index < line.size() && line[index] != ' ')
		{
			name += line[index];
			index++;
		}
        
        std::cout << "Message\n";
		//Print name
		std::cout << " Name  : " << name << "\n";

		if (index == line.size())
		{
            std::cout << "\n";
			return;
		}

		index++; //Skip space

		if (index < line.size() && line[index] == '@')
		{
			index++; //Skip @ symbol

			while (index < line.size() && line[index] != ' ')
			{
				reply += line[index];
				index++;
			}

			if (!reply.empty())
			{
				std::cout << " Reply : " << reply << "\n";
			}

			if (index == line.size())
			{
				//EOL
                std::cout << "\n";
				return;
			}

			index++; //Skip space

			while (index < line.size())
			{
				tweet += line[index];
                index++;
			}
		}
        
        if (!tweet.empty())
        {
            std::cout << " Tweet : " << tweet << "\n";
        }
        std::cout << "\n";
	}
}