# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook	{
	private:
		static const int MAX_CONTACTS = 8;
		Contact contacts[MAX_CONTACTS];
		int contactCount;
		int oldestContactIndex;

	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContacts() const;
};

# endif
