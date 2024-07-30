# ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Sed {
	private:
		std::string inFile;
		std::string outFile;

	public:
		Sed(std::string& filename);
		~Sed();
		void	replace(std::string s1, std::string s2);
};

#endif
