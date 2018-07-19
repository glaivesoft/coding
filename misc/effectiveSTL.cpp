// note for "effective STL"
// 7/19/2018

#include <array>
#include <tuple>
#include <string>
#include <cassert>
#include <vector>
#include <stdio.h>
#include <math.h>

#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    float a = 2.0;
    float b = 3.0;
    
    if(fabs(a-b)<1e-9)
    {
        cout<<"a = b"<<endl;
    }
    else
    {
        cout<<"a <> b"<<endl;
    }
    
    //
    int x = 3;
    
    if(x % 2 != 0)
    {
        cout<<x<<" is odd "<<endl;
    }
    
    //
    int row_num = 4;
    int col_num = 4;
    
    vector<vector<int> > array(row_num, vector<int>(col_num, 0));
    
    array.clear();
    
    //
    
    return 0;
}
