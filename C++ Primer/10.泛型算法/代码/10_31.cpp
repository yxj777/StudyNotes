#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
	ifstream in("test.txt");
	if(!in)
		cout << "打开文件失败" << endl;	
	ofstream outOdd("test1.txt"),outEven("test2.txt");
	if(!outOdd)
		cout << "打开奇数文件失败" << endl;
	if(!outEven)
		cout << "打开偶数文件失败" << endl;

	istream_iterator<int> it(in),eof;
	ostream_iterator<int> otOdd(outOdd," "),otEven(outEven, "\n");
	
	while(it != eof)
	{
		if(*it%2==0)
			*otEven++=*it;
		else
			*otOdd++=*it;
		++it;
	}
	return 0;
}
