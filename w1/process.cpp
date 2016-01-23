#include "process.h"
#include "CString.h"

void process(char *s)
{
	w1::CString cs(s);

	cs.display(std::cout);
	std::cout << "\n";;
}