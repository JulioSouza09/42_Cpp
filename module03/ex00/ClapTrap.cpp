#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Cl4pTr4p"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "New Claptrap instance with the name 'Cl4pTr4p'." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "New Claptrap instance with the name " << name << "." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
    *this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy) {
    if (this != &copy) {
        this->name = copy.name;
        this->hitPoints = copy.hitPoints;
        this->energyPoints = copy.energyPoints;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap instance with name " << this->name << " destroyed." << std::endl;
}


void ClapTrap::attack(const std::string& target) {
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing <damage> points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount > this->hitPoints)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {}
