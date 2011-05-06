/**
 * This is an example using the base JsonCpp library.
 *
 * @file test1.cpp
 * @date Created on: May 5, 2011
 * @author: samh
 */

#include <fstream>

#include "json/json.h"

using namespace std;

bool parseAndPrint(const char * filename) {
    Json::Value root;
    Json::Reader reader;

    std::ifstream in(filename);
    bool parsingSuccessful = reader.parse(in, root);

    if (!parsingSuccessful) {
        // report to the user the failure and their locations in the document.
        std::cout << "Failed to parse configuration\n"
                << reader.getFormattedErrorMessages();
        return false;
    }

    Json::StyledWriter writer;
    // Make a new JSON document for the configuration. Preserve original comments.
    std::string outputConfig = writer.write(root);

    cout << outputConfig;
    return true;
}

int main(int argc, char **argv) {
    if (argc == 2) {
        return parseAndPrint(argv[1]) ? 0 : 1;
    } else {
        cout << "Usage: " << argv[0] << " JSON_FILE" << endl;
        return 2;
    }
}
