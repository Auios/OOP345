#include "Stations.h"
namespace w2{

	Stations::Stations(const char* s){

		unsigned int ad, st;
		
		std::string name;

		fName = s;
		std::fstream file(fName, std::ios::in);
		if (!file.is_open())
			std::cerr << "File is not open" << std::endl;
		else{
			file >> nSubs;

			file.get();
			file.get();

			subways = new Station[nSubs];

			for (int x = 0; x < 4; x++){
				std::getline(file, name, ';');
				file >> st >> ad;
				file.get();
				subways[x].set(name, st, ad);
			}
		}
		file.close();
	}


	Stations::~Stations(){
		std::fstream file(fName, std::ios::in | std::ios::out | std::ios::trunc);
		
		file << nSubs << ";";

		for (int x = 0; x < nSubs; x++){
			file << subways[x].getName() << ";";
			file << subways[x].inStock(Station::PassType::student) << " " << subways[x].inStock(Station::PassType::adult);
		}
		file.close();
		delete[] subways;

	}

	void Stations::update() const{
		int input;
		std::cout << "\nPasses Sold :" << std::endl;
		std::cout << "-------------" << std::endl;
		for (int x = 0; x < nSubs; x++){
			std::cout << subways[x].getName() << std::endl;
			std::cout << " Student Passes sold : ";
			std::cin >> input;
			subways[x].update(Station::PassType::student, -input);
			std::cout << " Adult   Passes sold : ";
			std::cin >> input;
			subways[x].update(Station::PassType::adult, -input);
		}
	}

	void Stations::restock() const{
		int input;
		std::cout << "\nPasses Added :" << std::endl;
		std::cout << "--------------" << std::endl;
		
		for (int x = 0; x < nSubs; x++){
			std::cout << subways[x].getName() << std::endl;
			std::cout << " Student Passes added : ";
			std::cin >> input;
			subways[x].update(Station::PassType::student, input);
			std::cout << " Adult   Passes added : ";
			std::cin >> input;
			subways[x].update(Station::PassType::adult, input);
		}
	}

	void Stations::report() const{
		std::cout << "\nPasses in Stock : Student Adult" << std::endl;
		std::cout << "-------------------------------" << std::endl;
		for (int x = 0; x < nSubs; x++){
			std::cout << std::setw(22) << std::left << subways[x].getName() << std::right;
			std::cout << std::setw(6) << std::left << subways[x].inStock(Station::PassType::student)
				<< subways[x].inStock(Station::PassType::adult) << std::endl;
		}
	}
}