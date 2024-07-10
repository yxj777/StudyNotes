#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v{1,2,3,4,5,6,7,8,9};
	for(auto i=v.begin() ; i!=v.end() ; ++i)
		cout <<  (((*i) %2) ? (*i)*=2 : *i) << "\t";
	return 0;
}
