#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
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
	cout << endl ;
	stable_sort(words.begin(), words.end(), isShorter);
	for(const auto &s : words)
		cout << s << " ";
	cout << endl;
	return 0;
}
