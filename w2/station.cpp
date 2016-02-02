//Station
#include "station.h"

namespace w2
{
	Station::Station(std::fstream& is)
	{
		std::getline(is, name, ';'); //Read station name up to the ';'. Throw away the ';'
		//std::cout << "name= -->" << name << "<--\n";
		is >> passCounts[PASS_STUDENT];
		is >> passCounts[PASS_ADULT];
		std::string s;
		std::getline(is, s); //Throw away up to EOL

		//Debug
		/*
		std::cout << "Student count = " << passCounts[PASS_STUDENT];
		std::cout << "  Adult count = " << passCounts[PASS_ADULT];
		std::cout << "\n";
		*/
	}

	void Station::report()
	{
		std::cout
			<< name
			<< " "
			<< passCounts[PASS_STUDENT]
			<< " "
			<< passCounts[PASS_ADULT]
			<< "\n";
	}

	void Station::set(const std::string& n, unsigned s, unsigned a)
	{
		name = n;
		passCounts[PASS_STUDENT] = s;
		passCounts[PASS_ADULT] = a;
	}

	void Station::update(PassType pt, int num)
	{
		passCounts[pt] += num;
	}

	unsigned Station::inStock(PassType pt) const
	{
		return passCounts[pt];
	}

	const std::string& Station::getName() const
	{
		return name;
	}
}