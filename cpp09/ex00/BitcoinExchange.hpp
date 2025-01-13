#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	private:
		std::string	input_file_path;
		std::string	csv_file_path;
		std::map<std::string, long long> input_file_data;
		std::map<std::string, long long> csv_file_data;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void	set_input_file_path(const std::string path);
		void	set_csv_file_path(const std::string path);
		void	set_input_file_data(const std::map<std::string, long long> data);
		void	set_csv_file_data(const std::map<std::string, long long> data);
		const std::string& get_input_file_path() const;
		const std::string& get_csv_file_path() const;
		const std::map<std::string, long long>& get_input_file_data() const;
		const std::map<std::string, long long>& get_csv_file_data() const;

		void	parse_input_file(const char *file);
		void	validate_input_file_data();
		void	calculate_value_base_in_csv_data();
		void	output_results();
};

#endif
