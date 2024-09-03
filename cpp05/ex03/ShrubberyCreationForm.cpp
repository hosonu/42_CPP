#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
: AForm("ShrubberryCreationForm", 145, 137), target_(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src) {
	this->target_ = src.target_;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm&rhs) {
	if (this != &rhs) {
		target_ = rhs.target_;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->getSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradetoExecute())
		throw GradeTooLowException();

	std::string filename = target_ + "_shrubbery";
	std::ofstream file(filename.c_str());
	if(!file.is_open()) {
			// std::cerr << "Error: Unable to open output file." << std::endl;
			// return ;
			//is it not necessary to throw exception???
			throw std::runtime_error("Unable to open output file: " + filename);
	} 

	//print Ascii tree here to file
	file << "    /\\\n";
    file << "   /\\*\\\n";
    file << "  /\\O\\*\\\n";
    file << " /*/\\/\\/\\\n";
    file << "/\\O\\/\\*\\/\\\n";
    file << "/\\*\\/\\*\\/\\/\\\n";
    file << "/\\O\\/\\/*/\\/O/\\\n";
    file << "      ||\n";
    file << "      ||\n";
    file << "      ||\n";
	file << "  , -=-~  .-^- _\n";

    file.close();
}
