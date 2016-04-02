#include "Notifications.h"
#include "Message.h"

using namespace std;

namespace w5
{
	Notifications::Notifications()
	{
		msgTable = new Message[10];
		count = 0;
	}
	Notifications::Notifications(const Notifications& N)
	{
		msgTable = nullptr;
		*this = N;
	}
	Notifications& Notifications::operator=(const Notifications& N)
	{
		if (this != &N)
		{
			if (msgTable)
				delete[] msgTable;
			msgTable = 0;
			count = 0;
			if (N.msgTable)
			{
				count = N.count;
				msgTable = new Message[10];
				for (int x = 0; x < count; x++)
				{
					cout << x << endl;
					msgTable[x] = N.msgTable[x];
					cout << x << endl;
				}
			}
		}

		return *this;
	}
	Notifications::Notifications(Notifications&& N)
	{
		msgTable = nullptr;
		*this = std::move(N);
	}
	Notifications&& Notifications::operator=(Notifications&& N)
	{
		if (this != &N)
		{
			if (msgTable)
				delete[] msgTable;
			msgTable = nullptr;
			count = 0;

			count = N.count;
			msgTable = N.msgTable;

			N.count = 0;
			N.msgTable = 0;
		}

		return std::move(*this);
	}
	Notifications::~Notifications()
	{
		if(msgTable) delete[] msgTable;
	}
	void Notifications::operator+=(const Message& msg)
	{
		if (count < 10)
		{
			msgTable[count] = msg;
			count++;
		}
	}
	void Notifications::display(std::ostream& os) const
	{
		//os << "We have " << count << " tweets\n";

		for (int x = 0; x < count; x++)
		{
			cout << "Message\n";
			msgTable[x].display(os);
		}
	}
}