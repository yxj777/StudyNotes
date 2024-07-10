#include <iostream>
#include <string>
using namespace std;

struct Person
{
	friend istream &read(istream &is,Person &item);
	friend ostream &print(ostream &os,Person &item);
private:
	string name;
	string address;
public:
	string getName() const { return name;}
	string getAddress() const { return address;}
};
istream &read(istream &is,Person &item)
{
	is >> item.name >> item.address ;
	return is;
}
ostream &print(ostream &os,Person &item)
{
	os << item.getName() << "\t" << item.getAddress();
	return os;
}

int main()
{
	Person a;	
	read(cin,a);
	print(cout,a);
	cout << endl;
}
