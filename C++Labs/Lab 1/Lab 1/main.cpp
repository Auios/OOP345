#include <iostream>
#include <cstring>
#include "Process.h"
#include "CString.h"

using namespace std;
using namespace w1;

int main(int argc, char* argv[]){
	
	if (argc > 1){
		std::cout << "Maximum number of characters stored : " << w1::MAX << endl;

		for (int i = 1; i < argc; i++){
			process(argv[i]);
		}
	}
	else
		std::cout << "Insufficient number of arguments (min 1)" << std::endl;
	std::cout << std::endl;

	return !(argc > 1);
}