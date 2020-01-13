#include "BinaryTree.h"

int main () {

	//BinaryTree<int> r(5);
	BinaryTree<int>* root = new BinaryTree<int>(142);
	root->insert(80);
	root->insert(200);
	root->insert(300);
	root->insert(150);
	root->insert(10);
	root->insert(100);
	root->search(150);
	root->search(15);
	root->insertRec(8);
	root->searchRec(10);
	root->searchRec(1);
	root->~BinaryTree();
	return 0;
}