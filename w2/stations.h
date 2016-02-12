//Stations
#pragma once

#include <iomanip>
#include <string>
#include "station.h"

namespace w2
{
	class Stations
	{
	private:
		int count;
		Station *stations;
		std::string fileName;
	public:
		~Stations();
		Stations(char *dataFile);
		void update();
		void restock();
		void report();
	};
}