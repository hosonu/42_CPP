#include "BitcoinExchange.hpp"
#include "Validater.hpp"

int main(int argc, char *argv[])
{
	BitcoinExchange	btc; 
	try {
		Validater::validate_argument(argc, argv);
		btc.parse_input_file(argv[1]);
		//btc.validate_input_file_data();
		//btc.calculate_value_base_in_csv_data();
		//btc.output_results();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
