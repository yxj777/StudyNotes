#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	ifstream in("test.txt");
	if(!in)
		cerr << "读取文件失败" << endl;
	string line,word;
	vector<string> file;
	while(getline(in,line))
	{
		file.push_back(line);	
	}
	for(auto i=file.begin(); i<file.end(); ++i)
	{
		istringstream record(*i);
		while(record >> word)
			cout << word << " ";
		cout << endl;

	}
	return 0;
}
