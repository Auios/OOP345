#include <iostream>

template<typename t>
void print(const t& lvalue)
{
	std::wcout << lvalue << " L-value" << std::endl;
}

template<typename t>
void print(const t&& rvalue)
{
	std::wcout << rvalue << " R-value" << std::endl;
}

int main()
{
	char broiled = 'X';
	bool makes = true;
	double trouble = 665.;
	print(broiled);
	print(broiled + 2);
	print(std::move(broiled));
	print(makes+trouble);
	print(2+10.6);
	print(L"C++11 is a better C++");
}