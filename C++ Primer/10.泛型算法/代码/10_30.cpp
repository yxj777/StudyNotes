#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
	istream_iterator<string> it(cin),eof;
	ostream_iterator<string> out(cout, "\n");
	vector<string> vec;

	while(it != eof)
		vec.push_back(*it++);

	sort(vec.begin(),vec.end());
	copy(vec.begin(),vec.end(),out);
	return 0;
}
