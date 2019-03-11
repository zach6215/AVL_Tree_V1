#pragma once
#include "Node.h"
#include <iomanip>


class AVLTree
{
	int numNodes;
	Node * root;
	const int leftImbalLimit;
	const int rightImbalLimit;

	void prvtPrint(ostream& out, Node * curNode);
	void prvtDeconst(Node * deleteMe);


public:
	AVLTree();
	~AVLTree();

	void insert(int argKeyID, string argName);
	void print(ostream& out);


};

