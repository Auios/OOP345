#pragma once
#include <string>
#include <fstream>
#include <iostream>

namespace w3
{
	class Text
	{
	private:
		int lines;
		std::string * txt;

		void setSafeEmpty();
	public:
		Text();
		Text(char* fileName);

		Text(const Text& from);
		Text& operator=(const Text& from);

		Text(Text&&);
		Text& operator=(Text&& from);


		~Text();

		size_t size() const;
	};
}