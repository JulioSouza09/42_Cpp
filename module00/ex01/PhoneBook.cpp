#include "include/PhoneBook.h"

PhoneBook::PhoneBook() {
	this->index = 0;
}

void PhoneBook::addContact(Contact contact) {
	this->contacts[this->index % MAX_CONTACTS] = contact;
	this->index++;
}

void PhoneBook::listContacts(void) {
	for (int i = 0; i < MAX_CONTACTS; i++) {
		contacts[i].printContactColumn(i);
	}
}

void PhoneBook::printContact(int index) {
	contacts[index].printContact();
}
