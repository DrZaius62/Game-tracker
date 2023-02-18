#include "ncurses_utils.hpp"

int center(int width, std::string str){
    return (width - str.length())/2;
}

// Prints centered title for a menu
void printTitle(WINDOW *win, std::string title)
{
    int height, width;
    getmaxyx(win, height, width);
    mvwprintw(win, 1, center(width, title), title.c_str());
}

// Prints a list of items in a menu format, with highlights
void printList(WINDOW *win, int highlight, std::vector<std::string> list){
    int height, width;
    getmaxyx(win, height, width);

    for (int i = 0; i < list.size(); i++){
        if (i == highlight)
            wattron(win, A_REVERSE);
        mvwprintw(win, i+2, 1, list[i].c_str());
        wattroff(win, A_REVERSE);
    }
}
