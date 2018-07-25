
#include <iostream>
#include <ctime>

using namespace std;

inline void mysleep(clock_t sec)
{
	clock_t start = clock();
	clock_t end = sec*1000000 + start;
	while(clock()!=end);
}

int main(int argc, char *argv[])
{

	cout<<"wait 5 second"<<endl;
	mysleep(5);
    cout<<"5 seconds just elapses"<<endl;

	return 0;
}
