# include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->name = "Sc4vTr4p";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
    std::cout << "New ScavTrap instance with the name '" << this->name << "'." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
    std::cout << "New ScavTrap instance with the name '" << this->name << "'." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy){
    std::cout << "New ScavTrap instance copy of '" << copy.name << "'." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy) {
	if (this != &copy) {
		ClapTrap::operator=(copy);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap instance with name '" << this->name << "' destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->energyPoints == 0) {
		std::cout << this->name << " does not have enough energy points!" << std::endl;
		return ;
	}
	else if (this->hitPoints == 0) {
		std::cout << name << " does not have hit points remaining!" << std::endl;
		return ;
	}
    std::cout << this->name << " brutally attacks " << target << ", causing " << this->attackDamage << " points of damage! (ScavTraps are violent!)" << std::endl;
	this->energyPoints -= 1;
}

void ScavTrap::guardGate(void) {
	std::cout << this->name << " is now in Gate keeper mode!" << std::endl;
}
