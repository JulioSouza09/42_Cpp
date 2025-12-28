#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon weapon) {
	this->name = name;
	this->weapon = weapon;
}

HumanA::~HumanA(void) {}

void HumanA::attack(void) const {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
