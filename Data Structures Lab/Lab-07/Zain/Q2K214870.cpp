#include<iostream>
using namespace std;

class Node {
  public:
    int key;
  int data;
  string letters;
  Node * next;
  Node() 
  {
    key = 0;
    data = 0;
    letters= " ";
    next = NULL;
  }
  Node(int k, int d,string l) 
  {
    key = k;
    data = d;
    letters=l;
    next = NULL;
    }
};

class Stack 
{
  public:
    Node * top;
  Stack() {
    top = NULL;
  }

  bool isEmpty() {
    if (top == NULL) {
      return true;
    } else {
      return false;
    }
  }
  
  bool checkIfNodeExist(Node * n) {
    Node * temp = top;
    bool exist = false;
    while (temp != NULL) 
	{
      if (temp -> key == n -> key) {
        exist = true;
        break;
      }
      temp = temp -> next;
    }
    return exist;
  }
Node * nodeExists(int k) {
    Node * temp = NULL;
    Node * ptr = top;

    while (ptr != NULL) {
      if (ptr -> key == k) {
        temp = ptr;
      }
      ptr = ptr -> next;
    }

    return temp;
  }

  
  void push(Node * n) {
    if (top == NULL) {
      top = n;
      cout << "Node  PUSHED successfully" << endl;
    } else if (checkIfNodeExist(n)) {
      cout << "Node already exist with this Key value." <<
        "Enter different Key value" << endl;
    } else {
      Node * temp = top;
      top = n;
      n -> next = temp;
      cout << "Node  PUSHED successfully" << endl;
    }

  }

  Node * pop() {
    Node * temp = NULL;
    if (isEmpty()) 
	{
      cout << "stack underflow" << endl;
      return temp;
    } else {
      temp = top;
      top = top -> next;
      return temp;
    }
  }
  Node * peek() {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return NULL;
    } else {
      return top;
    }
  }
  int count() {
    int count = 0;
    Node * temp = top;
    while (temp != NULL) {
      count++;
      temp = temp -> next;
    }
    return count;
  }
  void display() 
  {
    Node*temp=top;
  for(int i=0;i<10;i++)
  	{
      cout << "(" << temp -> key << "," << temp -> data << ")" << " -> " <<endl;
      temp = temp -> next;
    }
    cout << endl<<"\nReverse\n"<<endl;
  for(int i=10;i>0;i--)
  {
  	
	  Node*ptr=nodeExists(i);
  	cout << "(" << ptr -> key << "," << ptr -> data << ")" << " -> " <<endl;
	}  
      }
    void displaychar()
    {
    	string s="Oblivionaire";
    	 	for(int i=0;i<12;i++)
  	{
	  
    	Node * n = new Node();
    	 
      n -> key = i+1;
      n -> letters = s[i];
      push(n);
	}
    Node*temp=top;
  for(int i=0;i<12;i++)
  	{
      cout << "(" << temp -> key << "," << temp -> letters << ")" << " -> " <<endl;
      temp = temp -> next;
    }
  
	}
};

int main() {
  Stack s1;
  int option, key, data;

  do {
    cout << "What operation do you want to perform?"<<endl;
	   cout<<"Enter 0 to exit & see Oblivionaire." << endl;
    cout << "1. Push()" << endl;
    cout << "2. Pop()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. peek()" << endl;
    cout << "5. count()" << endl;
    cout << "6. display()" << endl;
    cout << "7. Clear Screen" << endl << endl;
    cin >> option;

    Node * new_node = new Node(); 

    switch (option) {
    case 0:
      break;
    case 1:
    
	  cout << "Enter KEY and VALUE of NODE to push in the stack" <<    endl;
      for(int i=0;i<10;i++)
      {
	  cin >> key;
      cin >> data;
      new_node -> key = key;
      new_node -> data = data;
      s1.push(new_node);
  }
      break;
    case 2:
      cout << "Pop Function Called - Poped Value: " << endl;
      new_node = s1.pop();
      cout << "TOP of Stack is: (" << new_node -> key << "," << new_node -> data << ")";
      delete new_node;
      cout << endl;

      break;
    case 3:
      if (s1.isEmpty())
        cout << "Stack is Empty" << endl;
      else
        cout << "Stack is not Empty" << endl;
      break;
    case 4:
      if (s1.isEmpty()) {
        cout << "Stack is Empty" << endl;
      } else {
        cout << "PEEK Function Called : " << endl;
        new_node = s1.peek();
        cout << "TOP of Stack is: (" << new_node -> key << "," << new_node -> data << ")" <<
          endl;
      }
      break;
    case 5:
      cout << "Count Function Called: " << endl;
      cout << "No of nodes in the Stack: " << s1.count() << endl;
      break;

    case 6:
      cout << "Display Function Called - " << endl;
      s1.display();
      cout << endl;
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);
s1.displaychar();
  return 0;
}
