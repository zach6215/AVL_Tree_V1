#include "Node.h"



Node::Node(): keyID(0), lChild(nullptr), rChild(nullptr), height(0), balFactor(0), nullHeight(-1)
{

}

Node::Node(int argKeyID, string argName) : keyID(argKeyID), name(argName), nullHeight(-1)
{

}

Node::~Node()
{


}

//DOES NOT UPDATE SUBTREE
void Node::updateBalFactor()
{
	
	if (lChild != nullptr)
	{
		balFactor = lChild->getHeight();
	}
	else
	{
		balFactor = nullHeight;
	}

	if (rChild != nullptr)
	{
		balFactor -= rChild->getHeight();
	}
	else
	{
		balFactor -= nullHeight;
	}

}

Node * Node::getLeftChild()
{
	return lChild;
}

Node * Node::getRightChild()
{
	return rChild;
}

Node ** Node::leftPointerAccess()
{

	return &lChild;
}

Node ** Node::rightPointerAccess()
{
	return &rChild;
}

int Node::getHeight() const
{
	return height;
}

int Node::getKeyID() const
{
	return keyID;
}

int Node::getBalFactor() const
{
	return balFactor;
}

string Node::getName() const
{
	return name;
}

//DOES UPDATE SUBTREE
int Node::updateHeight()
{
	int lHeight;
	int rHeight;

	if (lChild != nullptr)
	{
		lHeight = lChild->updateHeight() + 1;
	}
	else
	{
		lHeight = 0;
	}

	if (rChild != nullptr)
	{
		rHeight = rChild->updateHeight() + 1;
	}
	else
	{
		rHeight = 0;
	}

	if (rHeight >= lHeight)
	{
		height = rHeight;
	}
	else
	{
		height = lHeight;
	}

	return height;
}

void Node::setHeight(int argHeight)
{
	height = argHeight;
}

void Node::setLeftChild(Node * argNode)
{
	lChild = argNode;
}

void Node::setRightChild(Node * argNode)
{
	rChild = argNode;
}