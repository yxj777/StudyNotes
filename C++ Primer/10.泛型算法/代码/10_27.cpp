#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec={1,1,2,2,3,4,5,6};	
	list<int> list;
	unique_copy(vec.begin(), vec.end(), back_inserter(list));

	for(auto &i : list)
		cout << i << " ";
	cout << endl;
	return 0;
}
