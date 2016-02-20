#pragma once

#include <iostream>
#include "Message.h"

namespace w5
{
	//Notifications manages the messages
	class Notifications
	{
	private:
		static const int MAX_TABLE_SIZE = 10;
		Message* msgTable;
		int count;

	public:
		Notifications() : count(0), msgTable(new Message[MAX_TABLE_SIZE]){}
		Notifications(const Notifications& rhs);
		Notifications& operator=(const Notifications& rhs);
		Notifications(Notifications&& rhs);
		Notifications&& operator=(Notifications&& rhs);
		~Notifications();
		void operator+=(const Message& msg); //Add message to the set
		void display(std::ostream& os); //Inster the Message objects to the os output stream
	};
}