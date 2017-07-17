#include "AVLTree.h"
#include "gtest/gtest.h"
#include <string>


TEST(Node, TestNodeConstruct) {
	Node * node = new Node(10);

	ASSERT_EQ(node->nodeValue, 10);
	ASSERT_EQ(node->rightChild, nullptr);
	ASSERT_EQ(node->leftChild, nullptr);
	ASSERT_EQ(node->leftHeight, 0);
	ASSERT_EQ(node->rightHeight, 0);
	ASSERT_EQ(node->parent, nullptr);
}

TEST(Node, TestNodeHeight) {
	Node * node = new Node(5);
	node->leftChild = new Node(4);
	node->leftChild->parent = node;
	node->rightChild = new Node(9);
	node->rightChild->parent = node;

	node->leftChild->leftChild = new Node(3);
	node->leftChild->leftChild->parent = node->leftChild;
	node->leftChild->rightChild = new Node(2);
	node->leftChild->rightChild->parent = node->leftChild;

	node->rightChild->rightChild = new Node(10);
	node->rightChild->rightChild->parent = node->rightChild;
	node->rightChild->leftChild = new Node(7);
	node->rightChild->leftChild->parent = node->rightChild;

	EXPECT_EQ(node->getHeight(), 2);
}

TEST(Node, TestNodeBalanceUnbalanced) {
	Node * node = new Node(5);
	node->leftChild = new Node(4);
	node->leftChild->parent = node;

	node->leftChild->leftChild = new Node(3);
	node->leftChild->leftChild->parent = node->leftChild;
	node->leftChild->rightChild = new Node(2);
	node->leftChild->rightChild->parent = node->leftChild;
	node->getHeight();

	EXPECT_EQ(node->getBalanceFactor(), 2);
}

TEST(Node, TestNodeBalanceBalanced) {
	Node * node = new Node(5);
	node->leftChild = new Node(4);
	node->leftChild->parent = node;
	node->rightChild = new Node(9);
	node->rightChild->parent = node;

	node->leftChild->leftChild = new Node(3);
	node->leftChild->leftChild->parent = node->leftChild;
	node->leftChild->rightChild = new Node(2);
	node->leftChild->rightChild->parent = node->leftChild;

	node->rightChild->rightChild = new Node(10);
	node->rightChild->rightChild->parent = node->rightChild;
	node->rightChild->leftChild = new Node(7);
	node->rightChild->leftChild->parent = node->rightChild;

	node->getHeight();
	EXPECT_EQ(node->getBalanceFactor(), 0);
}

TEST(AVLTree, TestSingleLeftRotation) {
	Node * node = new Node(5);
	node->leftChild = new Node(4);
	node->leftChild->parent = node;
	node->rightChild = new Node(6);
	node->rightChild->parent = node;

	node->leftChild->leftChild = new Node(3);
	node->leftChild->leftChild->parent = node->leftChild;
	node->leftChild->leftChild->leftChild = new Node(2);
	node->leftChild->leftChild->leftChild->parent = node->leftChild->leftChild;

	AVLTree tree = AVLTree();
	tree.setRoot(node);
	tree.RRotation(tree.getRoot()->leftChild);

	node = tree.getRoot();

	EXPECT_EQ(node->nodeValue, 5);
	EXPECT_EQ(node->leftChild->nodeValue, 3);
	EXPECT_EQ(node->leftChild->parent, node);
	EXPECT_EQ(node->leftChild->rightChild->nodeValue, 4);
	EXPECT_EQ(node->leftChild->rightChild->parent, node->leftChild);
	EXPECT_EQ(node->leftChild->leftChild->nodeValue, 2);
	EXPECT_EQ(node->leftChild->leftChild->parent, node->leftChild);
	EXPECT_EQ(node->rightChild->nodeValue, 6);
	EXPECT_EQ(node->rightChild->parent, node);
}

TEST(AVLTree, TestSingleRightRotation) {
	Node * node = new Node(10);
	node->leftChild = new Node(9);
	node->leftChild->parent = node;
	node->rightChild = new Node(15);
	node->rightChild->parent = node;

	node->rightChild->rightChild = new Node(20);
	node->rightChild->rightChild->parent = node->rightChild;
	node->rightChild->rightChild->rightChild = new Node(24);
	node->rightChild->rightChild->rightChild->parent = node->rightChild->rightChild;

	AVLTree tree = AVLTree();
	tree.setRoot(node);
	tree.LRotation(tree.getRoot()->rightChild);

	node = tree.getRoot();

	EXPECT_EQ(node->nodeValue, 10);
	EXPECT_EQ(node->rightChild->nodeValue, 20);
	EXPECT_EQ(node->rightChild->parent, node);
	EXPECT_EQ(node->rightChild->rightChild->nodeValue, 24);
	EXPECT_EQ(node->rightChild->rightChild->parent, node->rightChild);
	EXPECT_EQ(node->rightChild->leftChild->nodeValue, 15);
	EXPECT_EQ(node->rightChild->leftChild->parent, node->rightChild);
	EXPECT_EQ(node->leftChild->nodeValue, 9);
	EXPECT_EQ(node->leftChild->parent, node);
}

