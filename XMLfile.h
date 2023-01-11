#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include "User.h"
#include "Markup.h"
#include <vector>

class XMLfile {
protected:
    const string XML_FILENAME;
    CMarkup xmlDocument;
public:
    XMLfile(string fileName)
    : XML_FILENAME(fileName) {
    xmlDocument.Load(XML_FILENAME);
    };

    bool saveXMLdocumentToFile();
    CMarkup *getXMLdocument();
};


#endif // XMLFILE_H
