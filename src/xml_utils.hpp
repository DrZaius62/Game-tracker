#ifndef XML_UTILS_HPP
#define XML_UTILS_HPP

#include <iostream>
#include <string>
#include "pugixml.hpp"

#include "Game.hpp"

// Opens a doc of a given file
pugi::xml_document openXml(std::string file);

// Gets the xml_node root of the given xml file
pugi::xml_node rootNode(pugi::xml_document doc);

// Returns the pointer to the xml_node of a category
pugi::xml_node statusNode(pugi::xml_node root, std::string category);

// Searches for game in a category
pugi::xml_node searchGame(pugi::xml_node root, std::string name, 
        pugi::xml_node &status);

// Adds a game to a category
bool addGame(pugi::xml_node root, Game *game, std::string status);

// Deletes a game, can be in any category
bool deleteGame(pugi::xml_node root, Game *game);

// Moves a game to a new category
bool moveGame(pugi::xml_node root, Game *game, std::string new_status);

#endif /*XML_UTILS_HPP*/

