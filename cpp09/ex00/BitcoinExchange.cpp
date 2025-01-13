#include "BitcoinExchange.hpp"


void	BitcoinExchange::parse_input_file(const char *file) {
	std::ifstream file_stream(file);
	std::stringstream file_data_stream;
	file_data_stream << file_stream.rdbuf();
	std::string	file_data = file_data_stream.str();

	#ifdef DEBUG
	std::cout << file_data << std::flush;
	#endif

}

void	BitcoinExchange::set_input_file_path(const std::string path) {
	this->input_file_path = path;
}

void	BitcoinExchange::set_csv_file_path(const std::string path) {
	this->csv_file_path = path;
}

void	BitcoinExchange::set_input_file_data(const std::map<std::string, long long> data) {
	this->input_file_data = data;
}

void	BitcoinExchange::set_csv_file_data(const std::map<std::string, long long> data) {
	this->csv_file_data = data;
}

const std::string& BitcoinExchange::get_input_file_path() const {
	return this->input_file_path;
}

const std::string& BitcoinExchange::get_csv_file_path() const {
	return this->csv_file_path;
}

const std::map<std::string, long long>& BitcoinExchange::get_input_file_data() const {
	return this->input_file_data;
}

const std::map<std::string, long long>& BitcoinExchange::get_csv_file_data() const {
	return this->csv_file_data;
}

BitcoinExchange::BitcoinExchange()
: input_file_path("")
, csv_file_path("")
, input_file_data()
,  csv_file_data() {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
: input_file_path(other.input_file_path)
, csv_file_path(other.csv_file_path)
, input_file_data(other.input_file_data)
,  csv_file_data(other.csv_file_data) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->input_file_path = other.input_file_path;
		this->csv_file_path = other.csv_file_path;
		this->input_file_data = other.input_file_data;
		this->csv_file_data = other.csv_file_data;
	}
	return *this;
}
