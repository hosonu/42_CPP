#include "Sed.hpp"

Sed::Sed(std::string filename) : inFile(filename){
	this->outFile = this->inFile + ".replace";
}

Sed::~Sed() {
}

void	Sed::replace(std::string s1, std::string s2){
	std::ifstream inputFile(this->inFile);
	if(!inputFile.is_open()) {
		std::cerr << "Error: Unable to open input file." << std::endl;
		return ;
	}

	std::ofstream outputFile(this->outFile);
	if(!outputFile.is_open()) {
		std::cerr << "Error: Unable to open output file." << std::endl;
		inputFile.close();
		return ;
	}
	
	std::string line;
	while (std::getline(inputFile, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outputFile << line << std::endl;

		inputFile.close();
		outputFile.close();

		std::cout << "Replacement complete!" << outFile << std::endl;
	}
	
}