# include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	contactCount = 0;
	oldestContactIndex = 0;
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::addContact() {
	
	std::string fname, lname, nname, phone, secret;
	std::cout << "Enter First Name: ";
	std::getline(std::cin, fname);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lname);
	std::cout << "Enter Nick Name: ";
	std::getline(std::cin, nname);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phone);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, secret);

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

	for (int i = 0; i < contactCount; i++) {
		std::cout << std::setw(10) << i << "|" << std::setw(10) << contacts[i].getDisplayString() << std::endl;//figure out
	}
	
	int index;
	std::cout << "Enter index to display: ";
	while (!(std::cin >> index)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a number: ";
	}

	if (index >= 0 && index < contactCount) {
		contacts[index].display();
	} else {
		std::cout << "Invalid Index." << std::endl;
	}
}