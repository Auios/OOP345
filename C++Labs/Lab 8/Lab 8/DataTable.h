#ifndef DATA_TABLE_H
#define DATA_TABLE_H
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
namespace w8{
	template <typename T>
	class DataTable{
		int width;
		int precision;
		std::vector<T> x;
		std::vector<T> y;
	public:
		DataTable(std::ifstream& file, int w, int p) : width(w), precision(p){
			T varX, varY;
			size_t count = 0;
			std::string line;
			while (std::getline(file, line))
				count++;
			file.clear();
			file.seekg(std::ios::beg);
			for (size_t i = 0; i < count; i++){
				file >> varX;
				file >> varY;
				x.push_back(varX);
				y.push_back(varY);
			}
		}

		T mean() const{
			return std::accumulate(y.begin(), y.end(), (T)0) / y.size();
		}

		T sigma() const{
			T avg = mean();
			T val1 = std::accumulate(y.begin(), y.end(), (T)0,
				[avg](T sum, T current){
				sum += pow(current - avg, 2);
				return sum;
			});
			T val2;
			if ((y.size() - 1) != 0)
				val2 = val1 / (y.size() - 1);
			else
				throw "Error, cannot divide by 0";

			return sqrt(val2);
		}

		T median() const{
			std::vector<T> sorted = y;

			std::sort(sorted.begin(), sorted.end());

			return sorted.at(sorted.size() / 2);
		}

		void regression(T& slope, T& y_intercept) const{
			T val1 = y.size() *
				std::inner_product(x.begin(), x.end(), y.begin(), (T)0);
			T val2 = std::accumulate(x.begin(), x.end(), (T)0) *
				std::accumulate(y.begin(), y.end(), (T)0);
			T val3 = val1 - val2;

			T val4 = y.size() * std::accumulate(x.begin(), x.end(), (T)0,
				[](T runningTotal, T current){
				return runningTotal + pow(current, 2);
			});
			T val5 = pow(std::accumulate(x.begin(), x.end(), (T)0), 2);

			T val6 = val4 - val5;
			slope = val3 / val6;

			y_intercept = (std::accumulate (y.begin(), y.end(), (T)0) - 
				(slope * std::accumulate(x.begin(), x.end(), (T)0))) / y.size();
		}

		void display(std::ostream& os) const{
			os << std::setw(width) << "x" << std::setw(width) << "y" << std::endl;

			for (auto i = 0; i < x.size(); i++)
			{
				os << std::setw(width) << std::setprecision(precision) << std::fixed << x[i];
				os << std::setw(width) << std::setprecision(precision) << std::fixed << y[i];
				os << std::endl;

			}
		}
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& dt){
		dt.display(os);
		return os;
	}

}
#endif