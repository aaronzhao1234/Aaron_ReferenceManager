#ifndef OUTPUTREFERENCE_H
#define OUTPUTREFERENCE_H

#include <pugixml/pugixml.hpp>

using namespace pugi;

//*******************************************************************************************

bool outputReference (xml_node& referenceRootElement,  FILE* pFile);

//*******************************************************************************************
#endif // OUTPUTREFERENCE_H
