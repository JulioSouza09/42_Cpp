#include <fstream>
#include "GigaSed.h"
#include "error.h"

int main(int argc, char **argv) {
	std::ifstream file;

	if (argc != 4)
		return (error("Invalid arguments"));
	file.open(argv[1]);
	if (file.fail())
		return (error("Failed opening input file"));
	GigaSed gigaSed = GigaSed(file, argv[1]);
	gigaSed.replace(argv[2], argv[3]);
}
