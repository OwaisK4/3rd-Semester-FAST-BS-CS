#include <iostream>
#include <stack>
#define SPACE 10
using namespace std;

class Node{
	private:
		int key;
		string name;
	public:
		Node* leftChild;
		Node* rightChild;
		Node(){
			this->key = 0;
			this->name = "";
			leftChild = NULL;
			rightChild = NULL;
		}
		Node(int key, string name){
			this->key = key;
			this->name = name;
			leftChild = NULL;
			rightChild = NULL;
		}
		string toString(){
			cout << name << " has the key " << key << endl;
//			return name + " has the key " + string(key);
		}
		int getKey(){
			return key;
		}
		void setKey(int key){
			this->key = key;
		}
};

class BinaryRoot{
	private:
		Node* root;
	public:
		BinaryRoot(){
			root = NULL;
		}
		Node* getRoot(){
			return root;
		}
		void addNode(int key, string name){
			Node* newNode = new Node(key, name);
			if (root == NULL){
				cout << "Inserted at root.\n";
				root = newNode;
			}
			else{
				Node* parent = root;
				while (true){
					if (newNode->getKey() == parent->getKey()){
						cout << "Given key already exists.\n";
						return;
					}
					else if ((newNode->getKey() < parent->getKey()) && (parent->leftChild == NULL)){
						parent->leftChild = newNode;
						cout << "Inserted new node at the left.\n";
						break;
					}
					else if (newNode->getKey() < parent->getKey()){
						parent = parent->leftChild;
					}
					else if ((newNode->getKey() > parent->getKey()) && (parent->rightChild == NULL)){
						parent->rightChild = newNode;
						cout << "Inserted new node at the right.\n";
						break;
					}
					else if (newNode->getKey() > parent->getKey()){
						parent = parent->rightChild;
					}
				}
			}
		}
		void recursivePreorder(Node* r){
			if (r == NULL)
				return;
			cout << r->getKey() << " ";
			recursivePreorder(r->leftChild);
			recursivePreorder(r->rightChild);
		}
		void recursiveInorder(Node* r){
			if (r == NULL)
				return;
			recursiveInorder(r->leftChild);
			cout << r->getKey() << " ";
			recursiveInorder(r->rightChild);
		}
		void iterativePreorder(){
			if (root == NULL)
				return;
			stack<Node *> s;
			s.push(root);
			while (!s.empty()){
				Node* current = s.top();
				s.pop();
				cout << current->getKey() << " ";
				if (current->rightChild != NULL){
					s.push(current->rightChild);
				}
				if (current->leftChild != NULL){
					s.push(current->leftChild);
				}	
			}
		}
		Node* minValueNode(Node* node) {
			Node* current = node;
			while (current->leftChild != NULL) {
				current = current->leftChild;
			}
			return current;
  }
		Node* deleteNode(Node* r, int v){
			if (r == NULL){
				return NULL;
			}
			else if (v < r->getKey()){
				r->leftChild = deleteNode(r->leftChild, v);
			}
			else if (v > r->getKey()){
				r->rightChild = deleteNode(r->rightChild, v);
			}
			else{
				if (r->leftChild == NULL){
					Node* temp = r->rightChild;
					delete r;
					return temp;
				}
				else if (r->rightChild == NULL){
					Node* temp = r->leftChild;
					delete r;
					return temp;
				}
				else{
					Node* temp = minValueNode(r->rightChild);
					r->setKey(temp->getKey());
					r->rightChild = deleteNode(r->rightChild, temp->getKey());
				}
			}
			return r;
		}
		Node* deleteRange(Node* r, int range[2]){
			if (r == NULL){
				return NULL;
			}
			if (r->getKey() < range[0]){
				root = deleteNode(root, r->getKey());
				deleteRange(root, range);
			}
			else if	(r->getKey() > range[1]){
				root = deleteNode(root, r->getKey());
				deleteRange(root, range);
			}
			deleteRange(r->leftChild, range);
			deleteRange(r->rightChild, range);
		}
		void print2D(Node *r, int space) {
			if (r == NULL) // Base case  1
				return;
			space += SPACE; // Increase distance between levels   2
			print2D(r->rightChild, space); // Process right child first 3 
			cout << endl;
			for (int i = SPACE; i < space; i++) // 5 
				cout << " "; // 5.1  
			cout << r->getKey() << "\n"; // 6
			print2D(r->leftChild, space); // Process left child  7
		}
};

int main(){
	const int size = 7;
	BinaryRoot TreeX, TreeY;
	int X[size] = {15, 10, 20, 8, 12, 18, 25};
	int range[2] = {9, 12};
	for (int i=0; i<size; i++){
		TreeX.addNode(X[i], "NULL");
	}
	TreeX.print2D(TreeX.getRoot(), 5);
	TreeX.recursiveInorder(TreeX.getRoot());
	cout << "\n";
	TreeX.deleteRange(TreeX.getRoot(), range);
//	TreeX.print2D(TreeX.getRoot(), 5);
	TreeX.recursiveInorder(TreeX.getRoot());
	cout << "\n";
	return 0;
}
