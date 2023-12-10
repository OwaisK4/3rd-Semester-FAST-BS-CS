#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node* parent;
};

node* minValue(node* node);

node* inOrderSuccessor(node* root, node* n)
{
	if (n->right != NULL)
		return minValue(n->right);

	node* p = n->parent;
	while (p != NULL && n == p->right) {
		n = p;
		p = p->parent;
	}
	return p;
}

node* minValue(node* n)
{
	node* current = n;

	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

node* newNode(int data)
{
	node* n = new node();
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;

	return n;
}

node* insert(node* n, int data)
{
	if (n == NULL)
		return (newNode(data));
	else {
		node* temp;

		if (data <= n->data) {
			temp = insert(n->left, data);
			n->left = temp;
			temp->parent = n;
		}
		else {
			temp = insert(n->right, data);
			n->right = temp;
			temp->parent = n;
		}

		return n;
	}
}

int main()
{
	node *root = NULL, *temp, *succ, *min;

	root = insert(root, 8);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 4);
	root = insert(root, 7);
	root = insert(root, 10);
	root = insert(root, 14);
	root = insert(root, 13);
	
	// 10 inorder successor
	temp = root->right;
	succ = inOrderSuccessor(root, temp);
	if (succ != NULL)
		cout << "\n Inorder Successor of " << temp->data<< " is "<< succ->data;
	else
		cout <<"\n Inorder Successor doesn't exit";
	
	temp = root->left->right;
	succ = inOrderSuccessor(root, temp);
	if (succ != NULL)
		cout << "\n Inorder Successor of " << temp->data<< " is "<< succ->data;
	else
		cout <<"\n Inorder Successor doesn't exit";
	
	temp = root->right->right->left;
	if (succ != NULL)
		cout << "\n Inorder Successor of " << temp->data<< " is "<< succ->data;
	else
		cout <<"\n Inorder Successor doesn't exit";
	return 0;
}