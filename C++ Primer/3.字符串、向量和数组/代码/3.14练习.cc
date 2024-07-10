#include <iostream>
#include <vector>
using namespace::std;
int main()
{
	vector<int> v;
	int x;
	while(cin >> x)
		v.push_back(x);
	for(auto y:v)
		cout << y << "\t";
	cout << endl;
	return 0;
}
