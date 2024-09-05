#ifndef SCALARCONVERSIONHELPER_HPP
#define SCALARCONVERSIONHELPER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <limits>
#include <iomanip>
#include <cmath>
#include <cfloat>

class ScalarConversionHelper {
	private:
		ScalarConversionHelper();
		ScalarConversionHelper(const ScalarConversionHelper &src);
		ScalarConversionHelper& operator=(const ScalarConversionHelper &rhs);
		static bool isChar(const std::string &literal);
		static bool isInt(const std::string &literal);
		static bool isFloat(const std::string &literal);
		static bool isDouble(const std::string &literal);

	public:
		~ScalarConversionHelper();

		static bool isPseudoFloat(float value);
		static bool isPseudoDouble(double value);
		static int	getTypeFromLiteral(const std::string &literal);
		static void	convertToChar(const char value);
		static void	convertToInt(long value);
		static void	convertToFloat(float value);
		static void	convertToDouble(double value);
};

#endif
