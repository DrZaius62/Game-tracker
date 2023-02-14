#include <curses.h>
#include <ncurses.h>

int main()
{
    initscr();
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *win = newwin(yMax/2, xMax/2, 10, 10);
    WINDOW *win2 = newwin(yMax/2, xMax/4, 10, xMax/2);

    box(win, 0,0);
    box(win2, 0,0);
    refresh();
    wrefresh(win);
    wrefresh(win2);

    getch();
    endwin();
}
