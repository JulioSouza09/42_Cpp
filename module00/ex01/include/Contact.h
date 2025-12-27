#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact {
private:
	std::string firstName;	
	std::string lastName;	
	std::string nickname;	
	std::string phoneNumber;	
	std::string darkestSecret;	
public:
	void setContact(
		std::string firstName,
		std::string lastName,
		std::string nickname,
		std::string phoneNumber,
		std::string darkestSecret
	);
	void printContact(void);
	void printContactColumn(int index);
	std::string truncateContact(std::string str);
};

#endif
