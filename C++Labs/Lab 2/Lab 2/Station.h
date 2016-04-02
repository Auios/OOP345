#ifndef STATION_H
#define STATION_H
#include <iostream>
#include <string>
namespace w2{
	class Station{
		std::string Name;
		unsigned int Student;
		unsigned int Adult;

	public:
		enum PassType { student, adult };
		Station();
		void set(const std::string&, unsigned, unsigned);
		void update(PassType, int);
		unsigned inStock(PassType) const;
		const std::string& getName() const;
	};
}

#endif
