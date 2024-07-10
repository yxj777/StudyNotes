#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;
istream &f(istream &in)
{
	string x;
	while(in >> x , !in.eof())
	{
		if(in.bad())
			throw runtime_error("IO流出出错");
		if(in.fail())
		{
			cerr << "数据输出错误,请重试" << endl;
			in.clear();
			in.ignore(100,'\n');	//抛弃回车符
			continue;
		}
		cout << x << endl;
	}
	in.clear();
	return in;
}
int main()
{
	
	
	ostringstream out;
	out << "sssss" << endl;
	istringstream inp(out.str());
	f(inp);
	return 0;
}

