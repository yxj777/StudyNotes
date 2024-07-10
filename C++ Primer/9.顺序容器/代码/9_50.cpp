#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> vec={"1","10","20","12"};
	int sum=0;
	for(auto &i : vec)
	{
		sum+=stoi(i);
	}
	cout << sum << endl;
	return 0;
}
