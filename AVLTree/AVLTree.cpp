#include "AVLTree.h"

AVLTree::AVLTree() {
	this->root = nullptr;
}

int AVLTree::Search(int item)
{
	return 0;
}

void AVLTree::Insert(int item)
{
}

void AVLTree::Delete(int item)
{
}

void AVLTree::LLRotation(Node * node)
{
	if (node->getBalanceFactor() > -2)
		return;

	Node *leftChild = node->leftChild;
	node->leftChild = leftChild->rightChild;

	if (node->leftChild)
		node->leftChild->parent = node;

	leftChild->parent = node->parent;
	leftChild->rightChild = node;
	leftChild->rightChild->parent = leftChild;

	if (leftChild->parent == nullptr)
		this->root = leftChild;

	this->root->getHeight();
}

void AVLTree::RRRotation(Node * node)
{
	if (node->getBalanceFactor() < 2)
		return;

	Node *rightChild = node->rightChild;
	node->rightChild = rightChild->leftChild;
	
	if (node->rightChild)
		node->rightChild->parent = node;
	
	rightChild->parent = node->parent;
	rightChild->leftChild = node;
	rightChild->leftChild->parent = rightChild;

	if (rightChild->parent == nullptr)
		this->root = rightChild;

	this->root->getHeight();
}

void AVLTree::LRRotation(Node * node)
{
	LLRotation(node->leftChild);
	RRRotation(node);
}

void AVLTree::RLRotation(Node * node)
{
	RRRotation(node->rightChild);
	LLRotation(node);
}
