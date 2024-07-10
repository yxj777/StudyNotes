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
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);

	auto sortCmp=[](const string &a, const string &b)
			{ return a.size() <b.size(); };
	stable_sort(words.begin(),words.end(), sortCmp);

	auto partCmp=[sz](const string &a)
			{ return a.size() >=sz; };

	auto wc=partition(words.begin(), words.end(), partCmp);

	auto outWc=[](const string &s)
		{ cout << s << " " ; };
	for_each(words.begin(), wc, outWc); 
	cout << endl;
}
int main()
{
	string inp;
	vector<string> words;
	while(cin >> inp)
		words.push_back(inp);

	biggies(words, 5);
	return 0;
}
