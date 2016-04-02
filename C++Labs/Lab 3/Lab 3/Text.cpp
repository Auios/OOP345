#include "Text.h"

namespace w3{
	Text::Text(){
		strings = nullptr;
		nStrings = 0;
	}

	Text::~Text(){
		delete[] strings;
	}
	Text::Text(const std::string& fileName){
		if (fileName.empty())
			strings = nullptr;
		else{
			std::ifstream file(fileName);
			std::string lines;
			int nLines = 0;
			while (std::getline(file, lines)){
				++nLines;
			}
			file.close();
			strings = new std::string[nLines];
			nStrings = nLines;
			file.open(fileName);
			for (int i = 0; i < nStrings; i++)
				std::getline(file, strings[i]);
			file.close();
		}
	}
	
	Text::Text(const Text& src): strings(nullptr), nStrings(0){
		*this = src;
	}

	Text& Text::operator=(const Text& src){
		if (this != &src){
			delete[] strings;
			if (src.strings != nullptr){
				strings = new std::string[src.nStrings];
				nStrings = src.nStrings;
				for (size_t i = 0; i < nStrings; i++){
					strings[i] = src.strings[i];
				}
			}
			else{
				strings = nullptr;
				nStrings = 0;
			}
		}
		return *this;
	}

	Text::Text(Text&& src): nStrings(src.nStrings), strings(src.strings){
		src.strings = nullptr;
		src.nStrings = 0;
	}

	Text& Text::operator=(Text&& src){
		if (this != &src){
			nStrings = src.nStrings;
			strings = src.strings;
			src.nStrings = 0;
			src.strings = nullptr;
		}
		return *this;
	}

	size_t Text::size() const{
		return nStrings;
	}
	

}