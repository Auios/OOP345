#ifndef _CString_H
#define _CString_H

#include <iostream>
#include <cstring>



namespace w1 {
	const int MAX = 3;
	class CString{
	private:
		char str[MAX + 1];

	public:
		CString(const char*);

		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, const CString&);
}
#endif