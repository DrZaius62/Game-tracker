// interface.cpp - The cli for the program

#include "interface.hpp"
#include "xml_utils.hpp"
#include "ClearScreen.hpp"

// Displays the main menu
void menu()
{
    "- Wishlist\n"
    "- Backlog\n"
    "- Playing\n"
    "- Beat\n"
    "- Quit\n"
    "- Paused\n";
}




// Prints all games in a category
void showList(std::string category)
{
    ClearScreen();
    pugi::xml_node group = statusNode(root, category);
    std::string group_str = group.name();
    std::string bar(group_str.length() + 4, '-');
    std::cout << bar << std::endl;
    std::cout << "| " << group_str  << " |" << std::endl;
    std::cout << bar << std::endl;

    for(auto game : group)
    {
        std::cout << "- " << game.attribute("name").value() << std::endl;
    }
}
