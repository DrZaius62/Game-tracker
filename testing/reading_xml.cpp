#include "pugixml.hpp"
#include <iostream>
#include <cassert>

int main()
{
    // Create empty XML document within memory
    pugi::xml_document doc;

    // Load XML file into memory
    // Remark: to fully read declaration entries you have to specify
    // "pugi::parse_declaration"
    pugi::xml_parse_result result = doc.load_file("test.xml",
        pugi::parse_default|pugi::parse_declaration);
    if (!result)
    {
        std::cout << "Parse error: " << result.description()
            << ", character pos= " << result.offset;
    }
    // A valid XML document must have a single root node
    pugi::xml_node root = doc.document_element();

        // Search for the first matching entry with the given hint attribute
    std::string searchStr = "Wishlist";
    pugi::xpath_node xpathNode = root.select_node(searchStr.c_str());
    if (xpathNode)
    {
        pugi::xml_node selectedNode = xpathNode.node();
        for (pugi::xml_node child = selectedNode.first_child(); child; )
        {
            // Get next child node before possibly deleting current child
            pugi::xml_node next = child.next_sibling();
            // Check wether child node shall be deleted
            if (std::string(child.attribute("name").value()) == "god of war")
            //if (std::string(child.attribute("name").value()) == "god of war")
            {
                std::cout << child.attribute("name").value() << std::endl;
                //child.parent().remove_child(child);
                //child.remove_attribute("price");
                selectedNode.remove_child(child);
            }
            child = next;
        }
        pugi::xml_node game = selectedNode.append_child("Game");
        game.append_attribute("name") = "sly cooper";

    }

    bool saveSucceeded = doc.save_file("test.xml");
    assert(saveSucceeded);
    return 0;
}
