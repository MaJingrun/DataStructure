#include "LinkedList.h"
#include<iostream>
using namespace std;

int main()
{
	Chain<int> l;
	l.Insert(0, 2).Insert(1, 5).Insert(2,5).Insert(3, 4);
	l.BinSort(5);
	cout << l << endl;
	return 0;
}