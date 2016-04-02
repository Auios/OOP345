#include <iostream>
#include <cstring>
#include "Process.h"
#include "CString.h"

void process(const char* s){
	w1::CString tmp(s);
	std::cout << tmp << std::endl;
}