// This program outputs itself to the screen.

#include <iostream>
#include <fstream>
using namespace std;
	
int main() 
{
    char character;
    ifstream in_stream;

    in_stream.open("outputsource.cpp");

    //
    do
    {
        in_stream.get(character);
        cout << character;
    } while (! in_stream.eof());
    
    
    /*
     
     in_stream.get(character);
     for ( ; ! in_stream.fail() ; )
     {
        cout << character;
        in_stream.get(character);
     }
     
     */
	
	in_stream.close();
							
	return 0;
}
