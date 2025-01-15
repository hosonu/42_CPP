#ifndef VALIDATER_HPP
#define VALIDATER_HPP

#include <string>
#include <exception>
#include <fstream>

class Validater
{
	public:
		static void validate_argument(int argc, char *argv[]);
		static void validate_csv_data(const std::string path);
	
	private:
		Validater();
		~Validater();
		Validater(const Validater &other);
		Validater &operator=(const Validater &other);
};

#endif
