// interface.cpp - The cli for the program
#include <ncurses.h>
#include <string>
#include <vector>

int center(int width, std::string str);

void printTitle(WINDOW *win, std::string title);

void printList(WINDOW *win, int highlight, std::vector<std::string> list);

class Menu{
    public:
        void printMain();
        void printCurrentScreen();

        WINDOW *getWin();
        void setWin(WINDOW *win);

        int getCategory();
        void setCategory(int category);

        int getHighlight();
        void setHighlight(int set);

        int getSizeList();
        void setSizeList(int size);

        int getInput();

        void display();

        Menu(int factor, int starty, int startx);
        ~Menu();
    private:
        WINDOW *win;
        int width;
        int height;
        int highlight;
        int sizeList;
        int category;
};




