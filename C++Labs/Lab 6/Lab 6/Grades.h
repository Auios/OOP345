#ifndef GRADES_H
#define GRADES_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>
class Grades{
	std::vector<long> SID;
	std::vector<float> Grade;
	// restrict copy/move
	Grades(const Grades&) = delete;
	Grades( Grades&&) = delete;
	Grades& operator=(const Grades&) = delete;
	Grades&& operator=(Grades&&) = delete;
public:
	Grades(const char*);
	void displayGrades(std::ostream&, std::function<std::string(float)>) const;
};

#endif
