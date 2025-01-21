#include "BitcoinExchange.hpp"

long	ft_strtol(const std::string& str) {
	std::stringstream ss(str);
	long	num;

	ss >> num;
	if (ss.fail()) {
		return 0;
	}
	return num;
}

bool	is_valid_date(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	int	year = ft_strtol(date.substr(0, 4));
	int	month = ft_strtol(date.substr(5, 2));
	int	day = ft_strtol(date.substr(8, 2));

	if (year <= 0 || month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}

	int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2) {
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
			days_in_month[1] = 29;
		}
	}
	if (day > days_in_month[month - 1]) {
		return false;
	}

	return true;
}

std::string	BitcoinExchange::calculate_value_base_in_csv_data(const std::string& line) {
	std::stringstream	ss(line);
	std::string			date;
	float				value;

	std::getline(ss, date, '|');
	if (!(ss >> value)) {
		return "Error: bad input => " + line;
	}

	date = date.substr(0, date.find_last_not_of(" \t") + 1);

	if (value < 0) {
		return "Error: not a positive number.";
	}
	if (value > 1000) {
		return "Error: too large a number.";
	}

	if (!is_valid_date(date)) {
		return "Error: bad input => " + line;
	}

	#ifdef DEBUG
	std::cout << "date: " << date << ", value: " << value << std::endl;
	#endif
	std::map<std::string, float>::iterator	it = this->csv_file_data.find(date);
	if (it == this->csv_file_data.end()) {
		it = this->csv_file_data.upper_bound(date);
		if (it == this->csv_file_data.begin()) {
			return "Error: date is too old";
		}
		--it;
	}

	float result = value * it->second;
	std::stringstream	result_ss;
	result_ss << date << " => " << value << " = " << result;
	return result_ss.str();
}

void	BitcoinExchange::processExchange() {
	std::ifstream file_stream(this->input_file_path.c_str());

	std::string header;
	if (!std::getline(file_stream, header)) {
		throw std::runtime_error("Error: could not read header from input file");
	}

	if (header != "date | value") {
		throw std::runtime_error("Error: invalid header in input file");
	}

	std::string line;
	while (std::getline(file_stream, line)) {
		line = calculate_value_base_in_csv_data(line);
		std::cout << line << std::endl;
	}
	file_stream.close();
}

void	BitcoinExchange::set_input_file_path(const std::string path) {
	this->input_file_path = path;
}

void	BitcoinExchange::set_csv_file_data(const std::map<std::string, float> data) {
	this->csv_file_data = data;
}

const std::string& BitcoinExchange::get_input_file_path() const {
	return this->input_file_path;
}

const std::map<std::string, float>& BitcoinExchange::get_csv_file_data() const {
	return this->csv_file_data;
}

BitcoinExchange::BitcoinExchange() : input_file_path("") ,  csv_file_data() {
	Validater::validate_csv_data("./cpp_09/data.csv");
	std::ifstream csv_file("./cpp_09/data.csv");
	std::string line;
	while (std::getline(csv_file, line)) {
		std::stringstream	ss(line);
		std::string			date;
		float				value;

		std::getline(ss, date, ',');
		ss >> value;
		if (date == "date") {
			continue;
		}
		this->csv_file_data[date] = value;
	}
	csv_file.close();
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
: input_file_path(other.input_file_path)
,  csv_file_data(other.csv_file_data) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->input_file_path = other.input_file_path;
		this->csv_file_data = other.csv_file_data;
	}
	return *this;
}
