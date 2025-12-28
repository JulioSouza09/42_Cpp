#include "Zombie.h"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) {
	this->name = name;
}

void Zombie::setName(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << "* " << this->name << " has died *" << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
