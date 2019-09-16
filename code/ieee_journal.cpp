#include "ieee_journal.h"

#include <pugixml/pugixml.hpp>

#include <iostream>
#include <string.h>

using namespace pugi;
using namespace std;
//****************************************************************************************************************************

bool ieeeJournal (xml_node& referenceInstance, FILE* pFile)

{
           xpath_node referenceDetailNode = referenceInstance.select_node("./referenceDetail");
           uint32_t iYear = referenceDetailNode.node().attribute("year").as_uint();
           uint32_t iVol = referenceDetailNode.node().attribute("vol").as_uint();
           uint32_t iNo = referenceDetailNode.node().attribute("no").as_uint();
           uint32_t iPageStart = referenceDetailNode.node().attribute("pageStart").as_uint();
           uint32_t iPageEnd = referenceDetailNode.node().attribute("pageEnd").as_uint();
           uint32_t referenceNumber = referenceInstance.attribute("referenceNum").as_uint();
           bool bOnline = referenceDetailNode.node().attribute("online").as_bool();

           fprintf(pFile,"[%u] %s, %s, %s, vol. %u, no. %u, ", referenceNumber,
                                            referenceDetailNode.node().attribute("initialAndSurname").as_string(),
                                            referenceDetailNode.node().attribute("articleTitle").as_string(),
                                            referenceDetailNode.node().attribute("journalTitleAbbr").as_string(),
                                            iVol, iNo);

           if (iPageStart==iPageEnd)
           {
               fprintf (pFile, "p. %u, ", iPageStart);
           }

           else {
               fprintf (pFile, "pp. %u-%u, ", iPageStart, iPageEnd);
           }


           fprintf (pFile,"%s. %u. ", referenceDetailNode.node().attribute("monthAbbr").as_string(),
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