TEST(AVLTree, TestDoubleLeftRotation) {
	Node * node = new Node(10);
	node->leftChild = new Node(6);
	node->leftChild->parent = node;
	node->rightChild = new Node(20);
	node->rightChild->parent = node;

	node->leftChild->leftChild = new Node(3);
	node->leftChild->leftChild->parent = node->leftChild;
	node->leftChild->leftChild->rightChild = new Node(4);
	node->leftChild->leftChild->rightChild->parent = node->leftChild->leftChild;

	AVLTree tree = AVLTree();
	tree.setRoot(node);
	tree.LRRotation(tree.getRoot()->leftChild);

	node = tree.getRoot();

	EXPECT_EQ(node->nodeValue, 10);
	EXPECT_EQ(node->leftChild->nodeValue, 4);
	EXPECT_EQ(node->leftChild->parent, node);
	EXPECT_EQ(node->leftChild->rightChild->nodeValue, 6);
	EXPECT_EQ(node->leftChild->rightChild->parent, node->leftChild);
	EXPECT_EQ(node->leftChild->leftChild->nodeValue, 3);
	EXPECT_EQ(node->leftChild->leftChild->parent, node->leftChild);
	EXPECT_EQ(node->rightChild->nodeValue, 20);
	EXPECT_EQ(node->rightChild->parent, node);
}

TEST(AVLTree, TestDoubleRightRotation) {
	Node * node = new Node(10);
	node->leftChild = new Node(9);
	node->leftChild->parent = node;
	node->rightChild = new Node(15);
	node->rightChild->parent = node;

	node->rightChild->rightChild = new Node(20);
	node->rightChild->rightChild->parent = node->rightChild;
	node->rightChild->rightChild->leftChild = new Node(19);
	node->rightChild->rightChild->leftChild->parent = node->rightChild->rightChild;

	AVLTree tree = AVLTree();
	tree.setRoot(node);
	tree.RLRotation(tree.getRoot()->rightChild);

	node = tree.getRoot();

	EXPECT_EQ(node->nodeValue, 10);
	EXPECT_EQ(node->rightChild->nodeValue, 19);
	EXPECT_EQ(node->rightChild->parent, node);
	EXPECT_EQ(node->rightChild->rightChild->nodeValue, 20);
	EXPECT_EQ(node->rightChild->rightChild->parent, node->rightChild);
	EXPECT_EQ(node->rightChild->leftChild->nodeValue, 15);
	EXPECT_EQ(node->rightChild->leftChild->parent, node->rightChild);
	EXPECT_EQ(node->leftChild->nodeValue, 9);
	EXPECT_EQ(node->leftChild->parent, node);
}

namespace {
	class AVLTest : public ::testing::Test {
	protected:

		AVLTree t1_;

		AVLTest() {
			t1_ = AVLTree();
		}
	};

	TEST_F(AVLTest, InsertTest) {
		t1_.Insert(5);
		t1_.Insert(6);
		t1_.Insert(4);

		Node * root = t1_.getRoot();

		EXPECT_EQ(root->nodeValue, 5);
		EXPECT_EQ(root->parent, nullptr);
		EXPECT_EQ(root->leftChild->nodeValue, 4);
		EXPECT_EQ(root->leftChild->parent, root);
		EXPECT_EQ(root->rightChild->nodeValue, 6);
		EXPECT_EQ(root->rightChild->parent, root);
	}

	TEST_F(AVLTest, SingleRotateLeftOnInsert) {
		t1_.Insert(5);
		t1_.Insert(6);
		t1_.Insert(7);

		Node * root = t1_.getRoot();

		EXPECT_EQ(root->nodeValue, 6);
		EXPECT_EQ(root->parent, nullptr);
		EXPECT_EQ(root->leftChild->nodeValue, 5);
		EXPECT_EQ(root->leftChild->parent, root);
		EXPECT_EQ(root->rightChild->nodeValue, 7);
		EXPECT_EQ(root->rightChild->parent, root);
	}

	TEST_F(AVLTest, SingleRotateRightOnInsert) {
		t1_.Insert(5);
		t1_.Insert(4);
		t1_.Insert(3);

		Node * root = t1_.getRoot();

		EXPECT_EQ(root->nodeValue, 4);
		EXPECT_EQ(root->parent, nullptr);
		EXPECT_EQ(root->leftChild->nodeValue, 3);
		EXPECT_EQ(root->leftChild->parent, root);
		EXPECT_EQ(root->rightChild->nodeValue, 5);
		EXPECT_EQ(root->rightChild->parent, root);
	}

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}