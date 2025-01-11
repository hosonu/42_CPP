#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>

class BitcoinExchange
{
	private:
		std::string	file_path;
		std::map<std::string, long long> file_data;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void	set_file_path(const std::string path);
		void	set_file_data(const std::map<std::string, long long> data);
		const std::string& get_file_path() const;
		std::string& get_file_path();
		const std::map<std::string, long long>& get_file_data() const;
		std::map<std::string, long long>& get_file_data();

		void	get_input_file_data(const char *file);
		void	validate_input_file_data();
		void	calculate_value_base_in_csv_data();
		void	output_results();
};

#endif
