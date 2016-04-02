#pragma once

#include <iostream>
#include "Product.h"

namespace w7
{
	class TaxableProduct : public Product
	{
	private:
		char taxType;

	public:
		static const float tax[2];
		TaxableProduct(long p, double c, char t) : Product(p, c), taxType(t){}
		double getCharge() const;
		void display(std::ostream &os);
		~TaxableProduct(){};
	};
}