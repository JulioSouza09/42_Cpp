#include "Zombie.h"

void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main(void) {
	Zombie *joel;
	joel = newZombie("joel");
	randomChump("Julio");
	joel->announce();
	std::cout << "* Joel is alive and eager for more brains *" << std::endl;
	joel->announce();
	std::cout << "* Joel didn't find any brain to eat *" << std::endl;
	delete joel;
	return (0);
}
