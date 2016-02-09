#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <fstream>
#include <iostream>

namespace w3 {

	class Text{
		std::string* strings;
		size_t nStrings;

	public:
		Text();
		Text(const std::string&);
		Text(const Text&);
		Text& operator=(const Text&);
		Text(Text&&);
		Text& operator=(Text&&);
		~Text();
		size_t size() const;

	};
}



#endif