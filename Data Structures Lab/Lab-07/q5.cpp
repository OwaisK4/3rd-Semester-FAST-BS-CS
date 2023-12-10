#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(){
    		data = 0;
    		next = NULL;
		}
  		Node(int d){
			data = d;
    		next = NULL;
    	}
};

class Queue{
	public:
	Node *front;
	Node *rear;
  	
	Queue(){
		front = NULL;
		rear = NULL;
	}
    
	bool isEmpty(){
		if(front == NULL && rear == NULL){
			return true;
		}
		else{
			return false;
		}
	}
	 
	bool checkIfNodeExist(Node* n){
	 	Node *temp = front;
	 	bool exist = false;
	 	while (temp != NULL){
	 		if(temp->data == n->data){
                exist = true;
                break;
      	    }
      	    temp = temp->next;
		}
		return exist;
	}
	 
	void ADDMember(Node* n){
        if (isEmpty()){
            front = n;
            rear = n;
        }
        else if(checkIfNodeExist(n)){
            cout << "Node already exist with this Key value.\n";
        }
        else{
            rear->next = n;
            rear = n;
        }
    }
	
	Node* RemoveMember() {
        Node *temp = NULL;
        if (isEmpty()){
            cout << "Queue is Empty" << endl;
            return NULL;
        } 
        else{
            if (front == rear){
                temp = front;
                front = NULL;
                rear = NULL;  
                return temp;
            }
            else{
                temp = front;
                front = front->next;  
                return temp;
            } 
        }
    }
	 
	void display() {
        if (isEmpty()){
            cout << "Queue is Empty" << endl;
        }
        else{
            cout << "Queue: " << endl;
            Node *temp = front;
            while(temp != NULL){
                cout << temp->data << " --> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main(){
	Queue queue;
	for (int i=0; i<10; i++){
		queue.ADDMember(new Node(i));
	}
	Node* temp;
	for (int i=0; i<10; i++){
		temp = queue.RemoveMember();
		cout << temp->data << " -> ";
	}
	return 0;
}
