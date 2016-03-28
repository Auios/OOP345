#pragma once

#include "iProduct.h"
#include <iomanip>

namespace w7
{
	class Product : public iProduct
	{
	private:
		long pID;
		double charge;

	public:
		Product(long p, double c) : pID(p), charge(c){}
		double getCharge() const;
		void display(std::ostream &os);
		~Product(){}
	};
}