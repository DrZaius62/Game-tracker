#include <iostream>
#include <unistd.h> 

#include "Game.hpp"
#include "xml_utils.hpp"
#include "interface.hpp"
pugi::xml_node  root;
int main()
{
    Game *game = new Game();
    game->setName("The Last of Us");

    // Create empty XML document within memory
    pugi::xml_document doc = openXml("test.xml");
    root = doc.document_element();
    
    menu();
    int option;
    std::cin >> option;

    switch (option) {
        case 1:
            showList("Wishlist");
            break;
        default:
            
            break;
    }

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
