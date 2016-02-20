#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <functional>

class Grades
{
private:
	size_t count;
	struct studentEntry
	{
		double studentMark;
		std::string studentNumber;
	} *studentTable;

public:
	Grades() : count(0){}

	Grades(const char* filename) : count(0)
	{
		std::fstream is(filename);
		if (is.is_open())
		{
			std::string line;
			while (getline(is, line))
			{
				count++;
			}

			//Reset the file to read from the beginning
			is.clear(); //Clear end of file condition
			is.seekg(0); //Put cursor back to start of file

			studentTable = new studentEntry[count];

			
			for (size_t i = 0; i < count; i++)
			{
				is >> studentTable[i].studentNumber;
				is >> studentTable[i].studentMark;
			}
			/*
			for (size_t i = 0; i < count; i++)
			{
				std::cout << studentTable[i].studentNumber << " "
					<< studentTable[i].studentMark
					<< "\n";
			}


			std::cout << "file " << filename << " has " << count << " lines.\n";
			*/

			is.close();
		}
		else
		{
			throw std::string("Grade(") + filename + ") - cannot open file\n";
		}
	}

	void displayGrades(std::ostream& os, std::function < std::string(double mark) > letter) const
	{
		for (size_t i = 0; i < count; i++)
		{
			os
				<< studentTable[i].studentNumber << " "
				<< studentTable[i].studentMark << " "
				<< letter(studentTable[i].studentMark) << "\n";
		}
	}
};