#include <iostream>
#include "StackVector.h"
#include "StackList.h"

using namespace std;

int main() 
{
    StackVector<int> sv;
    StackList<int> sl;

    sv.push(10);
    sv.push(20);
    sv.push(30);
    cout << sv.pop() << endl;
    cout << sv.pop() << endl;

    cout << endl;   

    sl.push(100);
    sl.push(200);
    sl.push(300);
    cout << sl.pop() << endl;
    cout << sl.pop() << endl;
}
