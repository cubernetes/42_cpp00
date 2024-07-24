#include <iostream>

int main(int argc, char *argv[]) {
	if (--argc)
		while(*++argv)
			while(**argv)
				std::cout << (char)toupper(*(*argv)++);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}
