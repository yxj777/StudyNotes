#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void wri(const string &name,vector<string> &rec)
{
	ifstream in(name);
	if(!in)
		cerr << "无法打开文件" << endl;
	string line;
	while(getline(in,line))
		rec.push_back(line);
	in.close();
}
int main()
{
	vector<string> rec;
	int j;
	string name="test.txt";
	wri(name,rec);
	for (auto i=rec.begin();i<rec.end();++i)
		cout << *i << endl;
	cin >> j;
	return 0;
}