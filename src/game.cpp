#include <iostream>
#include "pugixml.hpp"

int main()
{
    // Create a new XML document
    pugi::xml_document doc;

    // Create the root element
    pugi::xml_node root = doc.append_child("Games");

    // Create child elements
    pugi::xml_node game1 = root.append_child("Game");
    pugi::xml_node game2 = root.append_child("Game");

    // Add attributes to the child elements
    game1.append_attribute("name") = "Super Mario";
    game1.append_attribute("status") = "playing";
    game1.append_attribute("price") = "50";
    game2.append_attribute("name") = "Minecraft";
    game2.append_attribute("status") = "bought";
    game2.append_attribute("price") = "20";

    // Add text to the child elements
    game1.append_child(pugi::node_pcdata).set_value("Platformer");
    game2.append_child(pugi::node_pcdata).set_value("Adventure");

    // Save the XML document to a file
    if (!doc.save_file("games.xml"))
        std::cout << "Error saving the XML file" << std::endl;
    else
        std::cout << "XML file saved successfully" << std::endl;
    return 0;
}

