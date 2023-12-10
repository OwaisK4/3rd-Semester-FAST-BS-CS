#include <iostream>
#define SPACE 10
using namespace std;

class TreeNode{
	public:
		int value;
		TreeNode *left;
		TreeNode *right;
	public:
		TreeNode(){
			value = 0;
			left = NULL;
			right = NULL;
		}
		TreeNode(int v){
			value = v;
			left = NULL;
			right = NULL;
		}
};

class BST{
	public:
		TreeNode *root;
		BST(){
			root = NULL;
		}
		BST(TreeNode* newNode){
			root = newNode;
		}
		TreeNode* InsertRecursive(TreeNode* &r, TreeNode* newNode){
			if (r == NULL){
				r = newNode;
				cout << "Node successfully inserted.\n";
				return r;
			}
			else if (r->value > newNode->value)
				r->left = InsertRecursive(r->left, newNode);
			else if (r->value < newNode->value)
				r->right = InsertRecursive(r->right, newNode);
			else{
				cout << "No duplicates allowed in BST.\n";
				return r;
			}
			return r;
		}
		void print2D(TreeNode * r, int space) {
			if (r == NULL) // Base case  1
				return;
			space += SPACE; // Increase distance between levels   2
			print2D(r -> right, space); // Process right child first 3 
			cout << endl;
			for (int i = SPACE; i < space; i++)
				cout << " ";
			cout << r -> value << "\n"; // 6
			print2D(r -> left, space); // Process left child  7
		}
		void PrintPreorder(TreeNode* r){
			if (r == NULL)
				return;
			cout << r->value << " ";
			PrintPreorder(r->left);
			PrintPreorder(r->right);
		}
		void PrintInorder(TreeNode* r){
			if (r == NULL)
				return;
			PrintInorder(r->left);
			cout << r->value << " ";
			PrintInorder(r->right);
		}
		void PrintPostorder(TreeNode* r){
			if (r == NULL)
				return;
			PrintPostorder(r->left);
			PrintPostorder(r->right);
			cout << r->value << " ";
		}
		TreeNode* SearchRecursive(TreeNode* r, int val){
			if (r == NULL || r->value == val)
				return r;
			else if (val < r->value)
				return SearchRecursive(r->left, val);
			else
				return SearchRecursive(r->right, val);
		}
		int height(TreeNode* r){
			if (r == NULL)
				return -1;
			int lheight = height(r->left);
			int rheight = height(r->right);
			if (lheight > rheight)
				return 1 + lheight;
			else
				return 1 + rheight;
		}
		TreeNode* PrintGivenLevel(TreeNode* r, int level){
			if (r == NULL)
				return r;
			else if (level == 0)
				cout << r->value << " ";
			else{
				PrintGivenLevel(r->left, level - 1);
				PrintGivenLevel(r->right, level - 1);
			}
		}
		void PrintBFS(TreeNode* r){
			int h = height(r);
			for (int i=0; i<=h; i++){
				PrintGivenLevel(r, i);
				cout << "\n";
			}
		}
		int calc(TreeNode* r, int count){
			if (r->left == NULL && r->right == NULL)
				return count+1;
			else if (r->left != NULL && r->right != NULL)
				count++;
			count = calc(r->left, count);
			count = calc(r->right, count);
			return count;
		}
//		TreeNode* DeleteNode(TreeNode* r, int value){
//		}
};

int main(){
	BST obj;
//	TreeNode *node(5);
//	obj.root = obj.InsertRecursive(obj.root, new TreeNode(5));
//	obj.root = obj.InsertRecursive(obj.root, new TreeNode(6));
//	obj.root = obj.InsertRecursive(obj.root, new TreeNode(4));
//	obj.root = obj.InsertRecursive(obj.root, new TreeNode(3));
//	obj.root = obj.InsertRecursive(obj.root, new TreeNode(2));
	obj.InsertRecursive(obj.root, new TreeNode(5));
	obj.InsertRecursive(obj.root, new TreeNode(9));
	obj.InsertRecursive(obj.root, new TreeNode(3));
	obj.InsertRecursive(obj.root, new TreeNode(4));
	obj.InsertRecursive(obj.root, new TreeNode(2));
	obj.print2D(obj.root, 5);
	obj.PrintPreorder(obj.root);
	cout << "\n";
	obj.PrintInorder(obj.root);
	cout << "\n";
	obj.PrintPostorder(obj.root);
	cout << "\n";
	cout << "Height of tree is: " << obj.height(obj.root) << "\n";
	obj.PrintBFS(obj.root);
	cout << "\n";
	cout << "Count of subtrees = " << obj.calc(obj.root, -1);
	return 0;
}
