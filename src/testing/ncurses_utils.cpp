#include <curses.h>
#include <ncurses.h>

#include <iostream>
#include <vector>
#include <string>

int center(int width, std::string str){
    return (width - str.length())/2;
}

void printTitle(WINDOW *win, std::string title)
{
    int height, width;
    getmaxyx(win, height, width);
    mvwprintw(win, 1, center(width, title), title.c_str());
}

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

int main()
{
    initscr();
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    int width = xMax/2;
    int height = yMax/2;
    WINDOW *win = newwin(height, width, 10, 20);
    refresh();

    std::vector<std::string>list = {"test1", "test2", "test3"};
    int highlight = 2;

    keypad(win, true);
    int choice;

    while (1){
        box(win, 0, 0);
        printTitle(win, "Hola");
        printList(win, highlight, list);

        choice = wgetch(win);

        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight == 1) highlight = 2;
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == list.size()+1) highlight = list.size(); 
                break;
            default:
                break;
        }
        if (choice == 10)
            break;
    }

    getch();
    endwin();
}
