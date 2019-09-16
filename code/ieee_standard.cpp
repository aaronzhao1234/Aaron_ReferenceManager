#include "ieee_standard.h"

#include <pugixml/pugixml.hpp>

#include <iostream>
#include <string.h>

using namespace pugi;
using namespace std;
//****************************************************************************************************************************

bool ieeeStandard (xml_node& referenceInstance, FILE* pFile)

{
           xpath_node referenceDetailNode = referenceInstance.select_node("./referenceDetail");
           uint32_t iYear = referenceDetailNode.node().attribute("year").as_uint();
           uint32_t referenceNumber = referenceInstance.attribute("referenceNum").as_uint();
           bool bOnline = referenceDetailNode.node().attribute("online").as_bool();

           fprintf(pFile,"[%u] %s, %s, %u. ",referenceNumber,
                                            referenceDetailNode.node().attribute("standardTitle").as_string(),
                                            referenceDetailNode.node().attribute("standardNumber").as_string(),
                                            iYear);

           const char* url = referenceDetailNode.node().attribute("URL").as_string();
           const char* doi = referenceDetailNode.node().attribute("DOI").as_string();

           if (bOnline)
           {
           fprintf(pFile, "[online]. ");
           if( not strcmp (url, ""))
           {
               fprintf (pFile,"doi: %s\n", referenceDetailNode.node().attribute("DOI").as_string());
           }
           else if ( not strcmp(doi,""))
           {
               fprintf (pFile,"Available: %s\n", referenceDetailNode.node().attribute("URL").as_string());
           }
           }
           else
           {
               fprintf(pFile,"\n");
           }
 return true;

}
