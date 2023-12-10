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
//				cout << "Inserted node successfully.\n";
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
//				cout << "Inserted node successfully.\n";
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
		Node* search(Node* r, int value, int level=0){
			if (r == NULL){
				cout << "Node with given value not found.\n";
				return r;
			}
			if (r->data == value){
				cout << "Node found at level " << level << "\n";
				return r;
			}
			else if (r->data > value)
				return search(r->left, value, level+1);
			else if (r->data < value)
				return search(r->right, value, level+1);
		}
		Node* minValueNode(Node* r){
			Node* current = r;
			while (current->left != NULL){
				current = current->left;
			}
			return current;
		}
		Node* deleteNode(Node* r, int value){
			if (r == NULL){
				cout << "No node with given value exists.\n";
				return NULL;
			}

			if (r->data > value){
				r->left = deleteNode(r->left, value);
			}
			else if (r->data < value){
				r->right = deleteNode(r->right, value);
			}
			else{
				if (r->left == NULL){
					Node* temp = r->right;
					delete r;
					cout << "Deleted node with value " << value << "\n";
					return temp;
				}
				else if (r->right == NULL){
					Node* temp = r->left;
					delete r;
					cout << "Deleted node with value " << value << "\n";
					return temp;
				}
				else{
					Node* temp = minValueNode(r->right);
					r->data = temp->data;
					r->right = deleteNode(r->right, temp->data);
				}
			}
			int bf = getBalanceFactor(r);
			if (bf > 1){
				if (getBalanceFactor(r->left) >= 0)
					return rightRotate(r);
				else{
					r->left = leftRotate(r->left);
					return rightRotate(r);
				}
			}
			if (bf < -1){
				if (getBalanceFactor(r->right) <= 0)
					return leftRotate(r);
				else{
					r->right = rightRotate(r->right);
					return leftRotate(r);
				}
			}
			return r;
		}
		void recursivePreorder(Node* r){
			if (r == NULL)
				return;
			cout << r->data << " ";
			recursivePreorder(r->left);
			recursivePreorder(r->right);
		}
		void recursiveInorder(Node* r){
			if (r == NULL)
				return;
			recursiveInorder(r->left);
			cout << r->data << " ";
			recursiveInorder(r->right);
		}
		void recursivePostorder(Node* r){
			if (r == NULL)
				return;
			recursivePostorder(r->left);
			recursivePostorder(r->right);
			cout << r->data << " ";
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
	int values[11] = { 55, 66, 77, 11, 33, 22, 35, 25, 44, 88, 99 };
	for (int i=0; i<11; i++){
		tree.root = tree.insertBalanced(tree.root, new Node(values[i]));
	}
	cout << "Preorder: ";
	tree.recursivePreorder(tree.root);
	cout << "\n2D Print:\n";
	tree.print2D(tree.root, 5);
	cout << "\n";
//	tree.printBalanceFactor(tree.root);
//	cout << "\n";
	tree.deleteNode(tree.root, 35);
	tree.deleteNode(tree.root, 99);
	cout << "\n2D Print:\n";
	tree.print2D(tree.root, 5);
	cout << "\nPreorder: ";
	tree.recursivePreorder(tree.root);
	cout << "\nInorder: ";
	tree.recursiveInorder(tree.root);
	cout << "\nPostorder: ";
	tree.recursivePostorder(tree.root);
	cout << "\n";
	return 0;
}
