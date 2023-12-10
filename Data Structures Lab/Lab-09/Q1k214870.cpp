#include<iostream>
#define SPACE 10

using namespace std;

class TreeNode {
  public:
    int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode() {
    value = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
};

class BST 
{
  public:
    TreeNode * root;
  BST() {
    root = NULL;
  }

  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }
void insertNode(TreeNode*r,TreeNode*newnode)
{
	if(root==NULL)
	{
		root=newnode;
		cout<<"\nRoot\n";
	}
	else 
	{
		TreeNode*temp=root;
		if(newnode->value<root->value)
		{
			while(temp->left!=NULL)
			{		
			temp=temp->left;		
}
cout<<"\nLeft\n";
			temp->left=newnode;
		}
	else if(newnode->value>root->value)
		{
			while(temp->right!=NULL)
			{		
			temp=temp->right;		
}
cout<<"\nRight\n";
			temp->right=newnode;
		}
	
	}
}
  
  void printInorder(TreeNode * r) 
  {
    if (r == NULL)
      return;
    printInorder(r -> left);
    cout << r -> value << " ";
    printInorder(r -> right);
  }
  void checkbst(TreeNode*r)
  {
  	TreeNode*temp=root;
  	while(temp->left!=NULL)
  	{
  		if(temp->left->value>temp->value)
  		{
  			cout<<endl<<temp->value<<" "<<temp->left->value<<endl;
  		
  			cout<<"\nRejected\n";
		  }
		  else {
		  	cout<<endl<<temp->value<<" "<<temp->left->value<<endl;
  		
		  	cout<<"\nAccepted\n";
		  }
		  temp=temp->left;
	  }
	  temp=root;
	  while(temp->right!=NULL)
  	{
  	if(temp->right->value<temp->value)
  		{
  			cout<<endl<<temp->value<<" "<<temp->right->value<<endl;
  		
  			cout<<"\nRejected\n";
		  }
		  else {
		  	cout<<endl<<temp->value<<" "<<temp->right->value<<endl;
  		
		  	cout<<"\nAccepted\n";
		  }
		  temp=temp->right;
	  }
  
  }
};

int main()
 {
  BST obj;
  int option, val;

  do {
    cout << "\nWhat operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "4. Print/Traversal BST values" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
    case 1:
      	cout <<"INSERT"<<endl;
	      cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
	      cin >> val;
	      new_node->value = val;
	       obj.insertNode(obj.root,new_node);
	      cout<<endl;
	break;
    case 4:
    	obj.checkbst(obj.root);
obj.printInorder(obj.root);
      break;
    
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}