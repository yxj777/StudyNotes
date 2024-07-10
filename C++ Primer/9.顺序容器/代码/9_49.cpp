#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void fun(ifstream &in, const string &letter)
{
	int pos;
	string s,maxStr;
	int maxSize=0;
	while(in >> s)
	{
		if(s.find_first_of(letter) == string::npos)
		{
			if(s.size()>maxSize)
			{
				maxSize=s.size();
				maxStr=s;
			}		
		}
	}
	cout << maxStr << endl;
}
int main()
{
	string letter="bdfghjklpqty";
	ifstream in("letter.txt");
	if(!in)
		cout << "文件打开失败";
	fun(in,letter);
}
