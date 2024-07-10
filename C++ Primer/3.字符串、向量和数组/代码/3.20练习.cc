#include <iostream>
#include <vector>
using namespace::std;
int main()
{
	vector<int> v;
	int inpt;
	int sum=0;
	decltype(v.size()) i,y;
	while(cin >> inpt)
		v.push_back(inpt);
	for(i=0,y=v.size()-1; i<y; i++,y--)
	{
		sum=v[i]+v[y];
		cout << sum << "\t";
	}
	return 0;
}
