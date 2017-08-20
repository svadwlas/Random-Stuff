using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AspectOrientedProgramming
{


    //Aspect  Oriented Programming using "Decorators"!
    class LoggingAwareDocumentSource :IDocumentSource
    {


        public Document[] GetDocuments(string format)
        {


            try
            {

                var documents = decoratedDocumentSource.GetDocuments(format);
                logger.LogSuccess( "Obtained" + documents.Length + " documents of type" + format);
                return documents;
                
            }

            catch (Exception ex)
            {
                logger.LogError("Error obtaining documents of type" + format, ex);
                throw;
            }



        }


        /*
         The Logging code is removed from the Original class
         The Document source is then decorated:


        var source = 
        new LoggingAwareDocumentSource(new DocumentSource(connectionString), new Logger(...));

        AOP allows us to do:
        Remove code duplication. 
        Enhance code readability by moving code related to cross-cutting concerns into a single place where it can be easily maintained. 





         */















    }
}
