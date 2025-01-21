#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Validater.hpp"

class BitcoinExchange
{
	private:
		std::string	input_file_path;
		std::map<std::string, float> csv_file_data;

		std::string	calculate_value_base_in_csv_data(const std::string& line);
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void	set_input_file_path(const std::string path);
		void	set_csv_file_data(const std::map<std::string, float> data);
		const std::string& get_input_file_path() const;
		const std::map<std::string, float>& get_csv_file_data() const;

		void	processExchange();
};

#endif
