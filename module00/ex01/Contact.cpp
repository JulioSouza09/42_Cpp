#include <iomanip>
#include "include/Contact.h"

Contact::Contact(std::string firstName, std::string lastName,
				 std::string nickname, std::string phoneNumber,
				 std::string darkestSecret) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

void Contact::printContact(void) {
	std::cout << this->firstName << std::endl;
	std::cout << this->lastName << std::endl;
	std::cout << this->nickname << std::endl;
	std::cout << this->phoneNumber << std::endl; 
}

void Contact::printContactColumn(int index) {
	std::cout << std::right;
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << truncateContact(this->firstName) << "|";
	std::cout << std::setw(10) << truncateContact(this->lastName) << "|";
	std::cout << std::setw(10) << truncateContact(this->nickname) << "|";
	std::cout << std::setw(10) << truncateContact(this->phoneNumber) << std::endl; 
}

std::string Contact::truncateContact(std::string str) {
	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 9) + ".");
}
