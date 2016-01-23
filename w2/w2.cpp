#include <iostream>
#include <string>
#include <fstream>

namespace w2
{
	enum PassType
	{
		PASS_STUDENT,
		PASS_ADULT,
		PASS_COUNT
	};

	class Station
	{
	private:
		std::string name;
		unsigned passCounts[PASS_COUNT];

	public:
		Station(){}// default ctor
		Station(std::fstream& is)
		{
			std::getline(is, name, ';'); //Read station name up to the ';'. Throw away the ';'
			//std::cout << "name= -->" << name << "<--\n";
			is >> passCounts[PASS_STUDENT];
			is >> passCounts[PASS_ADULT];
			std::string s;
			std::getline(is, s); //Throw away up to EOL

			//Debug
			/*
			std::cout << "Student count = " << passCounts[PASS_STUDENT];
			std::cout << "  Adult count = " << passCounts[PASS_ADULT];
			std::cout << "\n";
			*/
		}

		void report()
		{
			std::cout
				<< name
				<< " "
				<< passCounts[PASS_STUDENT]
				<< " "
				<< passCounts[PASS_ADULT]
				<< "\n";
		}

		void set(const std::string& n, unsigned s, unsigned a)
		{
			name = n;
			passCounts[PASS_STUDENT] = s;
			passCounts[PASS_ADULT] = a;
		}

		void update(PassType pt, int num)
		{
			passCounts[pt] += num;
		}

		unsigned inStock(PassType pt) const
		{
			return passCounts[pt];
		}

		const std::string& getName() const
		{
			return name;
		}
	};

	class Stations
	{
	private:
		int count;
		Station *stations;
		std::string fileName;
	public:
		~Stations()
		{
			//Write out file and update. (Truncate)
			std::fstream os(fileName, std::ios::out | std::ios::trunc);
			if (os)
			{
				// Write station count + ';' + '\n'
				// For each stations
					// write name ';' student count ' ' adult count '\n'
				os.close();
			}
			else
			{

			}
			delete[] stations;
		}

		Stations(char *dataFile)
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

		void update()
		{
			for (int i = 0; i < count; i++)
			{
				std::cout << "Station " << stations[i].getName() << ":\n";

				int s, a;

				std::cout << "Enter adult pass sales:";
				std::cin >> a;

				std::cout << "Enter student pass sales:";
				std::cin >> s;

				//std::cout << s << " ~~~ " << a << "\n"; //Debug

				unsigned numA = stations[i].inStock(PASS_ADULT);
				//std::cout << "numS=" << numA << "\n"; //Debug
				if (a < numA)
				{
					//numA -= a;
					stations[i].update(PASS_ADULT, -a);
				}
				//std::cout << "numS=" << numA << "\n"; //Debug

				unsigned numS = stations[i].inStock(PASS_STUDENT);
				//std::cout << "numS=" << numS << "\n"; //Debug
				if (s < numS)
				{
					//numS -= s;
					stations[i].update(PASS_STUDENT, -s);
				}
				//std::cout << "numS=" << numS << "\n"; //Debug
			}
		}

		void restock()
		{

		}

		void report()
		{
			for (int i = 0; i < count; i++)
			{
				std::cout
					<< "Station " << stations[i].getName() << " "
					<< stations[i].inStock(PASS_STUDENT) << " "
					<< stations[i].inStock(PASS_ADULT)
					<< ":\n";
				//stations[i].report();
			}
		}
	};
}//namespace w2

int main(int argc, char* argv[])
{
	std::cout << "\nCommand Line : ";
	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2)
	{
		std::cerr << "\nIncorrect number of arguments\n";
		return 1;
	}
	w2::Stations stations(argv[1]);
	stations.update();
	stations.restock();
	stations.report();

	std::getchar();
	return 0;
}