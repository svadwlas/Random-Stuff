using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//The Code below addresses a logging concern:
namespace AspectOrientedProgramming
{
    public class DocSource: IDocumentSource
    {

        public Document[] getDocuments(string format)
        {


            try
            {


                using (var context = CreateEFContext())
                {


                    var documents =
                        context.Documents.Where(c => c.Name.EndsWith("." + format))
                        .ToArray();


                }

                // The above code is a violation of the Single Responsibility Principle

            }
            catch (Exception ex)
            {



            }


            /*
             The Logging Pattern above could be found in several methods, in the overall code base.
             try{

            logger.LogSuccess(...
            //...

            }


            catch(){

            logger.LogError(...
            throw;



            }
             
             
             
             
             
             */


        }




















    }
}
