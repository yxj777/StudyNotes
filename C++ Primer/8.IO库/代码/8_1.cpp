#include <iostream>
#include <stdexcept>
using namespace std;
istream & f(istream &in)
{
	int x;
	while(in >> x , !in.eof())
	{
		if(in.bad())
			throw runtime_error("IO��������");
		if(in.fail())
		{
			cerr << "�����������,������" << endl;
			in.clear();
			in.ignore(100,'\n');	//�����س���
			continue;
		}
		cout << x << endl;
	}
	in.clear();
	return in;
}
int main()
{
	f(cin);
	return 0;
}
