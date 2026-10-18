#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	this->name = "Fr4gTr4p";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
    std::cout << "New FragTrap instance with the name '" << this->name << "'." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
    std::cout << "New FragTrap instance with the name '" << this->name << "'." << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
    std::cout << "New FragTrap instance copy of '" << copy.name << "'." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &copy) {
	if (this != &copy) {
		// ClapTrap object automatically assigns to 'this' because it is part of FragTrap
		ClapTrap::operator=(copy);
	}
	return *this;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap instance with name '" << this->name << "' destroyed." << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (this->energyPoints == 0) {
		std::cout << this->name << " does not have enough energy points!" << std::endl;
		return ;
	}
	else if (this->hitPoints == 0) {
		std::cout << name << " does not have hit points remaining!" << std::endl;
		return ;
	}
    std::cout << "Scared of being attacked first, " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}

void FragTrap::highFiveGuys(void) {
	std::cout << "Lemme get a high five guys!!" << std::endl;
}

