#include "include/PhoneBook.h"
#include <sstream>

std::string upperCase(std::string str) {
	std::string result;
	for (int i = 0; str[i] != '\0'; i++)
		result += std::toupper(str[i]);
	return (result);
}

bool promptContact(std::string message, std::string &result)
{
	std::string input;

	while (input.empty()) {
		std::cout << message;
		if (std::getline(std::cin, input).fail()) {
			std::cout << std::endl << "Error" << std::endl;
			return (false);
		}
	}
	result = input;
	return (true);
}

bool strToInt(const std::string &str, int &out) {
	std::istringstream iss(str);

	iss >> out;
	return (!iss.fail() && iss.eof());
}

bool getContact(PhoneBook &phoneBook) {	
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	Contact newContact;

	if (promptContact("First Name: ", firstName) != true
		|| promptContact("Last Name: ", lastName) != true
		|| promptContact("Nickname: ", nickname) != true
		|| promptContact("Phone Number: ", phoneNumber) != true
		|| promptContact("Darkest secret: ", darkestSecret) != true)
		return (false);
	newContact.setContact(
	
		firstName,
		lastName,
		nickname,
		phoneNumber,
		darkestSecret
	);
	phoneBook.addContact(newContact);
	return (true);
}

int	main(void) {
	std::string userInput;
	std::string choice;
	int number;
	PhoneBook phoneBook;

	while (true) {
		if (promptContact("Enter the command: ", userInput) != true)
			return (1);
		//userInput = upperCase(userInput);
		if (userInput == "ADD") {
			if (getContact(phoneBook) != true)
				return (1);
		}
		else if (userInput == "SEARCH") {
			phoneBook.PhoneBook::listContacts();
			if (promptContact("Choose one: ", choice) != true)
				return (1);
			if (strToInt(choice, number) != true) {
				std::cout << "Invalid input" << std::endl;
				return (1);
			}
			phoneBook.printContact(number);
		}
		else if (userInput == "EXIT")
			break ;
	}
	return (0);
}
