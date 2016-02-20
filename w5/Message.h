#pragma once

#include <fstream>
#include <iostream>
#include <string>

namespace w5
{
	class Message
	{
	private:
		std::string name, reply, tweet;
	public:
		Message()
		{

		}
		Message(std::ifstream& in, char c);
		bool empty();
		void display(std::ostream& os);
	};
}