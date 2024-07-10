#include <iostream>
#include <vector>
#include <string>
using namespace std;

void fun(string &s,const string &oldVal,const string &newVal)
{
	int oldSize=oldVal.size(),newSize=newVal.size(),sSize=s.size();
	for(int i=0,j=0; i<sSize; ++i)
	{
		if(s[i] == oldVal[j])	
		{
			if( oldVal == s.substr(i, oldSize))
			{
				s.replace(i, oldSize, newVal);
			}
		}
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
