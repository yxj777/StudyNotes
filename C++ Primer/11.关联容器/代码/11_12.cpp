#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;
int main()
{
	int n;
	string s;
	vector<pair<string, int>> vec;

	while(cin >> s && cin >> n)
		vec.push_back(pair<string, int>(s, n));	

	for(auto &i : vec)
		cout << "string = " << i.first <<"，int = " << i.second << endl;

}
