// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
#include "Grades.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] <<
			": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}

	try
	{
		Grades grades(argv[1]);
		// define the lambda expression for letter

		std::function < std::string(double mark) > letter;

		letter = [](double m) -> std::string
		{
			std::string ret;
			if (m >= 90) ret = "A+";
			else if (m >= 80) ret = "A";
			else if (m >= 75) ret = "B+";
			else if (m >= 70) ret = "B";
			else if (m >= 65) ret = "C+";
			else if (m >= 60) ret = "C";
			else if (m >= 55) ret = "D+";
			else if (m >= 50) ret = "D";
			else ret = "F";

			return ret;
		};
		grades.displayGrades(std::cout, letter);

	}
	catch (std::string& e)
	{
		std::cerr << "It threw: '" << e << "'\n";
	}

	std::cout << "Press any key to continue ... ";
	std::cin.get();
}