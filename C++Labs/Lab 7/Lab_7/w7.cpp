// Workshop 8 - STL Containers
// w7.cpp

#include <iostream>
#include <string>
#include "Sales.h"

int main(int argc, char** argv) {
	if (argc != 2){
		std::cerr << argv[0] << ": incorrect number of arguments\n";
		std::cerr << "usage: " << argv[0] << " file_name\n";
		return 1;
	}

	w7::Sales sale(argv[1]);
	sale.display(std::cout);

	std::cout << "\nPress any key to contiue ...";
	std::cin.get();
}