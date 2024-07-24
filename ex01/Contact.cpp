// Author: tischmid (timo42@proton.me)

#include <iostream>

#include "Contact.hpp"

bool Contact::is_initialized() const {
	return (true
		&& !this->_firstname.empty()
		&& !this->_lastname.empty()
		&& !this->_nickname.empty()
		&& !this->_phonenumber.empty()
		&& !this->_darkest_secret.empty()
	);
}

// constructors
Contact::Contact(
	std::string firstname,
	std::string lastname,
	std::string nickname,
	std::string phonenumber,
	std::string darkest_secret
) {
	std::cout << "Let's create a user\n";
	this->_firstname = firstname;
	this->_lastname = lastname;
	this->_nickname = nickname;
	this->_phonenumber = phonenumber;
	this->_darkest_secret = darkest_secret;
	std::cout << "Done\n";
}

// getters
std::string Contact::get_firstname() const {
	return this->_firstname;
}

std::string Contact::get_lastname() const {
	return this->_lastname;
}

std::string Contact::get_nickname() const {
	return this->_nickname;
}

std::string Contact::get_phonenumber() const {
	return this->_phonenumber;
}

std::string Contact::get_darkest_secret() const {
	return this->_darkest_secret;
}

// setters
void Contact::set_firstname(std::string firstname) {
	this->_firstname = firstname;
}

void Contact::set_lastname(std::string lastname) {
	this->_lastname = lastname;
}

void Contact::set_nickname(std::string nickname) {
	this->_nickname = nickname;
}

void Contact::set_phonenumber(std::string phonenumber) {
	this->_phonenumber = phonenumber;
}

void Contact::set_darkest_secret(std::string darkest_secret) {
	this->_darkest_secret = darkest_secret;
}

Contact::operator std::string () const {
	return (""
		+ std::string("First Name     | ") + this->_firstname + "\n"
		+ std::string("Last Name      | ") + this->_lastname + "\n"
		+ std::string("Nickname       | ") + this->_nickname + "\n"
		+ std::string("Phone Number   | ") + this->_phonenumber + "\n"
		+ std::string("Darkest Secret | ") + this->_darkest_secret + "\n"
   );
}

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
	os << static_cast<std::string>(contact);
	return os;
}
