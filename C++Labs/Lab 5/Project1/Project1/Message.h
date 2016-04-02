#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <iostream>
#include <fstream>
namespace w5{
	class Message{
		std::string msg;
		std::string user;
		std::string reply;
	public:
		Message();
		Message& operator=(const Message&);
		Message(std::ifstream &file, char c);
		void broken();
		bool empty() const;
		void display(std::ostream& os) const;
	};
}
#endif