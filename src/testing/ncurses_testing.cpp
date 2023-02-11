#include <curses.h>
#include <ncurses.h>

int main()
{
    int ch;
    // init screen and sets up screen
    initscr();

    raw();
    keypad(stdscr, TRUE);
    noecho;

    printw("Type any character to see it in bold\n");
    // print to screen

    ch = getch();

    if (ch == KEY_F(1))
        printw("F1 key pressed");
    else{
        printw("The pressed key is ");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    };
    // refreshes the screen
    refresh();

    // pause the screen output
    getch();

    // deallocates memory and ends ncurses
    endwin();
    return 0;
}
