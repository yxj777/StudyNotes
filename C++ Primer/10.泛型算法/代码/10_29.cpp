#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
using namespace std;

int main()
{
	vector<string> vec;
	ifstream in("test.txt");
	if(!in)
		cout << "打开文件失败" << endl;
	istream_iterator<string> sIt(in),eof;
	while(sIt != eof)
		vec.push_back(*sIt++);	
	for(auto &s : vec)
		cout << s << endl;
	return 0;
}
