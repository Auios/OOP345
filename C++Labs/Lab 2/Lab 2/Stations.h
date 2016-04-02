#ifndef STATIONS_H
#define STATIONS_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Station.h"
namespace w2{
	class Stations{
		std::string fName;
		int nSubs;
		Station* subways;

	public:
		Stations(const char*);
		~Stations();
		void update() const;
		void restock() const;
		void report() const;
	};

}
#endif // !STATIONS_H
