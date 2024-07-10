#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> list1={1,2,3,4,5,6};
	for(auto i=list1.begin(); i!=list1.end(); ++i)
	{
		if(*i % 2==0)
		{
			i=list1.erase(i);
			--i;
		}
		else
		{
			i=list1.insert(i,*i);
			++i;
		}
	}
	for(auto &i : list1)
		cout << i << "\t";
	cout << endl;
	return 0;
}
