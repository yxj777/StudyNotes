#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec={1,2,3,4,5};
	cout << "使用begin()\t"	<< *(vec.begin())	<< endl;
	cout << "使用front()\t"	<< vec.front()		<< endl;
	cout << "使用at()\t"	<< vec.at(0)		<< endl;
	cout << "使用[]\t\t"	<< vec[0]		<< endl;
	return 0;
}
