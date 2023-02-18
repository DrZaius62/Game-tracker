#include "xml_utils.hpp"
#include <cstddef>

pugi::xml_document openXml(std::string file)
{
    // Create empty XML document within memory
    pugi::xml_document doc;

    // Load XML file into memory
    // Remark: to fully read declaration entries you have to specify
    // "pugi::parse_declaration"
    pugi::xml_parse_result result = doc.load_file(file.c_str(),
        pugi::parse_default|pugi::parse_declaration);
    if (!result)
    {
        std::cout << "Parse error: " << result.description()
            << ", character pos= " << result.offset;
    }
    // A valid XML document must have a single root node
    return doc;
}

pugi::xml_node rootNode(pugi::xml_document doc)
{
    pugi::xml_node root = doc.document_element();
    return root;
}

pugi::xml_node statusNode(pugi::xml_node root, std::string category)
{
    pugi::xml_node group = root.first_child();
    for (;group; group = group.next_sibling()) {
        if (std::string(group.name()) == category){
            return group;
        }
    }

    return pugi::xml_node();
}

pugi::xml_node searchGame(pugi::xml_node root, std::string name, 
        pugi::xml_node &status)
{
    // Runs through all the status groups 
    pugi::xml_node group = root.first_child();
    for (;group; group = group.next_sibling()) {
        for (pugi::xml_node game : group) {
            if (std::string(game.attribute("name").value()) == name){
                status = group;
                return game;
            }
        }
    }
    return pugi::xml_node();
}

Game *makeGame(pugi::xml_node info){
    Game *game = new Game();

    game->setName(std::string(info.attribute("name").value()));
    game->setStart(atoi(info.attribute("start").value()));
    game->setBeat(atoi(info.attribute("beat").value()));
    game->setRelease(atoi(info.attribute("release").value()));
    game->setReview(atoi(info.attribute("review").value()));
    game->setPlatform(std::string(info.attribute("platform").value()));

    return game;
}

bool addGame(pugi::xml_node root, Game *game, std::string status)
{
    // Runs through all the status groups 
    pugi::xml_node new_game;
    for (pugi::xml_node group : root) {
        // Check whether group is status 
        if (std::string(group.name()) == status){
    
            new_game = group.append_child("Game");
            new_game.append_attribute("name") = game->getName().c_str();
            new_game.append_attribute("start") = game->getStart();
            new_game.append_attribute("beat") = game->getBeat();
            new_game.append_attribute("release") = game->getRelease();
            new_game.append_attribute("review") = game->getReview();
            new_game.append_attribute("platform") = game->getPlatform().c_str();

            std::cout << "Game added to " + std::string(group.name()) << std::endl;
            return true;
        }
    }
    return false;
}

bool deleteGame(pugi::xml_node root, Game *game)
{
    pugi::xml_node status;
    std::string name = game->getName();
    searchGame(root, name, status);

    for (pugi::xml_node child : status){
        // Check whether child node shall be deleted
        if (std::string(child.attribute("name").value()) == name){
            status.remove_child(child);
            std::cout << "Game removed from " + std::string(status.name()) 
                << std::endl;
            return true;
        }
    }
    //Error
    return false;
}

bool moveGame(pugi::xml_node root, Game *game, std::string new_status)
{
    if (deleteGame(root, game)){
        if (addGame(root, game, new_status)){
            std::cout << "Game moved." << std::endl;
            return true;
        }
    }
    std::cout << "Game couldn't be moved." << std::endl;
    return false;
}
