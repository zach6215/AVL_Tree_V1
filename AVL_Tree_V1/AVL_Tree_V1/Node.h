#pragma once
#include <string>

using namespace std;

class Node
{
private:
	int keyID;
	string name;		//Template later
	Node * lChild;
	Node * rChild;
	int height;
	int balFactor;
	const int nullHeight;

public:
	Node();
	Node(int argKeyID, string argName);
	~Node();


	void updateBalFactor();
	Node * getLeftChild();
	Node ** leftPointerAccess();
	Node ** rightPointerAccess();
	Node * getRightChild();
	int getHeight() const;
	int getKeyID() const;
	int getBalFactor() const;
	string getName() const;
	void setLeftChild(Node * argNode);
	void setRightChild(Node * argNode);

	int updateHeight();

	void setHeight(int argHeight);

};

