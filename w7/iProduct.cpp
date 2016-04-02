#include <string>
#include <vector>
#include "iProduct.h"
#include "Product.h"
#include "TaxableProduct.h"

namespace w7
{
	std::ostream &operator<<(std::ostream &os, iProduct &product)
	{
		product.display(os);
		return os;
	}

	iProduct *readProduct(std::ifstream &in)
	{
		int start = 0, end = 0;
		std::vector<std::string> token;
		std::string line;
		long ID;
		double price;
		char tax;
		size_t length = line.size();

		std::getline(in, line);

		while (start < length)
		{
			end = line.find(' '), start);
			if (end == std::string::npos)
			{
				end = length;
			}
			token.push_back(line.substr(start, end - start));
			start = end + 1;
		}
		ID = std::stol(token[0]);
		price = std::stod(token[1]);
		if (token.size() > 2)
		{
			tax = token[2].c_str()[0];
		}
		if (token.size() == 2)
		{
			return new Product(ID, price);
		}
		if (tax == 'H' || tax == 'P')
		{
			return new TaxableProduct(ID, price, tax);
		}
		throw "File corrupted";
	}
}