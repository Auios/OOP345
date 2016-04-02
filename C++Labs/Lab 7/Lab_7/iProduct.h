#ifndef I_PRODUCT_H
#define I_PRODUCT_H

//Workshop 7 - STL Containers
// iProduct.h

#include <iostream>
#include <fstream>

namespace w7{

	class iProduct{
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) = 0;
		virtual ~iProduct(){};
	};

	std::ostream& operator<<(std::ostream&, iProduct&);
	iProduct* readProduct(std::ifstream&);
}




#endif