#include <iostream>
using namespace std;
#include "ArrayList.h"

void main()
{
	ArrayList<int> l;
	ArrayList<float> l2;


	for (int i = 0; i < 1000; i++)
	{	
		l.Add(i);
	}

	l.Delete(12);

	for (int i = 0; i < l.GetSize(); i++)
	{
		cout << l[i] << endl;
	}	

}