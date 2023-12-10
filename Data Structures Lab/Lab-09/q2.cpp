#include <iostream>
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
};

class BinaryRoot{
	private:
		Node* root;
	public:
		BinaryRoot(){
			root = NULL;
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
};

int main(){
	const int size = 7;
	BinaryRoot Tree;
	int BST[size] = {15, 10, 20, 8, 12, 16, 25};
	for (int i=0; i<size; i++){
		Tree.addNode(BST[i], "NULL");
	}
	return 0;
}
