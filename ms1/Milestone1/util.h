#include <iostream>
#include <string>
#include <fstream>
#include <sstream> // stringstream
#include <vector>


std::string trim(std::string &s);

void csvRead(std::string fileName, char delimiter, std::vector<std::vector<std::string>> &data);