#include <iostream>

int main(void) {
	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPTR = &brain;
	std::string &brainREF = brain;

	std::cout << "brain = 	" << &brain << std::endl;
	std::cout << "brainPTR = 	" << brainPTR << std::endl;
	std::cout << "brainREF = 	" << &brainREF << std::endl;

	std::cout << "brain = 	" << brain << std::endl;
	std::cout << "brainPTR = 	" << *brainPTR << std::endl;
	std::cout << "brainREF = 	" << brainREF << std::endl;
	return (0);
}
