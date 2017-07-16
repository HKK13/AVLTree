#pragma once

struct Node {
	Node *parent, *leftChild, *rightChild;
	int leftHeight, rightHeight;
	int nodeValue;

	Node(int value) {
		this->leftHeight = 0;
		this->rightHeight = 0;
		this->nodeValue = value;
	}

	int getBalanceFactor() {
		return leftHeight - rightHeight;
	}

	int getHeight() {
		if (leftChild)
			leftHeight = 1 + leftChild->getHeight();
		if (rightChild)
			rightHeight = 1 + rightChild->getHeight();

		return leftHeight < rightHeight ? rightHeight : leftHeight;
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
