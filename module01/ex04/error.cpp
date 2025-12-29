#include "error.h"

int	error(std::string message) {
	std::cerr << "gigased: " << message << std::endl;
	return (1);
}
