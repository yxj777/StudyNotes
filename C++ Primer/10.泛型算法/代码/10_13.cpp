#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp( const string &s)
{
	return s.size() > 5;
}
int main()
{
	vector<string> words;
	string inp;
	while(cin >> inp)
		words.push_back(inp);
	auto max=partition(words.begin(), words.end(), cmp);

	for( auto s=words.begin(); s!=max; ++s)
		cout << *s << " " ;
	cout << endl;
	return 0;
}

