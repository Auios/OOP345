#include "Text.h"

namespace w3 {
	Text::Text() : name(nullptr), _size(0) {}
	Text::Text(const std::string& dataFile) {
		if (dataFile.empty())
			name = nullptr;
		else {
			std::ifstream file(dataFile);
			std::string buff;
			int numLines = 0;
			while (std::getline(file, buff)) {
				++numLines;
			}
			file.close();
			name = new std::string[numLines];
			_size = numLines;
			file.open(dataFile);
			for (int i = 0; i < numLines; i++)
				std::getline(file, name[i]);
			file.close();
		}
	}
	Text::~Text() {
		if(name)
			delete[] name;
	}
	//Text& Text::operator= (const Text& rhs) {
	//	if (this != &rhs) {
	//		if (name)
	//			delete[] name;
	//		name = nullptr;
	//		_size = 0;
	//		if (rhs.name) {
	//			_size = rhs._size;
	//			name = new std::string[_size];
	//			memcpy(name, rhs.name, _size *sizeof(int));
	//		}
	//		else {
	//			std::cout << "assignment operator called on itself\n";
	//		}
	//		
	//	}
	//	return *this;
	//}
	Text& Text::operator=(const Text& src) {
		if (this != &src) {
			delete[] name;
			if (src.name != nullptr) {
				name = new std::string[src._size];
				_size = src._size;
				for (size_t i = 0; i < _size; i++) {
					name[i] = src.name[i];
				}
			}
			else {
				name = nullptr;
				_size = 0;
			}
		}
		return *this;
	}
	Text::Text(const Text& rhs) {
		_size = 0;
		name = nullptr;
		*this = rhs;
	}
	Text&& Text::operator= (Text&& rhs) {
		if (this != &rhs) {
			if (name)
				delete[] name;
			name = rhs.name;
			_size = rhs._size;

			rhs._size = 0;
			rhs.name = nullptr;
		}
		else {
			std::cout << "move assignment operator called on itself\n";
		}
		return std::move(*this);
	}
	Text::Text(Text&& rhs) {
		name = nullptr;
		*this = std::move(rhs);
	}
	size_t  Text::size() {
		return _size;
	}
}