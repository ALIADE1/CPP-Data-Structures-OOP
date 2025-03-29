#include <iostream>
#include "QueueLI.h"   
#include "QueueVector.h"  
using namespace std;

void main()
{
	QueueList<int> ql; 
	ql.EnQueue(1);
	ql.EnQueue(2);
	ql.EnQueue(3);
	ql.EnQueue(4);
	ql.EnQueue(5);

	cout << "QueueList output: ";
	while (!ql.IsEmpty())
	{
		cout << ql.DeQueue() << " ";
	}
	cout << endl;

	QueueVector<int> qv;
	qv.EnQueue(10);
	qv.EnQueue(20);
	qv.EnQueue(30);
	qv.EnQueue(40);
	qv.EnQueue(50);

	cout << "QueueVector output: ";
	while (!qv.IsEmpty())
	{
		cout << qv.DeQueue() << " ";
	}
	cout << endl;

}
