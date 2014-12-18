//============================================================================
// Name        : TernaryTree.cpp
// Author      : Bhumi Sabarwal
//============================================================================

#include <iostream>
using namespace std;


// struct for TriNary tree node
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *middle;
  TreeNode *right;
  TreeNode(int value):
    val(value), left(NULL), middle(NULL), right(NULL) {}
};

// class for TriNary tree
class TriNaryTree {
  private:
    TreeNode *root;
    void insertNode(TreeNode *node, int value);
    TreeNode* deleteNode(TreeNode *node, int value);
    TreeNode* getSuccessor(TreeNode *node);
    void printTree(TreeNode *node);
  public:
    TriNaryTree():root(NULL) {}
    void insertNode(int value);
    void deleteNode(int value);
    void printTree();
};

void TriNaryTree::insertNode(int value) {
  if (root == NULL)
    root = new TreeNode(value);
  else
    insertNode(root, value);
}

void TriNaryTree::insertNode(TreeNode *node, int value) {
  if (node->val < value) {
    if (node->right)
      insertNode(node->right, value);
    else
      node->right = new TreeNode(value);
  }
  else if (node->val > value) {
    if (node->left)
      insertNode(node->left, value);
    else
      node->left = new TreeNode(value);
  }
  else {
    if (node->middle)
      insertNode(node->middle, value);
    else
      node->middle = new TreeNode(value);
  }
}

inline void TriNaryTree::deleteNode(int value) {
  root = deleteNode(root, value);
}

TreeNode* TriNaryTree::deleteNode(TreeNode *node, int value) {

  if (node == NULL)
    return node;

  if (node->val == value) {
    // three child nodes and all are NULL
    if (node->left == NULL && node->right == NULL && node->middle == NULL) {
      delete node;
      return NULL;
    }
    if (node->middle) {
      node->middle = deleteNode(node->middle, value);
    }
    else {
      if (node->left && node->right) {  // both left and right exist; replace by val of in-order successor of right subtree
        TreeNode *successor_node = getSuccessor(node->right);
        node->val = successor_node->val;
        node->right = deleteNode(node->right, successor_node->val);
      }
      else if (node->left) {    // right child is empty
        TreeNode *new_node = node->left;
        delete node;
        return new_node;
      }
      else {                   // left child is empty
        TreeNode *new_node = node->right;
        delete node;
        return new_node;
      }
    }
  }
  else if (node->val < value)
    node->right = deleteNode(node->right, value);
  else
    node->left = deleteNode(node->left, value);

  return node;
}

// Get the successor (in inorder traversal) in right child
TreeNode* TriNaryTree::getSuccessor(TreeNode *node) {
  if (node->left == NULL)
    return node;
  else
    return getSuccessor(node->left);
}

void TriNaryTree::printTree(){
	if(root==NULL)
		return;
	else
		printTree(root);
}

void TriNaryTree::printTree(TreeNode *node)
{
	if(node==NULL)
		return;
	else
	{
		printTree(node->left);
		cout<<"\n value is "<<node->val;
		printTree(node->middle);
		printTree(node->right);
	}
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	TriNaryTree T;
	T.insertNode(5);
    T.insertNode(4);
	T.insertNode(9);
	T.insertNode(5);
	T.insertNode(7);
	T.insertNode(2);
	T.insertNode(2);
	T.printTree();

	T.deleteNode(2);
	cout<<"\n after deleting 2 ";
	T.printTree();

	T.deleteNode(9);
	cout<< "\n after deleting 9";
	T.printTree();

	T.deleteNode(5);
	T.deleteNode(5);
	cout<<"\n after deleting 5 twice";
	T.printTree();


	return 0;
}
