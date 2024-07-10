#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace::std;

int main()
{
	vector<string> v;
	string word;
	char ch;
	while(cin >> word)
		v.push_back(word);
	for(string &i:v)
	{
		for(char &y:i)
			y=toupper(y);
		cout << i << endl;	
	}
}
