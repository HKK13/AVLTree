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
	if (this->root == nullptr) {
		this->root = new Node(item);
		this->root->getHeight();
		return;
	}

	Node * position = this->root;

	do {
		if (position->nodeValue == item) {
			return; // Duplicate.
		}
		else if (position->nodeValue > item) { // Less than current val.
			if (position->leftChild == nullptr) {
				position->leftChild = new Node(item);
				position->leftChild->parent = position;
				return;
			}
			else
				position = position->leftChild;
		}
		else if (position->nodeValue < item) { // Greater than current val.
			if (position->rightChild == nullptr) {
				position->rightChild = new Node(item);
				position->rightChild->parent = position;
				return;
			}
			else
				position = position->rightChild;
		}

	} while (position && (position->leftChild || position->rightChild));

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
