#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	LinkedList<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.PrintAll();
	cout << "Count: " << list.GetCount() << endl;
	return 0;
}