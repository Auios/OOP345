//Stations
#include "stations.h"

namespace w2
{
	Stations::~Stations()
	{
		//Write out file and update. (Truncate)
		std::fstream os(fileName, std::ios::out | std::ios::trunc);
		if (os)
		{
			os << count << ";\n";
			for(int i=0; i < count; i++)
			{
				os << stations[i].getName() << ";" << stations[i].inStock(PASS_STUDENT) << " " << stations[i].inStock(PASS_ADULT) << "\n";
			}
			// Write station count + ';' + '\n'
			// For each stations
			// write name ';' student count ' ' adult count '\n'
			os.close();
		}
		delete[] stations;
	}

	Stations::Stations(char *dataFile)
	{
		fileName = dataFile;
		std::fstream is(dataFile, std::ios::in);
		//if (!is.is_open())
		if (!is)
		{
			std::cerr << "Cannot open file " << dataFile << "\n";
			return;
		}

		//Read station count
		is >> count;
		//std::cout << "Station count=" << count << "\n"; //Debug

		//Expect a semicolon
		char c;
		is >> c;
		if (c != ';')
		{
			std::cerr << "Not our datafile, expected a semicolon ';', but found -->" << c << "<--\n";
		}
		else
		{
			std::string s;
			getline(is, s); //Read up to end-of-line into s

			stations = new Station[count];
			for (int i = 0; i < count; i++)
			{
				//Call station and assign
				stations[i] = Station(is);
			}
		}

		is.close();
	}

	void Stations::update()
	{
		std::cout
			<< "Passes Sold :" << "\n"
			<< "-------------" << "\n";
		for (int i = 0; i < count; i++)
		{
			int s, a;

			std::cout << stations[i].getName() << "\n";

			std::cout << "Student Passes sold : ";
			std::cin >> s;

			std::cout << "Adult   Passes sold : ";
			std::cin >> a;

			//std::cout << s << " ~~~ " << a << "\n"; //Debug

			unsigned numS = stations[i].inStock(PASS_STUDENT);
			//std::cout << "numS=" << numS << "\n"; //Debug
			if (s < numS)
			{
				//numS -= s;
				stations[i].update(PASS_STUDENT, -s);
			}
			//std::cout << "numS=" << numS << "\n"; //Debug

			unsigned numA = stations[i].inStock(PASS_ADULT);
			//std::cout << "numS=" << numA << "\n"; //Debug
			if (a < numA)
			{
				//numA -= a;
				stations[i].update(PASS_ADULT, -a);
			}
			//std::cout << "numS=" << numA << "\n"; //Debug
		}
	}

	void Stations::restock()
	{
		std::cout
			<< "Passes Added :" << "\n"
			<< "--------------" << "\n";

		for(int i = 0; i < count; i++)
		{
			int s,a;

			std::cout << stations[i].getName() << ":\n";

			std::cout << "Student Passes added : ";
			std::cin >> s;
			if(s > 0)
			{
				stations[i].update(PASS_STUDENT,s);
			}

			std::cout << "Adult   Passes added : ";
			std::cin >> a;
			if(a > 0)
			{
				stations[i].update(PASS_ADULT,a);
			}
		}
	}

	void Stations::report()
	{
		std::cout
			<< "Passes in stock : Student Adult" << "\n"
			<< "-------------------------------" << "\n";

		for (int i = 0; i < count; i++)
		{
			std::cout
				<< std::setw(21) << std::left << stations[i].getName() << " "
				<< std::setw(5) << std::left << stations[i].inStock(PASS_STUDENT) << " "
				<< stations[i].inStock(PASS_ADULT) << "\n";

			/*
			std::cout
				<< "Station " << stations[i].getName() << " "
				<< stations[i].inStock(PASS_STUDENT) << " "
				<< stations[i].inStock(PASS_ADULT)
				<< ":\n";
			//stations[i].report();
			*/
		}
	}
}