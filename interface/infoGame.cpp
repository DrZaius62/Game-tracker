// infoGame.cpp - Window that display the information of a game

#include "infoGame.hpp"
#include <curses.h>

// Constructor
Info::Info(int heightMenu, int widthMenu){
    
    width = 30;
    WINDOW *infoWin = newwin(heightMenu, width, 10, widthMenu+20-1);
    setWin(infoWin);
    box(infoWin, 0, 0);
    wrefresh(infoWin);
}

// Destructor
Info::~Info(){
    delwin(getWin());
}

void Info::printInfo(Game *game){

    WINDOW *curWin = getWin();
        /* Game
        std::string name;
        time_t  d_start;
        time_t  d_beat;
        time_t  d_release;
        int     review;
        std::string status;
        std::string  platform;
        */
    int i = 1;
    mvwprintw(curWin, i++, 1, std::string("Name: "+game->getName()).c_str());
    mvwprintw(curWin, i++, 1, std::string("Status: "+game->getStatus()).c_str());
    mvwprintw(curWin, i++, 1, std::string("Platform: "+game->getPlatform()).c_str());
}

WINDOW *Info::getWin(){
    return win;
}

void Info::setWin(WINDOW *win){
    this->win = win;
}


void Info::display(Game *game){

    wclear(getWin());
    box(getWin(), 0, 0);
    printInfo(game);
    wrefresh(getWin());
}

