#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	try {
		BitcoinExchange	btc;
		Validater::validate_argument(argc, argv);
		btc.set_input_file_path(argv[1]);
		btc.processExchange();
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
