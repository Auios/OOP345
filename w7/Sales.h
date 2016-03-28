#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "Product.h"
#include "TaxableProduct

namespace w7
{
	class Sales
	{
	private:
		std::vector<iProduct*> Products;

	public:
		Sales(const char* fileName);
		void display(std::ostream& os) const;
		~Sales();
	};
}