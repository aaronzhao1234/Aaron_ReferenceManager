#include "ieee_book.h"

#include <pugixml/pugixml.hpp>

#include <iostream>

using namespace pugi;
using namespace std;
//****************************************************************************************************************************

bool ieeeBook (xml_node& referenceInstance, FILE* pFile)

{
       xpath_node referenceDetailNode = referenceInstance.select_node("./referenceDetail");
       uint32_t iYear = referenceDetailNode.node().attribute("year").as_uint();
       uint32_t iEd = referenceDetailNode.node().attribute("edition").as_uint();
       uint32_t referenceNumber = referenceInstance.attribute("referenceNum").as_uint();

       fprintf(pFile,"[%u] %s, %s",     referenceNumber,
                                        referenceDetailNode.node().attribute("initialAndSurname").as_string(),
                                        referenceDetailNode.node().attribute("bookTitle").as_string());
       if (iEd == 1)
       {
           fprintf(pFile, ". ");
       }

       else if (iEd == 2)
       {
           fprintf(pFile, ", 2nd. ");
       }

       else if (iEd == 3)
       {
           fprintf(pFile, ", 3rd. ");
       }

       else if (iEd >= 4)
       {
           fprintf(pFile, ", %uth. ",iEd);
       }


       fprintf (pFile, "%s, %s: %s, %u.\n", referenceDetailNode.node().attribute("city").as_string(),
                                            referenceDetailNode.node().attribute("country").as_string(),
                                            referenceDetailNode.node().attribute("publisher").as_string(),
                                            iYear);



return true;
}
