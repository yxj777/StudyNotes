#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
	forward_list<int> fList={1,2,3,4,5,6,7,8,9,10,11,12};
	auto curr=fList.begin();
	auto before=fList.before_begin();
	while(curr != fList.end())
	{
		if(*curr%2)
		{
			curr=fList.erase_after(before);
		}else
		{
			before=curr;
			++curr;
		}
	}

	for(auto &i : fList)
		cout << i << " ";
	cout << endl;
	return 0;
}
