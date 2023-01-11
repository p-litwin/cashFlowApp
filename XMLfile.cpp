#include "XMLfile.h"

bool XMLfile::saveXMLdocumentToFile(){
    return xmlDocument.Save(XML_FILENAME);
}

CMarkup *XMLfile::getXMLdocument() {
    CMarkup *xmlPTR = &xmlDocument;
    return xmlPTR;
}
