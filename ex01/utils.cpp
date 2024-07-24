#include <cstdio>
#include <iostream>
#include <unistd.h>

#include "utils.hpp"

// trim from end of string (right)
std::string&
rtrim(std::string& s, const char* t)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from beginning of string (left)
std::string&
ltrim(std::string& s, const char* t)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from both ends of string (right then left)
std::string&
trim(std::string& s, const char* t)
{
    return ltrim(rtrim(s, t), t);
}

// prompt for a line,
// suppressing the prompt if the input stream is not a terminal
std::basic_istream<char, std::char_traits<char> >&
prompt_for_line(std::string prompt, std::string &input) {
	if (isatty(fileno(stdin)))
		std::cout << prompt;
	return std::getline(std::cin, input);
}

// prompt for a non-empty line that will be whitespace-truncated,
// suppressing the prompt if the input stream is not a terminal
std::basic_istream<char, std::char_traits<char> >&
prompt_nonempty_trunc_line(std::string prompt, std::string &input) {

	while (true) {
		if (isatty(fileno(stdin)))
			std::cout << prompt;

		std::basic_istream<char, std::char_traits<char> >&
		ret = std::getline(std::cin, input);

		if (ret && input.empty())
			std::cout << "Input cannot be empty!" << std::endl;
		else
		{
			input = trim(input);
			return ret;
		}
	}
}
