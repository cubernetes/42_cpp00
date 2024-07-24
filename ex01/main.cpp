#include <cstdio>
#include <unistd.h>

#include "utils.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
	std::string input;
	PhoneBook phonebook;

	if (isatty(fileno(stdin)))
		std::cout << "You can quit at all times using CTRL+D\n";
	while (true)
	{
		if (!prompt_for_line("What do you want to do (ADD, SEARCH, EXIT)?: ", input))
			break;
		if (input == "ADD")
		{
			if (!phonebook.add_contact())
				break;
		}
		else if (input == "SEARCH")
		{
			if (!phonebook.search_contacts())
				break;
		}
		else if (input == "EXIT")
			break;
		else if (input == "")
			continue;
		else
			std::cout << "Invalid input '" << input << "'. Enter one of ADD, SEARCH or EXIT\n";
	}
	if (isatty(fileno(stdin)))
		std::cout << "Exiting.\n";
	return 0;
}
