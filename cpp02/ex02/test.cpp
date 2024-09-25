
#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

// fractionl bit = 12

int main() {

	const int ITERATIONS = 1000000;
	float floatSum = 0.0f;
	for (int i = 0; i < ITERATIONS; ++i) {
		floatSum += 0.01f;
	}

	Fixed fixedSum(0.0f);
	for (int i = 0; i < ITERATIONS; ++i) {
		fixedSum = fixedSum + Fixed(0.01f);

	}

	double exactSum = 0.01 * ITERATIONS;
	std::cout << std::fixed << std::setprecision(2);// 小数第2位まで表示
    std::cout << "浮動小数点数の結果: " << floatSum << std::endl;
	std::cout << "固定小数点数の結果: " << fixedSum << std::endl;
	std::cout << "理論上の正確な結果: " << exactSum << std::endl;

	std::cout << "\n精度の差:" << std::endl;
    std::cout << "浮動小数点数の誤差: " << std::abs(exactSum - floatSum) << std::endl;
   std::cout << "固定小数点数の誤差: " << std::abs(exactSum - fixedSum.toFloat()) << std::endl; 

	return 0;
} 
