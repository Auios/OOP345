#include "Text.h"

namespace w3
{
	Text::Text()
	{
		setSafeEmpty();
	}

	Text::Text(char * fileName)
	{
		std::string buffer;

		setSafeEmpty();

		//Get number of lines
		std::ifstream ifs(fileName);
		while(std::getline(ifs,buffer))
		{
			++lines;
		}
		ifs.close();
		txt = new std::string[lines];
		ifs.open(fileName);
		for(int i=0; i<lines; i++)
		{
			std::getline(ifs,txt[i]);
		}
		ifs.close();
	}

	Text::Text(const Text& from)
	{
		setSafeEmpty();
	}

	Text& Text::operator=(const Text& from)
	{
		if (this != &from)
		{
			delete[] txt;
			if (from.txt != 0)
			{
				txt = new std::string[from.lines];
				lines = from.lines;
				for (size_t i = 0; i < lines; i++)
				{
					txt[i] = from.txt[i];
				}
			}
			else
			{
				txt = 0;
				lines = 0;
			}
		}
		return *this;
	}

	Text::Text(Text&& rhs)
	{
		txt = 0;
		*this = std::move(rhs);
	}

	Text&& Text::operator= (Text&& rhs)
	{
		if (this != &rhs)
		{
			if (txt)
				delete[] txt;
			txt = rhs.txt;
			lines = rhs.lines;

			rhs.lines = 0;
			rhs.txt = 0;
		}
		else
		{
			std::cout << "Move operator called itself\n";
		}
		return std::move(*this);
	}

	Text::~Text()
	{
		if(txt)
		{
			delete[] txt;
		}
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