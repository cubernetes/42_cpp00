// Author: tischmid (timo42@proton.me)

#pragma once

#include <cstdio>
#include <iostream>
#include <unistd.h>

// POSIX whitespace
#define WS " \t\n\r\f\v"

std::string&
rtrim(std::string& s, const char* t = WS);

std::string&
ltrim(std::string& s, const char* t = WS);

std::string&
trim(std::string& s, const char* t = WS);

std::basic_istream<char, std::char_traits<char> >&
prompt_for_line(std::string prompt, std::string &input);

std::basic_istream<char, std::char_traits<char> >&
prompt_nonempty_trunc_line(std::string prompt, std::string &input);
