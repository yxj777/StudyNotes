#include <iostream>
#include <vector>
#include <string>
using namespace::std;

int main()
{
	vector<string> s;
	string inpt;
	while(cin >> inpt)
		s.push_back(inpt);
	for(string i:s)
		cout << i << endl;
	return 0;
}
