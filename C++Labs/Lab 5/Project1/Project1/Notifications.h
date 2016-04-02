#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H
#include "Message.h"
#include <iostream>
namespace w5{
	const size_t MAX_MSG = 10;
	class Notifications{
		Message *Msgs;
		size_t size;
	public:
		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications&& operator=(Notifications&&);
		~Notifications();
		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
	};
}

#endif