# include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	contactCount = 0;
	oldestContactIndex = 0;
}

PhoneBook::~PhoneBook() {
}

std::string PhoneBook::getValidInput(const std::string& prompt) const {
	std::string input;

	
	while (true) {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << "Don't push Ctr + D!!!!!";	
			}
			exit(1);
		}
		if (!input.empty() && input.find_first_not_of(' ') != std::string::npos)
			break;
		std::cout << "Invalid input. Please enter a non-empty string." << std::endl;
	}
	return input;
}

void	PhoneBook::addContact() {
	
	std::string fname, lname, nname, phone, secret;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	fname = getValidInput("Enter First Name: ");
	lname = getValidInput("Enter Last Name: ");
	nname = getValidInput("Enter Nick Name: ");
	phone = getValidInput("Enter Phone Number: ");
	secret = getValidInput("Enter Darkest Secret: ");

	if (contactCount < MAX_CONTACTS) {
		contacts[contactCount].setContact(fname, lname, nname, phone, secret);
		contactCount++;
	} else {
		contacts[oldestContactIndex].setContact(fname, lname, nname, phone, secret);
		oldestContactIndex = (oldestContactIndex + 1) % MAX_CONTACTS;
	}
}

void	PhoneBook::searchContacts() const {
	if (contactCount == 0) {
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "index" << "|" << std::setw(10) << "firstname" << "|" << std::setw(10) << "lastname" << "|" << std::setw(10) << "nickname" << "|" << std::endl; 
	for (int i = 0; i < contactCount; i++) {
		std::cout << std::setw(10) << i << "|" << std::setw(10) << contacts[i].getDisplayString() << std::endl;
	}
	
	int index;
	std::string input;
	std::cout << "Enter index to display: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (true) {
		input = getValidInput("");
		std::stringstream ss(input);
		if (ss >> index && ss.eof()) {
			break;
		}
		std::cout << "Invalid input. Please enter a number: ";
	}

	if (index >= 0 && index < contactCount) {
		contacts[index].display();
	} else {
		std::cout << "Invalid Index." << std::endl;
	}
}