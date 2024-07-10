#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main()
{
	list<int> xList;
	deque<int> dEven;
	deque<int> dOdd;
	int num;
	while(cin >> num)
		xList.push_back(num);

	for(auto i=xList.begin(); i!=xList.end(); ++i)
	{
		if(*i%2)
			dOdd.push_back(*i);
		else
			dEven.push_back(*i);
	}
	cout << "偶数为：";
	for(auto &i : dEven)
		cout << i << "\t";
	cout << endl << "奇数为：";
	for(auto &i : dOdd)
		cout  << i << "\t";
	return 0;
}
