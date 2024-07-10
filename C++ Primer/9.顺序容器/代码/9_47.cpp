#include <string>
#include <iostream>
using namespace std;
void find_num(string &str, const string &num)
{
	int pos=0;
	while((pos=str.find_first_of(num,pos))!=string::npos)
	{
		cout << str[pos];
		++pos;
	}
	cout << endl;
}

void find_letter(string &str, const string &letter)
{
	int pos=0;
	while((pos=str.find_first_not_of(letter,pos))!=string::npos)
	{
		cout << str[pos];
		++pos;
	}
	cout << endl;
}
int main()
{
	string str="ab2c3d7R4E6";
	string num="123456789";
	string letter="abcdefghijklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTUVWXYZ";
	
	find_num(str,num);
	find_letter(str,num);	
	return 0;
}
