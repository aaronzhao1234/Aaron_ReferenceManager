#include "ieee_web.h"

#include <pugixml/pugixml.hpp>

#include <iostream>
#include <string.h>

using namespace pugi;
using namespace std;
//****************************************************************************************************************************

bool ieeeWeb (xml_node& referenceInstance, FILE* pFile)

{
           xpath_node referenceDetailNode = referenceInstance.select_node("./referenceDetail");
           uint32_t iYear = referenceDetailNode.node().attribute("year").as_uint();
           uint32_t iYearAccessed = referenceDetailNode.node().attribute("yearAccessed").as_uint();
           uint32_t iDay = referenceDetailNode.node().attribute("day").as_uint();
           uint32_t iDayAccessed = referenceDetailNode.node().attribute("dayAccessed").as_uint();
           uint32_t referenceNumber = referenceInstance.attribute("referenceNum").as_uint();

           fprintf(pFile,"[%u] %s, %s, %s, %s %u, %u. ", referenceNumber,
                                                         referenceDetailNode.node().attribute("initialAndSurname").as_string(),
                                                         referenceDetailNode.node().attribute("webPageTitle").as_string(),
                                                         referenceDetailNode.node().attribute("websiteTitle").as_string(),
                                                         referenceDetailNode.node().attribute("monthAbbr").as_string(),
                                                         iDay, iYear);

          fprintf (pFile,"[online]. Available: %s. Accessed on: %s %u, %u.\n", referenceDetailNode.node().attribute("URL").as_string(),
                                                                                referenceDetailNode.node().attribute("monthAbbrAccessed").as_string(),
                                                                                iDayAccessed,iYearAccessed);

 return true;

}
