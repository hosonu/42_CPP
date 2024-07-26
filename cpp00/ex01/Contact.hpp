# ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <sstream>
# include <cstdlib>

class Contact {
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenumber;
		std::string darkestsecrets;

		static std::string truncate(const std::string& str);

	public:
		Contact();
		~Contact();
		void	setContact(const std::string& fname, const std::string& lname, 
                	const std::string& nname, const std::string& phone, 
                    const std::string& secret);
		void	display()	const;
		std::string	getDisplayString()	const;
};

#endif