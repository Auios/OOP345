#include "Grades.h"
Grades::Grades(const char* f){
	std::fstream file(f);
	long sid;
	float gr;

	if (file.good()){
		std::string t;
		size_t count = 0;
		while (std::getline(file, t))
			count++;
		file.clear();
		file.seekg(0);
		for (size_t i = 0; i < count; i++){
			file >> sid;
			SID.push_back(sid);
			file >> gr;
			Grade.push_back(gr);
			file.get();
		}
	}
	else
		throw "File broken";
	file.close();
}

void Grades::displayGrades(std::ostream& os, std::function<std::string(float)> letter) const{
	for (int i = 0; i < SID.size(); i++){
		os << SID[i] << " " << Grade[i] << " " << letter(Grade[i]) << std::endl;
	}
}


