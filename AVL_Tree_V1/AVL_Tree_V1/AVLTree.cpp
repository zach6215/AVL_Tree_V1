#include "AVLTree.h"
#include <vector>



AVLTree::AVLTree() : root(nullptr), leftImbalLimit(1), rightImbalLimit(-1)
{

}


AVLTree::~AVLTree()
{
	prvtDeconst(root);
}

//Left right current tree traversal
void AVLTree::prvtDeconst(Node * deleteMe)
{
	if (deleteMe != nullptr)
	{
		prvtDeconst(deleteMe->getLeftChild());
		prvtDeconst(deleteMe->getRightChild());
		delete deleteMe;
	}
}

//Uses double indirection to store path to inserted node
//Inorder to update patents's nodes heights, recursive function for each parents' subtree
//Would be better if height was updated as path was found or incramented when going back up vai parent vector
//Left and right rotations should be their own function

void AVLTree::insert(int argKeyID, string argName)
{
	Node * newNode = new Node(argKeyID, argName);
	Node ** parentPointerItt = &root;
	vector <Node **> unbalancedParents;
	bool inserted = false;
	Node * child;
	Node * grandChild;


	while (!inserted)
	{
		if ((*parentPointerItt) == nullptr)
		{
			(*parentPointerItt) = newNode;
			newNode->updateHeight();

			inserted = true;

		}
		else if (newNode->getKeyID() < (*parentPointerItt)->getKeyID())
		{
			unbalancedParents.push_back(parentPointerItt);

			parentPointerItt = (*parentPointerItt)->leftPointerAccess();
		}
		else if (newNode->getKeyID() > (*parentPointerItt)->getKeyID())
		{
			unbalancedParents.push_back(parentPointerItt);

			parentPointerItt = (*parentPointerItt)->rightPointerAccess();
		}
		else
		{
			//Throw "same node" exeption
		}
	}

	//Balance all unbalanced nodes

	for (int i = unbalancedParents.size() - 1; i >= 0; i--)
	{
		(*unbalancedParents[i])->updateHeight();
		(*unbalancedParents[i])->updateBalFactor();

		if ((*unbalancedParents[i])->getBalFactor() > leftImbalLimit)
		{
			//Left Rotation
			grandChild = (*unbalancedParents[i]);
			child = grandChild->getLeftChild();


			if (child->getRightChild() != nullptr)
			{
				grandChild->setLeftChild(child->getRightChild());
				child->setRightChild(grandChild->getLeftChild()->getLeftChild());
				grandChild->getLeftChild()->setLeftChild(child);


				child = grandChild->getLeftChild();
			}


			grandChild->setLeftChild(child->getRightChild());
			child->setRightChild(grandChild);
			(*unbalancedParents[i]) = child;

			//Update nodes' heights and balFactors
			(*unbalancedParents[i])->updateHeight();
			(*unbalancedParents[i])->updateBalFactor();
			(*unbalancedParents[i])->getLeftChild()->updateBalFactor();
			(*unbalancedParents[i])->getRightChild()->updateBalFactor();
		}
		else if ((*unbalancedParents[i])->getBalFactor() < rightImbalLimit)
		{
			//Right Rotation
			grandChild = (*unbalancedParents[i]);
			child = grandChild->getRightChild();

			if(child->getLeftChild() != nullptr)
			{
				grandChild->setRightChild(child->getLeftChild());
				child->setLeftChild(grandChild->getRightChild()->getRightChild());
				grandChild->getRightChild()->setRightChild(child);

				
				child = grandChild->getRightChild();
			}


			grandChild->setRightChild(child->getLeftChild());
			child->setLeftChild(grandChild);
			(*unbalancedParents[i]) = child;

			//Update nodes' heights and balFactors
			(*unbalancedParents[i])->updateHeight();
			(*unbalancedParents[i])->updateBalFactor();
			(*unbalancedParents[i])->getLeftChild()->updateBalFactor();
			(*unbalancedParents[i])->getRightChild()->updateBalFactor();

		}

		unbalancedParents.pop_back();
	}


}

void AVLTree::print(ostream& out)
{
	if (root == nullptr)
	{
		out << "Empty tree";
	}
	else
	{
		prvtPrint(out, root);
	}

}

//Prints ordered list
//Left -> Current -> Right tree traversal
void AVLTree::prvtPrint(ostream& out, Node * curNode)
{
	if (curNode->getLeftChild() != nullptr)
	{
		prvtPrint(out, curNode->getLeftChild());
	}

	out.width(20);
	out << left << curNode->getKeyID() << curNode->getName() << '\n';

	if (curNode->getRightChild() != nullptr)
	{
		prvtPrint(out, curNode->getRightChild());
	}

}