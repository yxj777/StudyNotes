#include <iostream>
#include <vector>
using namespace std;
int fun(int a,int b);
int fun1(int a,int b)
{
	return a+b;
}
int fun2(int a,int b)
{
	return a-b;
}
int fun3(int a,int b)
{
	return a*b;
}
int fun4(int a,int b)
{
	return a/b;
}
void funPrint(int i,int j, int (*p)(int,int))
{
	cout << p(i,j) << endl;
}
int main()
{
	int i=10,j=5;
	decltype(fun) *p1=fun1,*p2=fun2,*p3=fun3,*p4=fun4;	
	vector<decltype (fun)*> p={p1,p2,p3,p4};
	for(auto a:p)
	//	funPrint(i,j,a);
		cout << a(i,j) << endl;
	return 0;
}
