#include "include/PhoneBook.h"

std::string upperCase(std::string str) {
	std::string result;
	for (int i = 0; str[i] != '\0'; i++)
		result += std::toupper(str[i]);
	return (result);
}

Contact *promptContact() {	
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "First Name: ";
	if (!(std::cin >> firstName)) return (NULL);
	std::cout << "Last Name: ";
	if (!(std::cin >> lastName)) return (NULL);
	std::cout << "Nickname: ";
	if (!(std::cin >> nickname)) return (NULL);
	std::cout << "Phone Number: ";
	if (!(std::cin >> phoneNumber)) return (NULL);
	std::cout << "Darkest secret: ";
	if (!(std::cin >> darkestSecret)) return (NULL);
	return (new Contact(
			firstName,
			lastName,
			nickname,
			phoneNumber,
			darkestSecret
		)
	);
}

int	main(void) {
	std::string userInput;
	int choice;
	Contact *contact;
	PhoneBook phoneBook;

	while (true) {
		std::cout << "Enter your command: ";
		if (!(std::cin >> userInput)) break;
		//userInput = upperCase(userInput);
		if (userInput == "ADD") {
			contact = promptContact();
			if (contact == NULL)
				return (1);
			phoneBook.addContact(contact);
		}
		else if (userInput == "SEARCH") {
			phoneBook.PhoneBook::listContacts();
			std::cout << "Choose one: ";
			if (!(std::cin >> choice)) {
				std::cout << "Invalid input" << std::endl;
				break;
			}
			phoneBook.printContact(choice);
		}
		else if (userInput == "EXIT")
			break ;
	}
	return (0);
}
