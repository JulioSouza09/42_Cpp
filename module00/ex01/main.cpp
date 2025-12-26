#include "include/PhoneBook.h"

std::string upperCase(std::string str) {
	std::string result;
	for (int i = 0; str[i] != '\0'; i++)
		result += std::toupper(str[i]);
	return (result);
}

int	main(void) {
	std::string userInput;
	std::string name;
	std::string phoneNumber;
	PhoneBook phoneBook;

	while (true) {
		std::cout << "Enter your command: ";
		if (!(std::cin >> userInput)) break;
		userInput = upperCase(userInput);
		if (userInput == "ADD") {
			std::cout << "Enter the name: ";
			if (!(std::cin >> name)) break;
			std::cout << "Enter the phone number: ";
			if (!(std::cin >> phoneNumber)) break;
			phoneBook.PhoneBook::addContact(name, phoneNumber);
		}
		else if (userInput == "SEARCH") {
			std::cout << "Enter the name: ";
			if (!(std::cin >> name)) break;
			phoneBook.PhoneBook::findContact(name);
		}
		else if (userInput == "EXIT")
			break ;
	}
	return (0);
}
