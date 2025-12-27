#include "include/PhoneBook.h"

PhoneBook::PhoneBook() {
	this->index = 0;
	this->contactCount = 0;
}

PhoneBook::~PhoneBook() {};

void PhoneBook::addContact(Contact contact) {
	this->contacts[this->index % MAX_CONTACTS] = contact;
	this->index++;
	if (this->contactCount < MAX_CONTACTS)
		this->contactCount++;
}

void PhoneBook::listContacts(void) {
	for (int i = 0; i < this->contactCount; i++) {
		contacts[i].printContactColumn(i);
	}
}

void PhoneBook::printContact(int index) {
	if (index < 0 || index > MAX_CONTACTS || index > this->contactCount)
		return ;
	contacts[index].printContact();
}
