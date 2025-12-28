#include "Zombie.h"

#define N_ZOMBIES 10

Zombie *zombieHorde(int N, std::string name);

int main(void) {
	Zombie *horde;

	horde = zombieHorde(N_ZOMBIES, "Angry Zombie");
	if (horde == NULL)
		return (1);
	for (int i = 0; i < N_ZOMBIES; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
