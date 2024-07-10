#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(),words.end());
	words.erase(end_unique, words.end());
}
int main()
{
	string inp;
	vector<string> words;
	while(cin >> inp)
		words.push_back(inp);
	elimDups(words);
	for(auto &s : words)
		cout << s << " ";
	cout << endl <<"个数=" << words.size() << endl;
	return 0;
}
