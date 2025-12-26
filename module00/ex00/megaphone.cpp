#include <iostream>

int	main(int argc, char **argv)
{
	std::string scream = "";

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
			scream += toupper(argv[i][j]);
	  	std::cout << scream;
		scream = "";
	}
	std::cout << "\n";
	return (0);
}
