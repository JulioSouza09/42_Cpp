#include "include/Contact.h"

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
