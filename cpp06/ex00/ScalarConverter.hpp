#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include "ScalarConversionHelper.hpp"

class ScalarConverter{
	private:
		ScalarConverter();//private constructor make class un instanceable
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter& operator=(const ScalarConverter &rhs);
	public:
		~ScalarConverter();
		static void convert(const std::string &literal);//static method could be called without generating instance
};

#endif
