#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

// Workshop 7 - STL Containers
// iProduct.h
#pragma once

#include <iostream>
#include <fstream>

namespace w7
{
	class iProduct
	{
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) = 0;
		virtual ~iProduct(){};
	};

	std::ostream& operator<<(std::ostream&, iProduct&);
	iProduct* readProduct(std::ifstream&);
}