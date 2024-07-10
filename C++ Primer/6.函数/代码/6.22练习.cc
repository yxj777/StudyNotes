#include <iostream>

using namespace std;

void temp(int *&x,int *&y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
int main()
{
	int x=10,y=20;
	int *xp=&x,*yp=&y;
	temp(xp,yp);	
	cout << *xp << "\t" << *yp;
	return 0;
}
