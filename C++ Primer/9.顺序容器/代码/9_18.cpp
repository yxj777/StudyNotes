#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<string> sDeq;
	string inp;
	while(cin >> inp)
		sDeq.push_back(inp);
	for(auto i=sDeq.begin(); i!=sDeq.end(); ++i)
		cout << *i << endl;

	return 0;
}
