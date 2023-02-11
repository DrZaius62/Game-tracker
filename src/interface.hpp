
#ifndef     INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <string>
#include <ncurses.h>

#include "pugixml.hpp"

extern pugi::xml_node root;

void menu();

// Prints the games in category
void showList(std::string category);

#endif /*INTERFACE_HPP*/

