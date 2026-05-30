#include "ClapTrap.hpp"

/*
    given:
        ClapTrap ClapTrap();
    when:
        Default constructor is called
    then:
        Set the name to 'Cl4pTr4p'
        set the hitPoints to 10
        set the energyPoint to 10
        set the attackDamage to 0
        print "New ClapTrap instance with the name 'Cl4pTr4p'." to the stdin
*/
ClapTrap::ClapTrap(void) : name("Cl4pTr4p"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "New Claptrap instance with the name 'Cl4pTr4p'." << std::endl;
}

/*
    given:
        ClapTrap ClapTrap("Fl4k");
    when:
        Default constructor is called
    then:
        Set the name to 'Fl4k'
        set the hitPoints to 10
        set the energyPoint to 10
        set the attackDamage to 0
        print "New ClapTrap instance with the name 'Fl4k'." to the stdin
*/
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

/*
    given:
        ClapTrap ClapTrap();
    when:
        Default destructor is called
    then:
        print "ClapTrap instance with the name 'Cl4pTr4p' destroyed." to the stdin
*/
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