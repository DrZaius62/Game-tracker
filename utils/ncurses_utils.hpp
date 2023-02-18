
#ifndef NCURSES_UTILS_HPP
#define NCURSES_UTILS_HPP

#include <ncurses.h>
#include <string>
#include <vector>

int center(int width, std::string str);
void printTitle(WINDOW *win, std::string title);
void printList(WINDOW *win, int highlight, std::vector<std::string> list);

#endif /*NCURSES_UTILS_HPP*/

