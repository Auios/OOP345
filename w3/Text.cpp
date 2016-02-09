#include "Text.h"

namespace w3
{
	Text::Text()
	{
		setSafeEmpty();
	}

	Text::Text(char * fileName)
	{
		setSafeEmpty();

		int linesTmp = 0;
		std::string txtTmp;

		//Get number of lines
		std::ifstream ifs(fileName);
		while(std::getline(ifs,txtTmp))
		{
			++linesTmp;
		}
		lines = linesTmp;
	}

	Text::Text(const Text& from)
	{
		setSafeEmpty();
	}

	Text::~Text()
	{
		delete[] txt;
	}

	size_t Text::size() const
	{
		return lines;
	}

	void Text::setSafeEmpty()
	{
		lines = 0;
		txt = 0;
	}
}