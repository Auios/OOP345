#include "Message.h"
#include <iostream>

namespace w5{
	Message::Message(){}

	Message::Message(std::ifstream& file, char c){
		if (file.good()){
			std::getline(file, msg, c);
			size_t point = msg.find(' ');
			if (point != std::string::npos){
				user = msg.substr(0, point);
				msg.erase(0, point + 1);
			}
			else
				broken();
			if (msg[0] == '@'){
				point = msg.find(' ');
				if (point != std::string::npos){
					reply = msg.substr(1, point);
					msg.erase(0, point + 1);
				}
				else
					broken();
			}
			if (msg[0] == '\n')
				broken();
		}
		else{
			broken();
		}
	}
	void Message::broken(){
		msg = "";
		user = "";
		reply = "";
	}
	bool Message::empty() const{
		return msg == "";
	}

	void Message::display(std::ostream& os) const{
		std::string piece;
		size_t point = msg.find(' ');
		if (!empty()){
			os << "\nMessage" << std::endl;
			os << " User  : " << user << std::endl;
			if (!reply.empty())
				os << " Reply : " << reply << std::endl;
			os << " Tweet : " << msg << std::endl;
		}
	}
	Message& Message::operator=(const Message& src){
		msg = src.msg;
		user = src.user;
		reply = src.reply;
		return *this;
	}
}