#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap robot1;
	DiamondTrap robot2("Bob");
	DiamondTrap robot3("Tom");

	robot1.whoAmI();
	robot1.attack("Bob");
	robot1.takeDamage(23);
	robot1.beRepaired(23);
	robot1.highFiveGuys();
	robot1.takeDamage(10000);
	robot3 = robot1;
	robot1.attack("Bob");
	robot1.beRepaired(23);

	robot2.whoAmI();
	robot2.attack("Tom");
	robot2.takeDamage(23);
	robot2.beRepaired(23);
	robot2.highFiveGuys();
	robot2.takeDamage(10000);
	robot2.attack("Bob");
	robot2.beRepaired(23);

	robot3.whoAmI();
	robot3.attack("Bob");
}
