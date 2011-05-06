/**
 * This is an example using the base JsonCppQt wrapper.
 *
 * @file test1-qt.cpp
 * @date Created on: May 5, 2011
 * @author: samh
 */

#include <iostream>

#include <QtCore/QDebug>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QVariant>

#include "json/jsoncpp-qt.h"

using namespace std;

bool parseAndPrint(const char * filename) {
    QVariant root;
    Json::QtReader reader;

    QFile file("example1.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cerr << "Failed to open file" << endl;
        return false;
    }
    QTextStream in(&file);

    bool parsingSuccessful = reader.parse(in.readAll(), root);

    if (!parsingSuccessful) {
        // report to the user the failure and their locations in the document.
        cerr << "Failed to parse configuration\n"
                << qPrintable(reader.getFormattedErrorMessages());
        return false;
    }

    qDebug() << root;

    Json::QtWriter writer;
    QString outputConfig = writer.write(root);

    cout << qPrintable(outputConfig);

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
