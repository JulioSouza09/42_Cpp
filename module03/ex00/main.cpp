#include "ClapTrap.hpp"

int main(void) {
	ClapTrap a;
	ClapTrap b("DeathTrap");

	std::cout << "================== A ==================" << std::endl;
	a.attack("Hey");
	a.takeDamage(3);
	a.beRepaired(5);
	for (int i = 0; i < 10; i++) {
		a.attack("JoJO");
	}

	std::cout << "================== B ==================" << std::endl;
	b.attack("Jojo");
	b.takeDamage(23092033);
	b.beRepaired(10);
}
