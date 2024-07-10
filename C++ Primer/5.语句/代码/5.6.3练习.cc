#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
	int i,j;
	cout << "请输入被除数和被除数" << endl;
	while(cin >> i >> j)
	{
		try
		{
			if(j==0)
				throw range_error("除数不能为0");
			cout << "结果为："<<i/j << endl;
			break;
		}catch(range_error err)
		{
			cout << err.what() << endl;
			cout << "需要重新输入吗？(y/n)" << endl;
			char ch;
			cin >> ch;
			while(ch!='y' && ch!='n')
			{
				cout << "请输入y/n" << endl;
				cin >> ch;
			}	
			if(ch!='y')
				break;
			else
				cout << "请输入被除数和被除数" << endl;
		}
	}
	return 0;
}
