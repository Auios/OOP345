#include "CString.h"
#include <cstring>

namespace w1
{
	CString::CString(char *s)
	{
		if (s == 0){ str[0] = '\0'; }
		else
		{
			for (int i = 0; i < MAX; i++)
			{
				str[i] = s[i];
				if (!s[i]){ break; }
			}
			str[MAX] = '\0';
		}
	}

	void CString::display(std::ostream& os)
	{
		os << str;
	}

	std::ostream& operator<<(std::ostream& os, CString& cs)
	{
		cs.display(os);
		return os;
	}
}