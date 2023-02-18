// winGame.hpp - Window that display the information of a game


#ifndef INFO_GAME_HPP
#define INFO_GAME_HPP

#include <string>
#include <iostream>
#include <ncurses.h>

#include "pugixml.hpp"

#include "xml_utils.hpp"
#include "ncurses_utils.hpp"
#include "Game.hpp"

class Info{
    public:
        Info(int heightMenu, int widthMenu);
        ~Info();

        WINDOW *getWin();
        void setWin(WINDOW *win);

        // Makes a page of info of a game
        void printInfo(Game *game);

        // Prints the box of information
        void display(Game *game);

    private:
        WINDOW *win;
        int width;
        int height;
};

#endif /*INFO_GAME_HPP*/

