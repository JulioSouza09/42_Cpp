#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap(), name("D14m0ndTr4p") {
	ClapTrap::name = name + "_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
    std::cout << "New DiamondTrap instance with the name '" << this->name << "'." << std::endl;
}


DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), name(name) {
	ClapTrap::name = name + "_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
    std::cout << "New DiamondTrap instance with the name '" << this->name << "'." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), name(copy.name) {}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &copy) {
	if (this != &copy) {
		ClapTrap::operator=(copy);
		this->name = copy.name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap instance with name '" << this->name << "' destroyed." << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	std::cout << "I am " << this->name << " and " << ClapTrap::name << " at the same time!" << std::endl;
}
