#include "HumanB.h"

HumanB::HumanB(std::string name) {
	this->name = name;
}

HumanB::~HumanB(void) {}

void HumanB::attack(void) const {
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon) {
	this->weapon = weapon;
}
