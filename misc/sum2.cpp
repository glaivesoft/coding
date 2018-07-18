#include <iostream>
using namespace std;

void sum(int numbers[], int length, int target)
{
    int i = 0, j = length - 1;
    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum < target) {
            i++;
        } else if (sum > target) {
            j--;
        } else {
            cout<< i + 1 <<" "<< j + 1 <<endl;
            return;
        }
    }
    
    cout<<"fail to find"<<endl;
    return;
}

int main()
{
    //
    int a[] = {1, 4, 50, 69, 70};
    int b = 73;
    
    //
    sum(a, 6, b);
    
    //
    return 0;
}

