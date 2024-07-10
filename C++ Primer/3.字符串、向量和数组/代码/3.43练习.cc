#include <iostream>
using namespace std;

int main()
{
	int ia[2][3]={1,2,3,4,5,6};
	cout << "范围for版本" << endl;
	for(int (&row)[3]:ia)
		for(int &col:row)
			cout << col << "\t";
	cout << endl << "下标版本" << endl;
	for(int i=0 ; i!=2 ; ++i)
		for(int j=0 ; j!=3 ; ++j)
			cout << ia[i][j] << "\t";
	cout << endl << "指针版本" << endl;
	for(int (*i)[3]=begin(ia) ; i!=end(ia) ; ++i)
		for( int *j=begin(*i) ; j!=end(*i) ; ++j)
			cout << *j << "\t";
	return 0;
}
