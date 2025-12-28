#include "Zombie.h"
#include <new>

Zombie* zombieHorde(int N, std::string name) {
	Zombie *horde;

	try {
		horde = new Zombie[N];
	}
	catch (const std::bad_alloc&) {
		return (NULL);
	}
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return (horde);
}
