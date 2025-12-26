#include "include/PhoneBook.h"

PhoneBook::PhoneBook() {
	this->index = 0;
}

void PhoneBook::addContact(std::string name, std::string phoneNumber) {
	this->contacts[index % MAX_CONTACTS].name = name;
	this->contacts[index % MAX_CONTACTS].phoneNumber = phoneNumber;
	this->index++;
}

void PhoneBook::findContact(std::string name) {
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (name == this->contacts[i].name) {
			std::cout << "Contact found!\n";
			contacts[i].Contact::printContact();
			return ;
		}
	}
	std::cout << "Contact not found :(\n";
}
