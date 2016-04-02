// Workshop 6 -Lambda Expression
// w6.cpp
#include <iostream>
#include <cmath>
#include <functional>
#include "Grades.h"
int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] <<
			": incorrect number of arguments\n";
			std::cerr << "Usage: " << argv[0] << " file_name\n";
			return 1;
	}
	try{
		Grades grades(argv[1]);
		// define the lambda expression for letter
		std::function<std::string(float)> letter = [](float grade) -> std::string {
			int gr = std::nearbyint(grade);
			std::string letter;
			if (gr >= 90)
				letter = "A+";
			else if (gr >= 80)
				letter = "A";
			else if (gr >= 75)
				letter = "B+";
			else if (gr >= 70)
				letter = "B";
			else if (gr >= 65)
				letter = "C+";
			else if (gr >= 60)
				letter = "C";
			else if (gr >= 55)
				letter = "D+";
			else if (gr >= 50)
				letter = "D";
			else if (gr < 50)
				letter = "f";
			else
				letter = "-";
			return letter;
		};
		grades.displayGrades(std::cout, letter);
		std::cout << "Press any key to continue ... ";
		std::cin.get();
	}
	catch (const char* msg){
		std::cout << msg << std::endl;
	}
}
