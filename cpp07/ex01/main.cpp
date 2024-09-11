#include "iter.hpp"
#include <iostream>

template<typename T>
void printElement(T& element)
{
    std::cout << element << " ";
}

template<typename T>
void doubleElement(T& element)
{
    element *= 2;
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

	std::cout << "Original array: ";
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;
	std::cout << "Doubled array: ";
	iter(intArray, 5, doubleElement<int>);
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;
	std::cout << "----------------------\n";
	std::cout << "Original array: ";
	iter(floatArray, 5, printElement<float>);
	std::cout << std::endl;
	std::cout << "Doubled array: ";
	iter(floatArray, 5, doubleElement<float>);
	iter(floatArray, 5, printElement<float>);
	std::cout << std::endl;
}