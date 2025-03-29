#include <iostream>
using namespace std;
#include "bst.h"

int main() {
	BST<int> bst;
	bst.AddValueRecursive(50);
	bst.AddValueRecursive(48);
	bst.AddValueRecursive(70);
	bst.AddValueRecursive(30);
	bst.AddValueRecursive(65);
	bst.AddValueRecursive(90);
	bst.AddValueRecursive(20);
	bst.AddValueRecursive(32);
	bst.AddValueRecursive(67);
	bst.AddValueRecursive(98);
	bst.AddValueRecursive(15);
	bst.AddValueRecursive(25);
	bst.AddValueRecursive(31);
	bst.AddValueRecursive(35);
	bst.AddValueRecursive(66);
	bst.AddValueRecursive(69);
	bst.AddValueRecursive(94);
	bst.AddValueRecursive(99);

	cout << "Exists(99): " << (bst.Exists(99) ? "true" : "false") << endl;
	cout << "Exists(2): " << (bst.Exists(2) ? "true" : "false") << endl;

	return 0;
}
