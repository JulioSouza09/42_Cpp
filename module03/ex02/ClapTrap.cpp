#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Cl4pTr4p"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "New Claptrap instance with the name 'Cl4pTr4p'." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "New Claptrap instance with the name '" << name << "'." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
    std::cout << "New Claptrap instance copy of '" << copy.name << "'." << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
    if (this != &copy) {
        this->name = copy.name;
        this->hitPoints = copy.hitPoints;
        this->energyPoints = copy.energyPoints;
		this->attackDamage = copy.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap instance with name '" << this->name << "' destroyed." << std::endl;
}


void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints == 0) {
		std::cout << this->name << " does not have enough energy points!" << std::endl;
		return ;
	}
	else if (this->hitPoints == 0) {
		std::cout << name << " does not have hit points remaining!" << std::endl;
		return ;
	}
    std::cout << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->hitPoints = (amount > this->hitPoints) ? 0 : this->hitPoints - amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints == 0) {
		std::cout << this->name << " does not have enough energy points!" << std::endl;
		return ;
	}
	else if (this->hitPoints == 0) {
		std::cout << name << " does not have hit points remaining!" << std::endl;
		return ;
	}
	std::cout << this->name << " repairs itself, regaining " << amount << " hit points!" << std::endl;
	this->hitPoints += amount;
	this->energyPoints -= 1;
}
