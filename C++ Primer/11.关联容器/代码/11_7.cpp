#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	map<string, vector<string>> mapTest;
	string firstName,lastName;
	while(cin >> firstName && cin >> lastName)
		mapTest[lastName].push_back(firstName);

	for( auto &i : mapTest )
	{
		cout << i.first << "家：";
		for( auto &j : i.second)
			cout << i.first << j << " ";
		cout << endl;
	}
	return 0;
}
