#include <iostream>
#include "CString.h"
#include "process.h"

int main(int argc, char *argv[], char *env[])
{
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++)
		{std::cout << argv[i] << (i == argc - 1 ? "\n" : " ");}

	if (argc == 1)
	{
		std::cerr << "Insufficient number of arguments (min 1)\n";
		return 1;
	}

	std::cout << "Maximum number of characters stored : " << w1::MAX << "\n";

	for (int i = 1; i < argc; i++)
	{
		std::cout << i << ": ";
		process(argv[i]);
	}
}