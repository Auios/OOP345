#include "Sales.h"

namespace w7
{
	Sales::Sales(const char *fileName)
	{
		std::ifstream file(fileName);
		iProduct *product;

		if (!file)
		{
			return;
		}
		while (file.good())
		{
			try
			{
				Products.push_back(readProduct(file));
			}
			catch (const char *message)
			{
				std::cerr << message << std::endl;

				for (auto p = Products.begin(); p != Products.end(); p++)
				{
					delete *p;
				}
				Products.clear();
				file.close();
				return;
			}
		}
		file.close();
	}

	void Sales::display(std::ostream &os) const
	{
		double total = 0;
		os << std::setw(10) << "Product No"
			<< std::setw(10) << std::right << "Cost"
			<< std::left << " Taxable\n";
		os << std::fixed << std::setprecision(2);

		for (auto product = Products.begin(); product != Products.end(); product++)
		{
			os << **product << "\n";
		}

		for (int i = 0; i < Products.size(); i++)
		{
			total += Products[i]->getCharge();
		}
		
		os << std::setw(10) << std::right << "Total" << std::setw(10) << total << "\n";
	}
	
	Sales::~Sales()
	{
		Products.clear();
	}
}