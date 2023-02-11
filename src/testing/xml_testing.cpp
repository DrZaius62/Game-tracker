#include "pugixml.hpp"
#include <cassert>
#include <string>

int main()
{
    // Generate new XML document within memory
    pugi::xml_document doc;

    // Alternatively store as shared pointer if tree shall be used for longer
    // time or multiple client calls:
    // std::shared_ptr<pugi::xml_document> spDoc = std::make_shared<pugi::xml_document>();
    //
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    declarationNode.append_attribute("encoding")   = "ISO-8859-1";
    declarationNode.append_attribute("standalone") = "yes";


    
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("UserGames");


    pugi::xml_node nodeChild1 = root.append_child("Wishlist");
    pugi::xml_node nodeChild2 = root.append_child("Playing");

    pugi::xml_node game1 = nodeChild1.append_child("Game");
    pugi::xml_node game2 = nodeChild2.append_child("Game");

    // Add as last element
    game1.append_attribute("name") = "god of war";
    game1.append_attribute("price") = 100;

    game2.append_attribute("name") = "zelda";
    game2.append_attribute("price") = 200;

    // Save XML tree to file.
    // Remark: second optional param is indent string to be used;
    // default indentation is tab character.
    //bool saveSucceeded = doc.save_file(XML_FILE_PATH.c_str(), PUGIXML_TEXT("  "));
    bool saveSucceeded = doc.save_file("test.xml", PUGIXML_TEXT("  "));


    assert(saveSucceeded);


    return 0;
}
