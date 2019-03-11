
#include <iostream>
#include <string>
#include "AVLTree.h"

using namespace std;

int main()
{
	AVLTree test;

	test.insert(10, "Zach");
	test.insert(5, "Phil");
	test.insert(0, "Sadie");
	test.insert(15, "Ginger");
	test.insert(12, "Tim");
	test.insert(20, "Trevor");
	test.insert(25, "Lisa");
	test.insert(30, "Lloyd");

	test.print(cout);

	system("pause");
	return 0;
}