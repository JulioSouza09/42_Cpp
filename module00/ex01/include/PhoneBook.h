#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.h"
# include <iostream>
# ifndef MAX_CONTACTS
#  define MAX_CONTACTS 8
# endif

class PhoneBook {
private:
	Contact *contacts[MAX_CONTACTS];	
	int		index;
public:
	PhoneBook();
	void addContact(Contact contact);
	void listContacts(void);
	void printContact(int index);
};

#endif
