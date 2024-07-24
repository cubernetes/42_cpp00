#pragma once

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
public:
	// constructors
	PhoneBook();

	bool add_contact();
	bool search_contacts();
	bool select_contact(int max);
private:
	Contact _contacts[MAX_CONTACTS];
	int _idx_oldest;
};

