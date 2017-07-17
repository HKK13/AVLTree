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
	Node * temp = node;

	do {
		temp->getHeight();
		int balance = temp->getBalanceFactor();

		if (balance == 2 && temp->leftChild && temp->leftChild->getBalanceFactor() == 1) {
			// Single Right Rotation
			this->RRotation(temp);
		}
		else if (balance == 2) {
			// Left Right Rotation
			this->LRRotation(temp);
		}
		else if (balance == -2 && temp->rightChild && temp->rightChild->getBalanceFactor() == -1) {
			// Single Left Rotation
			this->LRotation(temp);
		}
		else if (balance == -2) {
			// Right Left Rotation
			this->RLRotation(temp);
		}

		temp = temp->parent;
	} while (temp);
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
	Node * temp = node->leftChild;
	node->leftChild = temp->rightChild;
	temp->rightChild = nullptr;

	if (node->leftChild) {
		node->leftChild->parent = node;
	}

	temp->rightChild = node;
	temp->parent = node->parent;
	node->parent = temp;

	if (temp->parent && temp->parent->nodeValue < temp->nodeValue) {
		temp->parent->rightChild = temp;
	}
	else if (temp->parent) {
		temp->parent->leftChild = temp;
	}
	else {
		this->root = temp;
	}
}

void AVLTree::LRotation(Node * node)
{
	Node * temp = node->rightChild;
	node->rightChild = temp->leftChild;
	temp->leftChild = nullptr;

	if (node->rightChild) {
		node->rightChild->parent = node;
	}

	temp->leftChild = node;
	temp->parent = node->parent;
	node->parent = temp;

	if (temp->parent && temp->parent->nodeValue < temp->nodeValue) {
		temp->parent->rightChild = temp;
	}
	else if (temp->parent) {
		temp->parent->leftChild = temp;
	}
	else {
		this->root = temp;
	}
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
