#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "lib/rapidxml/rapidxml.hpp"
#include "lib/rapidxml/rapidxml_utils.hpp"

int main(int argc, char* argv[]) {
    // Check if file name was provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <XML_FILE>" << std::endl;
        return 1;
    }
    // 1. Init a blank HTML page that will have html, head and body tags
    std::stringstream html;
    html << "<!DOCTYPE html>\n"
         << "<html>\n"
         << "<head>\n"
         << "<title>CD Catalog</title>\n"
         << "</head>\n"
         << "<body>\n"
         << "<table border=\"1\">\n"  // Start of the table
         << "<tr><th>Title</th><th>Artist</th><th>Country</th><th>Company</th><th>Price</th><th>Year</th></tr>\n"; // Table headers

    // 2. Parse the XML
    std::string xmlFileName = argv[1];
    rapidxml::file<> xmlFile(xmlFileName.c_str()); // Reads the XML file and creates object
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data()); // The <0> declares the parsing mode = default

    // 3. proceed by parsing through the CD tags, grabbing the attributes inside them
    // Grab the root node, which should be Catalog
    rapidxml::xml_node<> *root_node = doc.first_node("CATALOG");

    if (root_node != nullptr){
        // Iterate over the CD nodes
        for (rapidxml::xml_node<> *cd_node = root_node->first_node("CD"); cd_node; cd_node = cd_node->next_sibling()) {
            rapidxml::xml_node<> *title_node = cd_node->first_node("TITLE");
            rapidxml::xml_node<> *artist_node = cd_node->first_node("ARTIST");
            rapidxml::xml_node<> *country_node = cd_node->first_node("COUNTRY");
            rapidxml::xml_node<> *company_node = cd_node->first_node("COMPANY");
            rapidxml::xml_node<> *price_node = cd_node->first_node("PRICE");
            rapidxml::xml_node<> *year_node = cd_node->first_node("YEAR");

            // 4. Add the values to the initialized HTML page
            html << "<tr>\n";  // Start a new row for this CD
            html << "<td>" << (title_node ? title_node->value() : "N/A") << "</td>\n";  // In case there are missing values
            html << "<td>" << (artist_node ? artist_node->value() : "N/A") << "</td>\n";
            html << "<td>" << (country_node ? country_node->value() : "N/A") << "</td>\n";
            html << "<td>" << (company_node ? company_node->value() : "N/A") << "</td>\n";
            html << "<td>" << (price_node ? price_node->value() : "N/A") << "</td>\n";
            html << "<td>" << (year_node ? year_node->value() : "N/A") << "</td>\n";
            html << "</tr>\n";  // End of row
        }
    }

    // 5. Finish the html file
    html << "</table>\n"
         << "</body>\n"
         << "</html>";

    // 6. Write the complete HTML content to a file
    std::ofstream file;
    file.open("cd_catalog.html");
    if (file.is_open()) {
        file << html.str();
        file.close();
        std::cout << "HTML file created successfully." << std::endl;
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
    }

    return 0;
}
