#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	char buf [100];
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	time_t T = time(NULL);
	tm * Ptm;
	Ptm = localtime(&T);
	strftime (buf,100,"%c",Ptm); 
	cout << buf << endl;
	return 0;
}
