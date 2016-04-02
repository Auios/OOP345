#include "Station.h"
namespace w2{

	Station::Station() : Name(""), Student(0), Adult(0){}

	void Station::set(const std::string& name, unsigned student, unsigned adult){
		if (!name.empty()){
			Adult = adult;
			Student = student;
			Name = name;
		}
		else{
			Name = "";
			Student = 0;
			Adult = 0;
		}
	}

	void Station::update(PassType t, int x){
		if (x > 0){
		if (t == student)
			Student += static_cast<unsigned int>(x);
		else
			Adult += static_cast<unsigned int>(x);
		}
		else{
		
			if (t == student)
				Student -= static_cast<unsigned int>(x*-1);
			else
				Adult -= static_cast<unsigned int>(x*-1);
		}
	}

	unsigned Station::inStock(PassType t) const{
		return t == student ? Student : Adult;
	}

	const std::string& Station::getName() const{
		return Name;
	}
}