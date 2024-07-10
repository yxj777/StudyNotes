#include <iostream>
#include <vector>
#include <string>
using namespace std;

void fun(string &s,const string &oldVal,const string &newVal)
{
	auto sBegin=s.begin();
	auto oldBegin=oldVal.begin();	
	int oldSize=oldVal.size(),newSize=newVal.size();
	while(sBegin != s.end())
	{
		if(*sBegin == *oldBegin)
		{
			int pos=sBegin-s.begin();
			string sonStr=s.substr(pos, oldSize);
			if(oldVal == sonStr)
			{
				oldBegin=oldVal.begin();
				sBegin=s.erase(sBegin,sBegin+oldSize);
				sBegin=s.insert(sBegin,newVal.begin(),newVal.end());
				sBegin+=newSize-1;
			}
		}	
		++sBegin;
	}
}
int main()
{
	string s="tho tho tho thru tho thru thru thru 2222";
	cout << "原：" << s << endl;
	fun(s,"tho","1");
	cout << "改：" << s << endl;

	cout << "原：" << s << endl;
	fun(s,"thru","2");
	cout << "改：" << s << endl;
	return 0;
}
