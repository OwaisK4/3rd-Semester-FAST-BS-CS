#include<iostream>
using namespace std;

class Node {
  public:
   int key;
  	int data;
  	Node * next;

  Node() {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
    next = NULL;
  }
};

class Queue {
  public:
  	Node *front;
  	Node *rear;
  	
    Queue(){
      front = NULL;
      rear = NULL;
    }
    
    bool isEmpty(){
    	if(front==NULL && rear==NULL){
    		return true;
		}
		else{
			return false;
		}
	}
	 
	bool checkIfNodeExist(Node *n){
	 	Node *temp = front;
	 	bool exist=false;
	 	while(temp!=NULL){
	 		if(temp->key==n->key){
                exist=true;
                break;
      	    }
      	    temp=temp->next;
		}
		return exist;
	}
	 
	void ADDMember(Node *n){
        if (isEmpty())
        {
            front = n;
            rear = n;
        }
        else if(checkIfNodeExist(n)){
            cout<<"Node already exist with this Key value."<<endl;
        }
        else{
            rear->next=n;
            rear=n;
        }
    }
	
	Node* RemoveMember() {
        Node *temp=NULL;
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return NULL;
        } 
        else {
            if(front==rear){
                temp=front;
                front = NULL;
                rear = NULL;  
                return temp;
            }
            else{
                temp=front;
                front = front->next;  
                return temp;
            } 
        }
    }
	 
	int count() {
        int count=0;
        Node *temp=front;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
	 
	void display() {
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
        }
        else{
            cout << "Queue: " << endl;
            Node *temp=front;
            while(temp!=NULL){
                cout<<"("<<temp->key<<","<<temp->data<<")"<<" --> ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }	
};
 
int main() {
  Queue q;
  int option,key, data;
 
  do {
    cout << "What operation do you want to perform?"
	 <<"Select Option number. Enter 0 to exit." << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. display()" << endl;
 	cin >> option;

	Node * node = new Node();
	 
    
    switch (option) {
        case 0:
        break;

        case 1:
            cout << "Enter KEY and VALUE of Node"<<endl;
            cin >> key;
            cin >> data;
            node->key = key;
            node->data = data;
            q.ADDMember(node);
        break;

        case 2:
        node = q.RemoveMember();
        cout<<"Dequeued Value is: ("<<node->key<<","<<node->data<<")";
        delete node;
        cout<<endl;
        
        break;

        case 3:
        q.display();
        cout << endl;
        break;

        default:
        cout << "\nWhat does it takes to be in your limits\n";
        break;
    }
  } while (option != 0);
 
  return 0;
}