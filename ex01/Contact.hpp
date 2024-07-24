// Author: tischmid (timo42@proton.me)

#pragma once

#include <iostream>

class Contact {
public:
	bool is_initialized() const;

	// constructors
	Contact() {};
	Contact(
		std::string firstname,
		std::string lastname,
		std::string nickname,
		std::string phonenumber,
		std::string darkest_secret
	);

	// getters
	std::string get_firstname() const;
	std::string get_lastname() const;
	std::string get_nickname() const;
	std::string get_phonenumber() const;
	std::string get_darkest_secret() const;
	
	// setters
	void set_firstname(std::string firstname);
	void set_lastname(std::string lastname);
	void set_nickname(std::string nickname);
	void set_phonenumber(std::string phonenumber);
	void set_darkest_secret(std::string darkest_secret);

	// conversion
	operator std::string () const;
private:
	// attributes of a contact
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phonenumber;
	std::string _darkest_secret;
};

std::ostream& operator<<(std::ostream& os, const Contact& contact);
