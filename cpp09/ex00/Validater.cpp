#include "Validater.hpp"

void Validater::validate_argument(int argc, char *argv[]) {
	if (argc != 2)
		throw std::invalid_argument("Error: could not open file.");
	
	std::string file_path = argv[1];
	if (file_path.empty()) {
		throw std::invalid_argument("Error: could not open file.");
	}

	std::ifstream file(file_path.c_str());
	if (!file.is_open()) {
		throw std::invalid_argument("Error: could not open file.");
	}

	if (file.peek() == std::ifstream::traits_type::eof()) {
		throw std::invalid_argument("Error: " + file_path +" is empty");
	}

	//if (file_path.find(".txt") == std::string::npos) {
	//	throw std::invalid_argument("Error: could not open file.");
	//}
}

Validater::Validater() {
}

Validater::~Validater() {
}

Validater::Validater(const Validater &other) {
	if (this != &other) {
		*this = other;
	}
}

Validater &Validater::operator=(const Validater &other) {
	if (this != &other) {
		*this = other;
	}
	return *this;
}
