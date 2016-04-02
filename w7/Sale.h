#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "iProduct.h"
#include "Product.h"

namespace w7
{
	class Sale
	{
	private:

	public:
		Sale(const char* f);
		void display(std::ostream &os) const;
	};
}