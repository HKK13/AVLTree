#include "AVLTree.h"
#include <iostream>
#include <string>


AVLTree::AVLTree() {
	this->root = nullptr;
}

Node * AVLTree::Search(int item)
{
	Node * tempSearch = this->root;

	while (tempSearch && (tempSearch->leftChild || tempSearch->rightChild)) {
		if (item == tempSearch->nodeValue) {
			break;
		}
		else if (item < tempSearch->nodeValue)
			tempSearch = tempSearch->leftChild;
		else if (item > tempSearch->nodeValue)
			tempSearch = tempSearch->rightChild;
	}

	return tempSearch;
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
				break;
			}

			position = position->leftChild;
		}
		else if (position->nodeValue < item) { // Greater than current val.
			if (position->rightChild == nullptr) {
				position->rightChild = new Node(item);
				position->rightChild->parent = position;
				break;
			}
			
			position = position->rightChild;
		}

	} while (position);

	this->DecideRotation(position);
}

void AVLTree::Delete(int item)
{
}

void AVLTree::DecideRotation(Node * node)
{
	// BalanceFactor = LeftHeight - RightHeight;

	if (node->parent) {
		this->root->getHeight();
		int balance = node->parent->getBalanceFactor();

		if (balance == 2 && node->getBalanceFactor() == 1) {
			// Single Right Rotation
			this->RRotation(node->parent);
		}
		else if (balance == 2) {
			// Left Right Rotation
			this->LRRotation(node->parent);
		}
		else if (balance == -2 && node->getBalanceFactor() == -1) {
			// Single Left Rotation
			this->LRotation(node->parent);
		}
		else if (balance == -2) {
			// Right Left Rotation
			this->RLRotation(node->parent);
		}
	}

}

void AVLTree::Print() {
	std::cout << this->root->nodeValue << std::endl;

	std::cout << this->root->leftChild->nodeValue << std::endl;

	std::cout << this->root->rightChild->nodeValue << std::endl;


}

int AVLTree::getHeight()
{
	return this->root->getHeight();
}

void AVLTree::RRotation(Node * node)
{
	Node * tempLeftChild = node->leftChild;
	node->leftChild = tempLeftChild->rightChild;

	if (node->leftChild)
		node->leftChild->parent = node;

	tempLeftChild->parent = node->parent;
	
	if (node->parent)
		node->parent->rightChild = tempLeftChild;
	
	tempLeftChild->rightChild = node;
	node->parent = tempLeftChild;

	if (tempLeftChild->parent == nullptr)
		this->root = tempLeftChild;

	this->root->getHeight();
}

void AVLTree::LRotation(Node * node)
{
	Node * tempRightChild = node->rightChild;
	node->rightChild = tempRightChild->leftChild;
	
	if (node->rightChild)
		node->rightChild->parent = node;
	
	tempRightChild->parent = node->parent;

	if (node->parent)
		node->parent->leftChild = tempRightChild;
	
	tempRightChild->leftChild = node;
	node->parent = tempRightChild;

	if (tempRightChild->parent == nullptr)
		this->root = tempRightChild;

	this->root->getHeight();
}

void AVLTree::LRRotation(Node * node)
{
	LRotation(node->leftChild);
	RRotation(node);
}

void AVLTree::RLRotation(Node * node)
{
	RRotation(node->rightChild);
	LRotation(node);
}
