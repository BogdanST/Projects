#include "stdafx.h"
#include <iostream>

//Method 1 following the Week 6 -PPT Pseudocode
/*Author = Dr. Diana Hintea (partial code provided),
Student Bogdan A. Stanciu(deleteNode/Constructor[Parent]/bin_tree_find /count_children)
Availability: http://moodle.coventry.ac.uk */


class BinTreeNode {
public:
	BinTreeNode(int value, BinTreeNode* parent) {
		this->value = value;
		this->parent = parent; //parent was added to the constructor to keep track of it
		this->left = NULL;
		this->right = NULL;
	}
	int value;
	BinTreeNode* parent;
	BinTreeNode* left;
	BinTreeNode* right;
};

BinTreeNode* tree_insert(BinTreeNode* tree, int item,BinTreeNode* parent) {
	if (tree == NULL)
		tree = new BinTreeNode(item, parent);
	else
		if (item < tree->value)
			if (tree->left == NULL)
				tree->left = new BinTreeNode(item,parent);
			else
				tree_insert(tree->left, item,parent);
		else
			if (tree->right == NULL)
				tree->right = new BinTreeNode(item,parent);
			else
				tree_insert(tree->right, item,parent);
	return tree;
}

void postorder(BinTreeNode* tree) {
	if (tree->left != NULL)
		postorder(tree->left);
	if (tree->right != NULL)
		postorder(tree->right);
	std::cout << tree->value << std::endl;

}

void in_order(BinTreeNode* tree) {
	if (tree->left != NULL)
		in_order(tree->left);
	std::cout << tree->value << std::endl;
	if (tree->right != NULL)
		in_order(tree->right);
}

int count_children(BinTreeNode* tree) {
	int count = 0;
	if (tree->left != NULL)
		count = count + 1;
	if (tree->right != NULL)
		count = count + 1;
	return count;
}

BinTreeNode* bin_tree_find(BinTreeNode* tree, int target) {
	if (tree->value == target)
		return tree;
	else if (tree->value < target)
		return bin_tree_find(tree->right, target);
	else
		return bin_tree_find(tree->left, target);
	return 0;
}

BinTreeNode* deleteNode(BinTreeNode* tree, int target) {
	BinTreeNode* Node = bin_tree_find(tree, target);  // find the corresponding node to "target)

	if (count_children(Node) == 0) // case 0: no children
	{							  
		if (Node->parent->value > target)
			Node->parent->left = NULL;
		else if (Node->parent->value < target)
			Node->parent->right = NULL;
		else
			delete Node;
		
	}
   if(count_children(Node) == 1)  //case 1: no child
		if (Node->left != NULL) {
			Node->value = Node->left->value;
			Node->left = NULL;
			}
		if(Node->right !=NULL)
		{
			Node->value = Node->right->value;
			Node->right = NULL;
		}
	else
	{
		Node->value = Node->right->value;
		Node->right = NULL;
	}
	return Node;
}


int main(int argc, char *argv[])
{
	BinTreeNode* t = tree_insert(0, 6,0);
	tree_insert(t, 10,t);
	tree_insert(t, 5 ,t);
	tree_insert(t, 2,t);
	tree_insert(t, 3,t);
	tree_insert(t, 4,t);
	tree_insert(t, 11,t);
	deleteNode(t,4);
	in_order(t);

	return 0;
}