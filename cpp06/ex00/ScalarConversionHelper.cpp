#include "ScalarConversionHelper.hpp"

ScalarConversionHelper::ScalarConversionHelper(){}

ScalarConversionHelper::ScalarConversionHelper(const ScalarConversionHelper &src) {
	*this = src;
}

ScalarConversionHelper& ScalarConversionHelper::operator=(const ScalarConversionHelper &rhs) {
	(void) rhs;
	return *this;
}

ScalarConversionHelper::~ScalarConversionHelper() {}

bool ScalarConversionHelper::isChar(const std::string &literal) {
	return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool ScalarConversionHelper::isInt(const std::string &literal) {
	char *end;
	std::strtol(literal.c_str(), &end, 10);
	return *end == '\0';
}

bool ScalarConversionHelper::isFloat(const std::string &literal) {
	char *end;
	 std::strtof(literal.c_str(), &end);
	return *end == 'f' && *(end + 1) == '\0' ;
}

bool ScalarConversionHelper::isDouble(const std::string &literal) {
	char *end;
	std::strtod(literal.c_str(), &end);
	return *end == '\0' ;
}

bool ScalarConversionHelper::isPseudoFloat(float value) {
	return value == std::numeric_limits<float>::infinity() || 
			value == -std::numeric_limits<float>::infinity() || 	
				value != value;
}

bool ScalarConversionHelper::isPseudoDouble(double value) {
	return value == std::numeric_limits<double>::infinity() || 
			value == -std::numeric_limits<double>::infinity() || 	
				value != value;
}

int	ScalarConversionHelper::getTypeFromLiteral(const std::string &literal) {
	if (isChar(literal)) {
		return 1;
	} else if (isInt(literal)) {
		return 2;
	} else if(isFloat(literal)) {
		return 3;
	} else if (isDouble(literal)) {
		return 4;
	}
	return 0;
}

void ScalarConversionHelper::convertToChar(const char value) {
	if (std::isprint(value)) {
		std::cout << "char: '" << value << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

void	ScalarConversionHelper::convertToInt(long value) {
	if (value >= INT_MIN && value <= INT_MAX) {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}
}

void ScalarConversionHelper::convertToFloat(float value) {
	if (isPseudoFloat(value)) {
		std::cout << "float: " << value << "f" << std::endl;
	} else if (value >= FLT_MIN && value <= FLT_MAX){
		std::cout << "float: " << std::fixed << std::setprecision(floor(value) == value ? 1 : 6) << value << "f" << std::endl;
	} else if (value == 0) {
		std::cout << "float: 0.0f" << std::endl;
	} else
		std::cout << "float: impossible" << std::endl;
}

void ScalarConversionHelper::convertToDouble(double value) {
		if (isPseudoDouble(value)) {
			std::cout << "double: " << value << std::endl;
		} else if (value >= DBL_MIN && value <= DBL_MAX) {
			std::cout << "double: " << std::fixed << std::setprecision(floor(value) == value ? 1 : 6) << value << std::endl;
		} else if (value == 0) {
			std::cout << "double: 0.0" << std::endl;
		} else
			std::cout << "double: impossible" << std::endl;
}
