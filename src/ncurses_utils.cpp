
#include "ncurses_utils.hpp"


int center(int width, std::string str){
    return (width - str.length())/2;
}

void printTitle(WINDOW *win, std::string title)
{
    int height, width;
    getmaxyx(win, height, width);
    mwprintw(win, 1, center(width, title), title.c_str());
}

void printList(WINDOW *win, std::string[] items){
    int height, width;
    int highlight = 2;
    int last = height - 2;
    getmaxyx(win, height, width);
    for (int i = 2; i < last; i++){
        if (i == highlight)
            wattron(win, A_REVERSE);
        else{
            mvwprintw(win, i, 1, items[i].c_str());
        }
        wattroff(win, A_REVERSE);
    }
}
