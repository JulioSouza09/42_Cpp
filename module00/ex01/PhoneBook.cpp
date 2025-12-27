#include "include/PhoneBook.h"

PhoneBook::PhoneBook() {
	this->index = 0;
	for (int i = 0; i < MAX_CONTACTS; i++) {
		contacts[i] = NULL;
	}
}

PhoneBook::~PhoneBook() {
	for (int i = 0; i < MAX_CONTACTS; i++)
		delete contacts[i];
}

void PhoneBook::addContact(Contact *contact) {
	delete contacts[this->index % MAX_CONTACTS];
	this->contacts[this->index % MAX_CONTACTS] = contact;
	this->index++;
}

void PhoneBook::listContacts(void) {
	for (int i = 0; i < MAX_CONTACTS; i++) {
		if (contacts[i] == NULL)
			return ;
		contacts[i]->printContactColumn(i);
	}
}

void PhoneBook::printContact(int index) {
	if (index < 0 || index > MAX_CONTACTS || contacts[index] == NULL)
		return ;
	contacts[index]->printContact();
}
