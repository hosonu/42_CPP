#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

void	test_vector() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try {
		std::vector<int>::iterator result = easyfind(vec, 3);
		std::cout << "Vector test passed: Found value " << *result <<  std::endl;
	} catch (const std::exception& e) {
		std::cout << "Vector test failed: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator result = easyfind(vec, 6);
		std::cout << "Vector test failed: Could not find value 6 " << *result  <<  std::endl;
	} catch (const std::exception& e){
		std::cout << "Vector test passed: " << e.what() << std::endl;
	}
}

void test_list() {
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	try {
		std::list<int>::iterator result = easyfind(lst, 30);
		std::cout << "List test passed: Found value " << *result << std::endl;
	} catch (const std::exception& e) {
		std::cout << "List test failed: " << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator result = easyfind(lst, 60);
		std::cout << "List test failed: Should not find value 60 " << *result << std::endl;
	} catch (const std::exception& e) {
		std::cout << "List test passed: " << e.what() << std::endl;
	}
}

int main() {
	test_vector();
	test_list();
	return 0;
}