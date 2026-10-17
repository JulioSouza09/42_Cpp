#include "ScavTrap.hpp"

int main(void) {
	ScavTrap robot1;
	ScavTrap robot2("Bob");
	ScavTrap robot3("Tom");

	robot1.attack("Bob");
	robot1.takeDamage(23);
	robot1.beRepaired(23);
	robot1.guardGate();
	robot1.takeDamage(10000);
	robot3 = robot1;
	robot1.attack("Bob");
	robot1.beRepaired(23);

	robot2.attack("Tom");
	robot2.takeDamage(23);
	robot2.beRepaired(23);
	robot2.guardGate();
	robot2.takeDamage(10000);
	robot2.attack("Bob");
	robot2.beRepaired(23);

	robot3.attack("Bob");
}
