#include <curses.h>
#include <ncurses.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    initscr();
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    int width = xMax/4;
    int height = yMax/4;
    WINDOW *win = newwin(height, width, 10, 10);
    WINDOW *win2 = newwin(height, width, 10, width+10);

    box(win, 0,0);
    box(win2, 0,0);
    //mvwprintw(win, 1, 1, to_string(width).c_str());
    mvwprintw(win, 1, 37, "a"); 
    //mvwprintw(win2, 1, 38, to_string(width).c_str());
    refresh();
    wrefresh(win);
    wrefresh(win2);

    getch();
    endwin();

}
