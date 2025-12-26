#include "include/PhoneBook.h"

std::string upperCase(std::string str) {
	std::string result;
	for (int i = 0; str[i] != '\0'; i++)
		result += std::toupper(str[i]);
	return (result);
}

int	main(void) {
	std::string userInput;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	std::string choice;
	PhoneBook phoneBook;

	while (true) {
		std::cout << "Enter your command: ";
		if (!(std::cin >> userInput)) break;
		userInput = upperCase(userInput);
		if (userInput == "ADD") {
			std::cout << "First Name: ";
			if (!(std::cin >> firstName)) return (1);
			std::cout << "Last Name: ";
			if (!(std::cin >> lastName)) return (1);
			std::cout << "Nickname: ";
			if (!(std::cin >> nickname)) return (1);
			std::cout << "Phone Number: ";
			if (!(std::cin >> phoneNumber)) return (1);
			std::cout << "Darkest secret: ";
			if (!(std::cin >> darkestSecret)) return (1);
			phoneBook.addContact(
				firstName,
				lastName,
				nickname,
				phoneNumber,
				darkestSecret
			);
		}
		else if (userInput == "SEARCH") {
			phoneBook.PhoneBook::listContacts();
			std::cout << "Choose one: ";
			if (!(std::cin >> choice)) break;
		}
		else if (userInput == "EXIT")
			break ;
	}
	return (0);
}
