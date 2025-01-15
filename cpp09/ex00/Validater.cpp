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
	file.close();
}

void Validater::validate_csv_data(const std::string path) {
	std::ifstream file(path.c_str());
	if (!file.is_open()) {
		throw std::invalid_argument("Error: could not open file.");
	}

	std::string header;
	if (!std::getline(file, header)) {
		throw std::invalid_argument("Error: could not read header from csv file");
	}
	if (header != "date,exchange_rate") {
		throw std::invalid_argument("Error: invalid header in csv file");
	}

	file.close();
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
