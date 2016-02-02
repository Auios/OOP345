//Station
#pragma once

#include <iostream>
#include <string>
#include <fstream>

namespace w2
{
	enum PassType
	{
		PASS_STUDENT,
		PASS_ADULT,
		PASS_COUNT
	};

	class Station
	{
	private:
		std::string name;
		unsigned passCounts[PASS_COUNT];

	public:
		Station(){}// default ctor
		Station(std::fstream& is);
		void report();
		void set(const std::string& n, unsigned s, unsigned a);
		void update(PassType pt, int num);
		unsigned inStock(PassType pt) const;
		const std::string& getName() const;
	};
}