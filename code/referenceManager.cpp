#include <iostream>
#include <pugixml/pugixml.hpp>
#include <outputreference.h>

using namespace pugi;
using namespace std;
//***************************************************************************************************


int main()
{

  FILE* referenceScript = fopen("referenceScript", "w");
  if(referenceScript == NULL)
      {
       cout << "open pipe failed" << endl;
      }


//----------OPEN XML File------------------------------------------------------------------------------------------------------------------------------------------------------//
    xml_document referenceManagerDocument;
    xml_parse_result referenceLoadResult=referenceManagerDocument.load_file("/home/aaronzhao/Dropbox/aaron's reference manager/referenceManager/xml_design/singleAutherBookExample.xml");
    if(referenceLoadResult.status != status_ok){
        cout << "load reference error" << endl;
    }
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//---------outputReference----------------------------------------------------------------------------------------------------------------------------------------------------//
    if(not outputReference(referenceManagerDocument, referenceScript))
            {
            cout<< "reference failed" << endl ;
            }
  fflush(referenceScript);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//




//---------CLOSE----------------------------------------------------------------------------------------------------------------------------------------------------//

    fclose(referenceScript);

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
    return EXIT_SUCCESS;
}
