#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main()
{
	list<const char *> cList={"111","222","333"};
	vector<string> sVec={"aaa","bbb","ccc"};
	cout << "赋值前：" << endl;
	cout << "char * list：\t";
	for(auto i=cList.begin(); i!=cList.end(); ++i)
		cout << " " << *i;
	cout << endl;
	cout << "string vector：\t";
	for(auto i=sVec.begin(); i!=sVec.end(); ++i)
		cout << " " << *i;
	
	sVec.assign(cList.begin(),cList.end());	

	cout << endl << "赋值后：" << endl;
	cout << "char * list：\t";
	for(auto i=cList.begin(); i!=cList.end(); ++i)
		cout << " " << *i;
	cout << endl;
	cout << "string vector：\t";
	for(auto i=sVec.begin(); i!=sVec.end(); ++i)
		cout << " " << *i;
	cout << endl;
	return 0;
}
