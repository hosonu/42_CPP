#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	(void)src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &rhs) {
	(void) rhs;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string &literal) {
	int type = ScalarConversionHelper::getTypeFromLiteral(literal); 
	std::cout << type << std::endl;
	switch (type)
	{
		case 1:{
			ScalarConversionHelper::convertToChar(literal[0]);
			ScalarConversionHelper::convertToInt(static_cast<long>(literal[0]));
			ScalarConversionHelper::convertToFloat(static_cast<float>(literal[0]));
			ScalarConversionHelper::convertToDouble(static_cast<double>(literal[0]));
			break;
		}
		case 2: {
			long value_i = std::strtol(literal.c_str(), 0, 10);
			ScalarConversionHelper::convertToChar(static_cast<char>(value_i));
			ScalarConversionHelper::convertToInt(value_i);
			ScalarConversionHelper::convertToFloat(static_cast<float>(value_i));
			ScalarConversionHelper::convertToDouble(static_cast<double>(value_i));
			break;
		}
		case 3: {
			float value_f = std::strtof(literal.c_str(), 0);
			if (ScalarConversionHelper::isPseudoFloat(value_f)) {
				std::cout << "char: impossible" << std::endl;
			} else
				ScalarConversionHelper::convertToChar(static_cast<char>(value_f));
			ScalarConversionHelper::convertToInt(static_cast<long>(value_f));
			ScalarConversionHelper::convertToFloat(value_f);
			ScalarConversionHelper::convertToDouble(static_cast<double>(value_f));
			break;
		}
		case 4: {
			double value_d = std::strtod(literal.c_str(), 0);
			if (ScalarConversionHelper::isPseudoDouble(value_d)) {
				std::cout << "char: impossible" << std::endl;
			} else
				ScalarConversionHelper::convertToChar(static_cast<char>(value_d));
			ScalarConversionHelper::convertToInt(static_cast<long>(value_d));
			ScalarConversionHelper::convertToFloat(static_cast<float>(value_d));
			ScalarConversionHelper::convertToDouble(value_d);
			break;
		}
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
	}
}