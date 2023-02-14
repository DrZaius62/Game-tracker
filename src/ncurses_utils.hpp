
#ifndef NCURSES_UTILS_HPP
#define NCURSES_UTILS_HPP

#include <ncurses.h>
#include <string>

void center(int width, std::string str);
void printTitle(WINDOW *win, std::string title);
void printList(WINDOW *win, std::string[] items);


#endif /*NCURSES_UTILS_HPP*/

