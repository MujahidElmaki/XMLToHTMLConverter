#include <iostream>
#include <fstream>
#include <string>
#include "lib/rapidxml/rapidxml.hpp"
#include "lib/rapidxml/rapidxml_utils.hpp"

int main() {
    // High level thought process

    // Inside the XML are <CD> tags
    // I would need to loop through each tag and process the attributes inside them
    // This could probably be done using a dictionary

    // Questions I have for now.
    // Is there a global correspondence from XML to HTML?
    // Or can I decide how I want to frame my HTML file
    // How can I create dictionaries, loops, possibly memory management in C++?
    // Which frameworks or libraries will I need for the console?

    // Pseudo Code implementation

    // 1. Init a blank HTML page that will have html, head and body tags
    std::string html =
            "<!DOCTYPE html>\n"
            "<html lang=\"en\">\n"
            "<head>\n"
            "<title>CD Catalog</title>\n"
            "</head>\n"
            "<body>\n"
            // Content will go here
            "</body>\n"
            "</html>";

    std::cout << html << std::endl;
    std::ofstream file;
    file.open("cd_catalog.html");

    if(file.is_open()) {
        file << html;
        file.close();

        std::cout << "HTML file created successfully." << std::endl;
    } else {
        std::cout << "Unable to open file for writing" << std::endl;
    }

    // 2. If the XML given is empty simply return the blank HTML
    //     2a. Parse the XML
    rapidxml::file<> xmlFile("cd_catalog.xml"); // Reads the XML file and creates object
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data()); // The <0> declares the parsing mode = default

    // Grab the root node, which should be catalog
    rapidxml::xml_node<> *root_node = doc.first_node("CATALOG"); // Point the first node to the root

    // Iterate over the CD nodes
    for (rapidxml::xml_node<> *cd_node = root_node->first_node("CD"); cd_node; cd_node = cd_node->next_sibling()) {
        rapidxml::xml_node<> *title_node = cd_node->first_node("TITLE");
        rapidxml::xml_node<> *artist_node = cd_node->first_node("ARTIST");

        std::cout << "Title: " << (title_node ? title_node->value() : "N/A") << ", ";
        std::cout << "Artist: " << (artist_node ? artist_node->value() : "N/A") << std::endl;
    }

    // 3. If not then proceed by parsing through the CD tags, grabbing the attributes inside them
    // 4. Think of a way to map those corresponding values to HTML
    // 5. Add the values to the initialized HTML page
    // 6. Think about the user experience when the MVP is complete
    return 0;
}
