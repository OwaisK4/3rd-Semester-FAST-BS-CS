#include <iostream>
#define SPACE 10
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node(){
			data = 0;
			left = NULL;
			right = NULL;
		}
		Node(int d){
			data = d;
			left = NULL;
			right = NULL;
		}
};

class AVLTree{
	public:
		Node* root;
		AVLTree(){
			root = NULL;
		}
		Node* insertRecursive(Node* r, Node* newNode){
//			Node* newNode = new Node(value);
			if (r == NULL){
				r = newNode;
				cout << "Inserted node successfully.\n";
				return r;
			}
			if (r->data == newNode->data){
				cout << "Node with given data already exists.\n";
				return r;
			}
			else if (r->data > newNode->data){
				r->left = insertRecursive(r->left, newNode);
			}
			else if (r->data < newNode->data){
				r->right = insertRecursive(r->right, newNode);
			}
		}
		Node* insertBalanced(Node* r, Node* newNode){
			if (r == NULL){
				r = newNode;
				cout << "Inserted node successfully.\n";
				return r;
			}
			if (r->data == newNode->data){
				cout << "Node with given data already exists.\n";
				return r;
			}
			else if (r->data > newNode->data){
				r->left = insertBalanced(r->left, newNode);
			}
			else if (r->data < newNode->data){
				r->right = insertBalanced(r->right, newNode);
			}
			
			int bf = getBalanceFactor(r);
			if (bf > 1 && newNode->data < r->left->data)
				return rightRotate(r);
			if (bf < -1 && newNode->data > r->right->data)
				return leftRotate(r);
			if (bf > 1 && newNode->data > r->left->data){
				r->left = leftRotate(r->left);
				return rightRotate(r);
			}
			if (bf < -1 && newNode->data < r->right->data){
				r->right = rightRotate(r->right);
				return leftRotate(r);
			}
			return r;
		}
		int height(Node* r){
			if (r == NULL){
				return -1;
			}
			int lheight = height(r->left);
			int rheight = height(r->right);
			if (lheight > rheight){
				return lheight + 1;
			}
			else{
				return rheight + 1;
			}
		}
		int getBalanceFactor(Node* r){
			if (r == NULL){
				return -1;
			}
			return height(r->left) - height(r->right);
		}
		void printBalanceFactor(Node* r){
			if (r == NULL){
				return;
			}
			cout << "Balance factor of Node: " << r->data << " is: " << getBalanceFactor(r) << endl;
			printBalanceFactor(r->left);
			printBalanceFactor(r->right);
		}
		Node* rightRotate(Node* r){
			Node* x = r->left;
			Node* y = x->right;
			
			x->right = r;
			r->left = y;
			
			return x;
		}
		Node* leftRotate(Node* r){
			Node* x = r->right;
			Node* y = x->left;
			
			x->left = r;
			r->right = y;
			
			return x;
		}
		void recursivePreorder(Node* r){
			if (r == NULL)
				return;
			cout << r->data << " ";
			recursivePreorder(r->left);
			recursivePreorder(r->right);
		}
		void print2D(Node* r, int space){
			if (r == NULL) // Base case  1
				return;
			space += SPACE; // Increase distance between levels   2
			print2D(r -> right, space); // Process right child first 3
			cout << endl;
			for (int i = SPACE; i < space; i++) // 5
				cout << " "; // 5.1
			cout << r -> data << "\n"; // 6
			print2D(r -> left, space); // Process left child  7
		}
};

int main(){
	AVLTree tree;
	int BST[5] = {15, 20, 10, 30, 40};
	tree.root = tree.insertRecursive(tree.root, new Node(5));
	for (int i=0; i<5; i++){
//		tree.root = tree.insertRecursive(tree.root, new Node(BST[i]));
		tree.root = tree.insertBalanced(tree.root, new Node(BST[i]));
	}
	cout << "\n";
	tree.recursivePreorder(tree.root);
	tree.print2D(tree.root, 5);
	cout << "\n";
	tree.printBalanceFactor(tree.root);
	tree.root = tree.insertBalanced(tree.root, new Node(1));
	tree.print2D(tree.root, 5);
	cout << "\n";
	tree.recursivePreorder(tree.root);
	return 0;
}
