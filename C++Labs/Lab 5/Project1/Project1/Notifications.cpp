#include "Notifications.h"
namespace w5{
	Notifications::Notifications(): Msgs(nullptr), size(0){
		Msgs = new Message[MAX_MSG];
	}

	Notifications::Notifications(const Notifications& src): size(src.size){
		Msgs = new Message[MAX_MSG];
		for (int i = 0; i < size; i++)
			Msgs[i] = src.Msgs[i];
	}
	Notifications& Notifications::operator=(const Notifications& src){
		size = src.size;
		delete[] Msgs;
		Msgs = new Message[MAX_MSG];
		for (int i = 0; i < size; i++){
			Msgs[i] = src.Msgs[i];
		}
		return *this;
	}
	Notifications::Notifications(Notifications&& src): Msgs(src.Msgs), size(src.size){
		src.Msgs = nullptr;
		src.size = 0;
	}
	Notifications&& Notifications::operator=(Notifications&& src){
		if (&src != this){
		delete[] Msgs;
		size = src.size;
		Msgs = src.Msgs;
		src.size = 0;
		src.Msgs = nullptr;
		}
		return std::move(*this);
	}
	Notifications::~Notifications(){
		delete[] Msgs;
	}
	void Notifications::operator+=(const Message& msg){
		if (size < MAX_MSG)
			Msgs[size++] = msg;
	}
	void Notifications::display(std::ostream& os) const{
		for (int i = 0; i < size; i++){
			Msgs[i].display(os);
		}
	}
}