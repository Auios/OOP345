#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace w5
{
	class Message
	{
		string name, reply, tweet;
	public:
		Message();
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream&) const;
	};
}