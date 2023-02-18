#include <curses.h>
#include <iostream>
#include <ncurses.h>
#include <unistd.h> 

#include "Game.hpp"
#include "xml_utils.hpp"
#include "Menu.hpp"
#include "infoGame.hpp"

pugi::xml_node  root;
int main()
{
    Game *game = new Game();
    game->setName("The Last of Us");

    // Create empty XML document within memory
    pugi::xml_document doc = openXml("test.xml");
    root = doc.document_element();

    initscr();
    noecho();
    cbreak();
    Menu *m = new Menu(2, 4, 10, 20);

    while(m->getInput() != 'x')
    {
        m->display();
    }
    m->~Menu();
    /*
    addGame(root, game, "Wishlist");
    moveGame(root, game, "Playing");

    if (doc.save_file("test.xml")){
        std::cout << "Changes saved." << std::endl;
    }
    else {
        std::cout << "Couldn't save changes." << std::endl;
    }
    game->print();
    */

    return 0;
}
