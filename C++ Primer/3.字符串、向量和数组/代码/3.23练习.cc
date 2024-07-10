#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> num;
	int x;
	for(int i=0; i<10; i++)
	{
		cin >> x;
		num.push_back(x);	
	}
	for(auto it=num.begin(); it!=num.end(); it++)
	{
		(*it)*=2;
		cout << *it << "\t";
	}
	return 0;
}
