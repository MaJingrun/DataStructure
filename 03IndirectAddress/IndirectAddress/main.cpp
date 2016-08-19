#include "IndirectAddress.h"
#include<iostream>
using namespace std;

int main()
{
	IndirectList<int> l;
	l.Insert(0, 0).Insert(1, 10).Insert(2,20);
	int x;
	if (l.Find(4,x)) {
		cout << x << endl;
	}
	if (l.Search(20))
		cout << l.Search(20) << endl;
	l.Delete(3, x);
	cout << l << endl;
	return 0;
}