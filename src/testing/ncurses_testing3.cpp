
#include <curses.h>
#include <ncurses.h>
#include <string>

// gives the starting position to center a string
int center(int width, std::string str){
    return (width - str.length()) / 2;
}

void printBox(WINDOW *win, int height, int width)
{
    box(win, 0, 0);
    mvwprintw(win, 1, center(width, "Wishlist"), "Wishlist");
}
int main()
{
    // NCURSES INIT
    initscr();

    // get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    int width = xMax/2;
    int height = yMax/2;
    WINDOW *win = newwin(height, width, 10, 20);

    refresh();

    int choice;
    int highlight = 3;
    keypad(win, true);

    std::string list[] = {"test", "ne"};
    int page = 0;
    while(1){
        printBox(win, height, width);
        for (int i = 3; i < 11; i++){
            if (i == highlight)
                wattron(win, A_REVERSE);
            if (i == 9){
                mvwprintw(win, i, 1, "-------Next page--------");
            }
            else if (i == 10){
                mvwprintw(win, i, 1, "-------Exit--------");
            }
            else{
                mvwprintw(win, i, 1, list[page].c_str());
            }
            wattroff(win, A_REVERSE);
        }
        choice = wgetch(win);

        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight == 2) highlight = 3;
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 11) highlight = 10;
                break;
            default:
                break;
        }
        if (choice == 10 and highlight == 9)
        {
            wclear(win);
            wrefresh(win);
            page = 1;
            continue;
        }
        else if (choice == 10 and highlight == 10)
        {
            break;
        }
    }
    getch();

    endwin();
    
    return 0;

}
