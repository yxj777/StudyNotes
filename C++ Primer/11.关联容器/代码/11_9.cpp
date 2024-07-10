#include <iostream>
#include <map>
#include <list>
#include <sstream>
using namespace std;

int main()
{
	int lineNum;
	string sLine,word;
	map<string, list<int>> lineMap;
	while(getline(cin, sLine))
	{
		++lineNum;
		istringstream inWord(sLine);
		while(inWord >> word)
			lineMap[word].push_back(lineNum);
	}

	for(auto i=lineMap.begin(); i!=lineMap.end(); ++i)
	{
		cout << i->first << "：";
		for(auto j=i->second.begin(); j!=i->second.end(); ++j)
			cout << *j << " ";
		cout << endl;
	}
	return 0;
}
