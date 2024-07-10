#include <iostream>
using namespace std;
typedef string bm[10];
string(&arr( ))[10];		
bm& arr();
auto arr() -> string(&)[10];
int main()
{
	return 0;
}
