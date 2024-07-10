#include <iostream>
using namespace std;
void temp(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;	
	*y=t;
}
void temp1(int &x,int &y)
{
	int t;
	t=x;
	x=y;
	y=t;
}
int main()
{
	int x=10,y=20;
	int *xp=&x,*yp=&y;
	temp(&x,&y);
	//temp(xp,yp);
	cout << x << "\t" << y << endl;
	temp1(x,y);
	cout << x << "\t" << y << endl;
	return 0;
}
