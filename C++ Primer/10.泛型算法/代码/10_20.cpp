#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string inp;
	vector<string> words;
	while(cin >> inp)
		words.push_back(inp);

	int sz=6;
	auto findCmp=[sz](const string &a)
			{ return a.size() >=sz; };

	int nCount=count_if(words.begin(), words.end(), findCmp);

	cout << "长度超过6的有" << nCount << "个" << endl;
	return 0;
}
