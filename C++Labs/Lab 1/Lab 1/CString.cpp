#include <iostream>
#include <cstring>

#include "CString.h"
namespace w1{

	CString::CString(const char* s){
		if (s == nullptr)
			str[0] = '\0';
		else
			strcpy(str, s);
	}

	void CString::display(std::ostream& os) const {
		os << str;
	}

	std::ostream& operator<<(std::ostream& os, const CString& s)
	{
		static int n = 0;
		os << n++ << ": ";
		s.display(os);
		return os;
	}
}