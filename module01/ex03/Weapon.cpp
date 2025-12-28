#include "Weapon.h"

Weapon::Weapon(void) {
	this->type = "Bare Hands";
}

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::~Weapon(void) {}

const std::string& Weapon::getType(void) const {
	return (this->type);
}

void Weapon::setType(std::string type) {
	this->type = type;	
}
