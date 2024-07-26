#include "Contact.hpp"

Contact::Contact() {
	firstname = "";
	lastname = "";
	nickname = "";
	phonenumber = "";
	darkestsecrets = "";
}

Contact::~Contact() {

}

std::string Contact::truncate(const std::string& str) {
	size_t width  = 10;
	if (str.length() > width)
		return (str.substr(0, width - 1) + ".");
	return (str);
}

void	Contact::setContact(const std::string& fname, const std::string& lname, 
					const std::string& nname, const std::string& phone,
					const std::string& secret)
{
	firstname = fname;
	lastname = lname;
	nickname = nname;
	phonenumber = phone;
	darkestsecrets = secret;
}

void	Contact::display() const {
	std::cout << "First Name: " << firstname << std::endl;
	std::cout << "Last Name: " << lastname << std::endl;
	std::cout << "Nick Name: " << nickname << std::endl;
	std::cout << "Phone Number: " << phonenumber << std::endl;
	std::cout << "Derkest Secrets: " << darkestsecrets << std::endl;
}

std::string Contact::getDisplayString() const {
	std::ostringstream oss;
	oss << std::setw(10) << truncate(firstname) << "|"
		<< std::setw(10) << truncate(lastname) << "|"
		<< std::setw(10) << truncate(nickname) << "|";
	return oss.str();
}