// This program outputs itself to the screen.

#include <iostream>
#include <fstream>
using namespace std;
	
int main(int argc, char* argv[])
{
    if(argc<2)
    {
        cout<<"input your source file"<<endl;
        return -1;
    }
    
    char character;
    ifstream in_stream;

    in_stream.open(argv[1]);

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
