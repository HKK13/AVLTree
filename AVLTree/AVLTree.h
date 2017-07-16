#pragma once

struct Node {
	Node *parent, *leftChild, *rightChild;
	int balanceFactor;
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
