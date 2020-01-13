#pragma once
template <class T>
class BinaryTree
{
public:

	struct Node
	{
		T data;
		struct Node* left;
		struct Node* right;
		Node(T val = T(), Node* left = nullptr, Node* right = nullptr) : data(val),left(nullptr),right(nullptr) {};
	};

	BinaryTree(T val = nullptr) : root(new Node(val)) {};
	~BinaryTree();
	void insert(T val);
	bool search(T val);

	void insertRec(T val); //  adapter for insertRec(T val,Node* leaf)
	bool searchRec(T val); //  adapter for searchRec(T val,Node* leaf)

	void destroy(Node* leaf);

private:
	void insertRec(T val,Node* leaf); // insert recursion implementation 
	bool searchRec(T val,Node* leaf); // search recursion implementation 
	Node* root;
};

template <class T>
void BinaryTree<T>::insert(T val) {
	if (root == nullptr){
		root = new Node(val);
		return;
	}
	
	Node* temp = root;

	 while (temp != nullptr) {
		 if (val < temp->data && temp->left == nullptr)
		 {
			 temp->left = new Node(val);
			 break;
		 }
		 else if(val < temp->data)
			 temp = temp->left;
		  if ((val > temp->data && temp->right == nullptr))
		  {
			  temp->right = new Node(val);
			  break;
		  }
		  else if(val > temp->data)
			 temp = temp->right;
	 }

}

template <class T>
bool BinaryTree<T>::search(T val) {

	Node* temp = root;

	while (temp != nullptr && temp->data != val ) {
		if (val < temp->data)
			temp = temp->left;
		else 
			temp = temp->right;
	};

	if (temp != nullptr)
		return true;
	else
		return false;
}

template <class T>
void BinaryTree<T>::insertRec(T val) {
	return insertRec(val, root);
}

template <class T>
void BinaryTree<T>::insertRec(T val, Node* leaf) {
	if (val < leaf->data)
	{
		if (leaf->left != nullptr)
			insertRec(val, leaf->left);
		else
			leaf->left = new Node(val);
	}
	else if (val >= leaf->data)
	{
		if (leaf->right != nullptr)
			insertRec(val, leaf->right);
		else
			leaf->right = new Node(val);
	}
}

template <class T>
bool BinaryTree<T>::searchRec(T val) {
	return searchRec(val, root);
}

template <class T>
bool BinaryTree<T>::searchRec(T val, Node* leaf) {
	if (leaf != nullptr)
	{
		if (val == leaf->data)
			return true;
		if (val < leaf->data)
			return searchRec(val, leaf->left);
		else
			return searchRec(val, leaf->right);
	}
	else return false;
}

template <class T>
void BinaryTree<T>::destroy(Node* leaf) {
	
	if (leaf != nullptr)
	{
		if (leaf->left != nullptr)
			destroy(leaf->left);
		if (leaf->right != nullptr)
			destroy(leaf->right);
		
	delete leaf;
		return;
	}
	else return;
		
}

template <class T>
BinaryTree<T>::~BinaryTree() {
	destroy(root);
}