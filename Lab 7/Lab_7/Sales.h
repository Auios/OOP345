#ifndef SALES_H
#define SALES_H
#include <vector>
#include <string>
#include "Product.h"
#include "TaxableProduct.h"
#include <iomanip>
namespace w7{
	class Sales{
		std::vector<iProduct*> Products;
	public:
		Sales(const char* filename);
		void display(std::ostream& os) const;
		~Sales();
	};
}


#endif
