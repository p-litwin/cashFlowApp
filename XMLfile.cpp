#include "XMLfile.h"

bool XMLfile::saveXMLdocumentToFile(){
    return xmlDocument.Save(XML_FILENAME);
}
