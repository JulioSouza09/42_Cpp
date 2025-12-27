#include "Zombie.h"

Zombie *newZombie(std::string name) {
	if (name == "")
		return (NULL);
	return (new Zombie(name));
}
