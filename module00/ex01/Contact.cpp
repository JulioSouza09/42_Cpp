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
	std::cout << index << " | ";
	std::cout << this->firstName << "| ";
	std::cout << this->lastName << "| ";
	std::cout << this->nickname << "| ";
	std::cout << this->phoneNumber << std::endl; 
}
