#pragma once

struct Node {
	Node *parent, *leftChild, *rightChild;
	int leftHeight, rightHeight;
	int nodeValue;

	Node(int value) {
		this->leftHeight = 0;
		this->rightHeight = 0;
		this->leftChild = nullptr;
		this->rightChild = nullptr;
		this->parent = nullptr;
		this->nodeValue = value;
	}

	int getBalanceFactor() {
		return this->leftHeight - this->rightHeight;
	}

	int getHeight() {
		this->leftHeight = 0;
		this->rightHeight = 0;

		if (this->leftChild)
			this->leftHeight = 1 + this->leftChild->getHeight();
		if (this->rightChild)
			this->rightHeight = 1 + this->rightChild->getHeight();

		return this->leftHeight <= this->rightHeight ? this->rightHeight : this->leftHeight;
	}
};

class AVLTree {
public:

	AVLTree();

	int Search(int item);
	void Insert(int item);
	void Delete(int item);
private:
	void LLRotation(Node * node);
	void RRRotation(Node * node);
	void LRRotation(Node * node);
	void RLRotation(Node * node);
	Node *root;
};
