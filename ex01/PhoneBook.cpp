// Author: tischmid (timo42@proton.me)

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <unistd.h>

#include "utils.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

// constructors
PhoneBook::PhoneBook() {
	this->_idx_oldest = 0;
}

bool PhoneBook::add_contact() {
	Contact contact;
	std::string input;

	if (!prompt_nonempty_trunc_line("First Name: ", input))
		return false;
	contact.set_firstname(input);
	if (!prompt_nonempty_trunc_line("Last Name: ", input))
		return false;
	contact.set_lastname(input);
	if (!prompt_nonempty_trunc_line("Nickname: ", input))
		return false;
	contact.set_nickname(input);
	if (!prompt_nonempty_trunc_line("Phone Number: ", input))
		return false;
	contact.set_phonenumber(input);
	if (!prompt_nonempty_trunc_line("Darkest Secret: ", input))
		return false;
	contact.set_darkest_secret(input);
	this->_contacts[this->_idx_oldest] = contact;
	this->_idx_oldest = (this->_idx_oldest + 1) % MAX_CONTACTS;
	return true;
}

bool PhoneBook::select_contact(int max, int first) {
	std::string input;
	int idx;

	while (true) {
		if (isatty(fileno(stdin)))
			std::cout << "Select a contact (1.." << max << "): ";
		if (!prompt_nonempty_trunc_line("", input))
			return false;
		idx = std::atoi(trim(input).c_str()) - 1;
		if (idx >= 0 && idx <= max - 1)
			break;
		std::cout << "The input '" << input << "' is invalid!\n";
	}
	idx = (first - idx + MAX_CONTACTS) % MAX_CONTACTS;
	std::cout << this->_contacts[idx];
	return true;
}

bool PhoneBook::search_contacts() {
	int i;
	int idx;
	int first;
	bool empty = true;

	i = first = (this->_idx_oldest - 1 + MAX_CONTACTS) % MAX_CONTACTS;
	idx = 0;
	do {
		if (this->_contacts[i].is_initialized()) {
			empty = false;
			if (isatty(fileno(stdin)))
				std::cout << std::setw(COL_WIDTH) << idx + 1 << "|"
					<< std::setw(COL_WIDTH) << str_trunc(this->_contacts[i].get_firstname(), COL_WIDTH) << "|"
					<< std::setw(COL_WIDTH) << str_trunc(this->_contacts[i].get_lastname(), COL_WIDTH) << "|"
					<< std::setw(COL_WIDTH) << str_trunc(this->_contacts[i].get_nickname(), COL_WIDTH) << std::endl;
			idx++;
		}
		i = (i - 1 + MAX_CONTACTS) % MAX_CONTACTS;
	} while (i != first);
	if (!empty)
		return this->select_contact(idx, first);
	std::cout << "Do you hear the tumbleweeds?\n";
	return true;
}
