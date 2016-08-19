#include "LinearList.h"
#include<iostream>

using namespace std;

int main()
{
	LinearList<int> L(10);
	cout << "Length= " << L.Length() << endl;
	L.Insert(0, 1).Insert(1, 6);
	int x;
	L.Find(1, x);
	cout << "First element is " << x << endl;
	return 0;
}