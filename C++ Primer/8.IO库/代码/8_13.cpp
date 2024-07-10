#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

struct PersonInfo{
	string name;
	vector<string> phones;
};
bool valid(const string &s){return true;}
int main()
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;	
	ifstream in("test_phone.txt");
	if(!in)
		cout << "打开文件失败" << endl;
	while(getline(in,line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while(record >> word)
			info.phones.push_back(word);
		people.push_back(info);
		
	}
	ostringstream os;
	for( const auto &entry : people)
	{
		ostringstream formtted, badNums;
		for(const auto &nums : entry.phones)
		{
			if(!valid(nums))
				badNums << " " << nums;
			else
				formtted << " " << nums;
		}
		if(badNums.str().empty())
			os << entry.name << " " << formtted.str() << endl;
		else
			cerr << "输入出错:" << entry.name << "错误内容为：" <<badNums.str() << endl;
		
	}
	cout << os.str();
	return 0;
}
