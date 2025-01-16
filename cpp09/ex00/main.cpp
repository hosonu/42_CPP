#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	BitcoinExchange	btc; 
	try {
		Validater::validate_argument(argc, argv);
		btc.set_input_file_path(argv[1]);
		btc.processExchange();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
