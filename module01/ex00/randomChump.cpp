#include "Zombie.h"

void randomChump(std::string name) {
	if (name == "")
		return ;
	Zombie zombie(name);
	zombie.announce();
}
