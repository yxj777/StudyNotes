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

	auto findCmp=[sz](const string &a)
			{ return a.size() >=sz; };

	auto wc=find_if(words.begin(), words.end(), findCmp);

	auto outWc=[](const string &s)
		{ cout << s << " " ; };
	for_each(wc, words.end(), outWc); 
	cout << endl;
}
int main()
{
	string inp;
	vector<string> words;
	while(cin >> inp)
		words.push_back(inp);

	biggies(words, 2);
	return 0;
}
