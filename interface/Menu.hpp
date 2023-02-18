
#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "pugixml.hpp"

#include "xml_utils.hpp"
#include "ncurses_utils.hpp"
#include "Game.hpp"
#include "infoGame.hpp"

extern pugi::xml_node root;

class Menu{
    public:
        Menu(int yFactor, int xFactor, int starty, int startx);
        ~Menu();

        void printMain();
        void printCurrentScreen();

        WINDOW *getWin();
        void setWin(WINDOW *win);

        Info *getInfo();
        void setInfo(Info *info);

        int getCategory();
        void setCategory(int category);

        int getOldCategory();
        void setOldCategory(int category);

        int getHighlight();
        void setHighlight(int set);

        int getSizeList();
        void setSizeList(int size);

        int getHeight();
        int getWidth();

        int getInput();

        void display();

    private:
        // To managge the menu window
        WINDOW *win;

        // To manage the info window
        Info *info;
        int width;
        int height;
        int highlight;
        int sizeList;
        int category;
        // On category change, info window gets destroyed
        int oldCategory;

};


#endif /*INTERFACE_HPP*/
