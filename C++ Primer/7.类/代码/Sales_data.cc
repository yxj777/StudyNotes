#include <iostream>
#include <string>
using namespace std;

struct Sales_data
{
	Sales_data()=default;
	Sales_data(const string &s,int i,double p):bookNo(s),units_sold(i),revenue(p*i){}
	Sales_data(const string &s):bookNo(s){}
	Sales_data(istream &);
	string bookNo;			//ISBN号
	unsigned units_sold=0;		//销售量
	double revenue=0.0;		//销售额

	string isbn() const { return bookNo;};		//返回ISBN号
	Sales_data& combine(const Sales_data &rhs)
	{
		units_sold+=rhs.units_sold;
		revenue+=rhs.revenue;
		return *this;
	}
};
Sales_data add(const Sales_data &lh,const Sales_data &rh)
{
	Sales_data sum=lh;
	sum.combine(rh);
	return sum;	
}
istream &read(istream &is,Sales_data &item)
{
	double price;
	cout << "请依次输入 ISBN 销售量 单价" << endl;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue=price * item.units_sold;	
	return is;
}
ostream &print(ostream &os,const Sales_data &item)
{
	os << "ISBN为：" <<  item.isbn() << "\t销售量为： " << item.units_sold \
	   <<"\t销售额为：" << item.revenue;
	return os;	
}
void trans(Sales_data &total)
{
	if(cin)
	{
		Sales_data trans(cin);
		do
		{
			if(total.isbn()==trans.isbn())
				total=add(total,trans);
			else
			{
				print(cout,total);
				total=trans;
				cout << endl;
			}
		}while(read(cin,trans));
		print(cout,total);
		cout << endl;
	}
	else
		cout << "请输入正确的数据" << endl;		
}
Sales_data::Sales_data(istream &is)
{
	read(is,*this);
}
int main()
{
	Sales_data total(cin);
	trans(total);
	return 0;
}
