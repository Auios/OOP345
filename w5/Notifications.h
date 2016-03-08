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
		Notifications() : count(0), msgTable(new Message[MAX_TABLE_SIZE])
		{

		}

		Notifications(const Notifications& rhs)
		{
			msgTable = 0;
			*this = rhs;
		}

		Notifications& operator=(const Notifications& rhs)
		{
			if (this != &rhs)
			{
				if (msgTable)
				{
					delete[] msgTable;

					msgTable = 0;
					count = 0;

					if (rhs.msgTable)
					{
						count = rhs.count;
						msgTable = new Message[MAX_TABLE_SIZE];

						//Deep copy
						for (int i = 0; i < count; i++)
						{
							msgTable[i] = rhs.msgTable[i];
						}
					}
				}
				return *this;
			}
		}

		Notifications(Notifications&& rhs)
		{
			msgTable = 0;
			*this = std::move(rhs);

		}

		Notifications&& operator=(Notifications&& rhs)
		{
			if (this != &rhs)
			{
				if (msgTable) delete[] msgTable;

				msgTable = 0;
				count = 0;

				//Move pointers (Steal brains)
				count = rhs.count;
				msgTable = rhs.msgTable;

				//Mark rhs as 'no brains' - a zombie
				rhs.count = 0;
				rhs.msgTable = 0;
			}
			return std::move(*this);
		}

		~Notifications()
		{
			if (msgTable) delete [] msgTable;
		}

		void operator+=(const Message& msg) //Add message to the set
		{
			if (count < MAX_TABLE_SIZE)
			{
				msgTable[count] = msg;
				count++;
			}
		}

		void display(std::ostream& os) //Inster the Message objects to the os output stream
		{
			os << "We have " << count << " tweets.\n";

			for (int i = 0; i < count; i++)
			{
				msgTable[i].display(os);
			}
		}

	};
}