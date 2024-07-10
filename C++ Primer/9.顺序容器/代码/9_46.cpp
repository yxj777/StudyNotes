#include <iostream>
#include <string>
using namespace std;
void nameAdd(string &name, const string &str1, const string &str2)
{
	name.insert(0,str1+" ");
	name.insert(name.size()-1," "+str2);
}
int main()
{
	string name="xxxx";
	nameAdd(name, "Mr.", "Jr.");
	cout << name << endl;
	return 0;
}
