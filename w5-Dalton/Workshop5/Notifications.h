#pragma once
#include "Message.h"

namespace w5
{
	class Notifications
	{
		Message* msgTable;
		int count;
	public:
		Notifications();
		Notifications(const Notifications& N);
		Notifications& operator=(const Notifications& N);
		Notifications( Notifications&& N);
		Notifications&& operator=(Notifications&& N);
		~Notifications();
		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
	};
}