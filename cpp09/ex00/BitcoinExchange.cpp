#include "BitcoinExchange.hpp"


void	BitcoinExchange::get_input_file_data(const char *file) {
	this->file_path = file;
	std::ifstream file_stream(file);
	std::stringstream file_data_stream;
	file_data_stream << file_stream.rdbuf();

	
}

void	BitcoinExchange::set_file_path(const std::string path) {
	this->file_path = path;
}

void	BitcoinExchange::set_file_data(const std::map<std::string, long long> data) {
	this->file_data = data;
}

const std::string& BitcoinExchange::get_file_path() const {
	return this->file_path;
}

std::string& BitcoinExchange::get_file_path() {
	return this->file_path;
}

const std::map<std::string, long long>& BitcoinExchange::get_file_data() const {
	return this->file_data;
}

std::map<std::string, long long> BitcoinExchange::get_file_data() {
	return this->file_data;
}

BitcoinExchange::BitcoinExchange() : file_path(""), file_data("", 0) {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
: file_path(other.file_path), file_data(other.file_data) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->file_path = other.file_path;
		this->file_data = other.file_data;
	}
	return *this
}