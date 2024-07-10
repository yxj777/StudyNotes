#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main()
{
	vector<int> vec={1,2,3,4,5,6,7,8,9};
	list<int> ls1,ls2,ls3;

	copy(vec.begin(), vec.end(), inserter(ls1, ls1.begin()));
	copy(vec.begin(), vec.end(), back_inserter(ls2));
	copy(vec.begin(), vec.end(), front_inserter(ls3));
	
	for(auto &i : ls1)
		cout << i << " ";
	cout << endl;
	for(auto &i : ls2)
		cout << i << " ";
	cout << endl;
	for(auto &i : ls3)
		cout << i << " ";
	cout << endl;
	return 0;
}
