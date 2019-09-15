#include <iostream>

#include "outputreference.h"
#include "ieee_book.h"
#include "ieee_book_chapter.h"
#include "ieee_journal_electronic.h"

#include <pugixml/pugixml.hpp>
#include <ctime>

using namespace pugi;
using namespace std;
//---------------------------------------------------------------------------------------------------------------------------------------------------
bool outputReference (xml_node& referenceRootElement,  FILE* pFile)
{
   time_t tt;
   struct tm * ti;
   time (&tt);
   ti = localtime(&tt);
   fprintf(pFile, asctime(ti));//print time in the first line

   xpath_node referenceNode = referenceRootElement.select_node("/reference");
   xpath_node referenceStyleNode = referenceRootElement.select_node("/reference/referenceStyle");
   uint32_t refStyle = referenceStyleNode.node().attribute("referenceStyle").as_uint();

   switch(refStyle)
   {
//=====================================================CASE1 IEEE========================================================================================
   case 1 :
   {
   fprintf(pFile, "reference style: IEEE\n");

   xpath_node_set referenceSetNode = referenceRootElement.select_nodes("reference/referenceSet/referenceElement");
   for(xpath_node_set::const_iterator it = referenceSetNode.begin(); it != referenceSetNode.end(); it++)
   {
       xml_node referenceInstance = it->node();

       xpath_node referenceTypeNode = referenceInstance.select_node("./referenceType");
       uint32_t refType = referenceTypeNode.node().attribute("referenceType").as_uint();

       switch (refType)
       {
//-------------------------------------------------------CASE1_BOOK---------------------------------------------------------------------------------------
       case 1 :{
         ieeeBook (referenceInstance, pFile);
        break;
       }
//-------------------------------------------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------CASE2_BOOK_CHAPTER---------------------------------------------------------------------------------
       case 2 :{
           ieeeBookChapter (referenceInstance, pFile);
        break;
      }
 //-------------------------------------------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------CASE2_BOOK_CHAPTER---------------------------------------------------------------------------------
       case 3 :{
            ieeeJournalElectronic (referenceInstance, pFile);
         break;
      }
//-------------------------------------------------------------------------------------------------------------------------------------------------------
     }//SWITCH type
    }
       break;
   }//style 1

//==========================================================================================================================================================



//=====================================================CASE2 Harvard========================================================================================
   case 2 :
   {
       fprintf(pFile, "reference style: Harvard\n");

       break;
   }//style 2

//==========================================================================================================================================================

  }//SWITCH style

   return true;
}
