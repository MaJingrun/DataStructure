#include "LinkedList.h"
#include<iostream>

using namespace std;

int main()
{
	cout << "Hello,World" << endl;
	Chain<int> l;
	l.Insert(0, 1).Insert(1,2).Insert(2, 3);
	cout << l << endl;
	int x;
	l.Delete(2, x);
	cout << l << endl;
	if (l.Find(2,x)) {
		cout << "Found" << endl;
	}
	cout << "3ÔÚµÚ " << l.Search(3) << " ¸ö" << endl;
	return 0;
}