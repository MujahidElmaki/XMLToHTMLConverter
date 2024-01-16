# XMLToHTMLConverter

## Overview
This program converts a CD catalog from XML format to an HTML table format

## Prerequisites
- g++ compiler
- RapidXML library

## Installation and Compilation
1. **Clone the Repository** (or download the source code):
   `git clone https://github.com/MujahidElmaki/XMLToHTMLConverter.git`

2. **Navigate to the Project Directory**: `cd XMLToHTMLConverter`
3. **Compile the Program**: Run the `make` command to compile the executable
4. **Run the Executable**: After compiling you may run the program with: `./XMLToHTMLConverter cd_catalog.xml`
5. **Clean up**: You can clean the executable after running it with `make clean`

This will generate an HTML file from the given XML file, inside the XMLToHTMLConverter folder

## Features
- Reads XML CD catalog files
- Converts the XML to an HTML table format
- Handles basic XML structures

## Design Choices
- **RapidXML Library**: Chosen for its performance and ease of use for parsing XML files, currently the go to for this use case.
- **Stringstream (from sstream library)**: Incorporated for constructing the HTML content dynamically. The `stringstream` class offers a convenient and efficient way to concatenate strings and build the HTML structure. It simplifies the process of generating HTML by allowing for incremental additions to the HTML content, ensuring readability and maintainability of the code
## Trade-offs
- **Abstraction for Simplicity**: The program code is all contained in the main function, this was to keep things simple and readable. If this were code that would be pushed to production, I would think about separating the code into different files & classes. As well as making the implementation abstract to work with all XML files