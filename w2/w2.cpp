//g++ -std=c++0x -o w2 -Wall w2.cpp station.cpp stations.cpp
#include <iostream>
#include "stations.h"
#include "station.h"

int main(int argc, char* argv[])
{
	std::cout << "\nCommand Line : ";
	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << ' ';
	}

	std::cout << std::endl;

	if (argc != 2)
	{
		std::cerr << "\nIncorrect number of arguments\n";
		return 1;
	}

	w2::Stations stations(argv[1]);
	stations.update();
	stations.restock();
	stations.report();

	std::getchar();
	return 0;
}