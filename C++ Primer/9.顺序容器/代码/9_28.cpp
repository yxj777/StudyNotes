#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

bool fList_insert(forward_list<string> &fList, string str1, string str2)
{
	bool nRet=false;
	auto curr=fList.begin();
	auto before=fList.before_begin();
	while(curr != fList.end())
	{
		if(*curr == str1)
		{
			curr=fList.insert_after(curr,str2);
			break;
		}
		else
			before=curr;
		++curr;
	}
	if(curr == fList.end())
	{
		fList.insert_after(before,str2);
	}
	return nRet;
}
int main()
{
	forward_list<string> fList={"1","2","4"};
	string str1="5",str2="3";
	bool ret=fList_insert(fList,str1,str2);
	for(auto &i : fList)
		cout << i << endl;
	return 0;
}
