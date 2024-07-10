#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Sales_data
{
	Sales_data()=default;
	Sales_data(const string &s,int i,double p):bookNo(s),units_sold(i),revenue(p*i){}
	Sales_data(const string &s):bookNo(s){}
	Sales_data(istream &);
	string bookNo;			//ISBN号
	unsigned units_sold;		//销售量
	double revenue;		//销售额

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


int main(int argc, char *argv[])
{
	if(argc!=3)
	{
		cerr << "请给出文件名" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if(!in)
	{
		cerr << "无法打开文件" << endl;
		return -1;
	}
	ofstream out(argv[2]);
	if(!out)
	{
		cerr << "无法打开输出文件" << endl;
		return -1;
	}
	Sales_data total;
	if (read(in,total))
	{
		Sales_data trans;
		while(read(in,trans))
		{
			if(total.isbn()==trans.isbn())
				total.combine(trans);
			else
			{
				print(out,total)<<endl;
				total=trans;
			}
		}
		print(out,total) << endl;
	}
	else
	{
		cerr << "No data?" << endl;
	}
	return 0;
}

