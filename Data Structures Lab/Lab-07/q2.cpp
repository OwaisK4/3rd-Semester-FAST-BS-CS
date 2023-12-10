#include<iostream>
using namespace std;

template <typename T>
class Node{
	public:
		T data;
		int key;
		Node *next;
		Node(){
			key = 0;
    		data = 0;
    		next = NULL;
		}
  		Node(int k, T d){
    		key = k;
			data = d;
    		next = NULL;
    	}
};

template <typename T>
class Stack{
	public:
		Node<T> *top;
		Stack(){
    		top = NULL;
  		}
		bool isEmpty() {
			if (top == NULL){
    			return true;
			}
			else{
				return false;
    		}
  		}
  
		bool checkIfNodeExist(Node<T>* n){
			Node<T>* temp = top;
    		bool exist = false;
    		while (temp != NULL){
    			if (temp -> key == n -> key){
        			exist = true;
        			break;
    			}
      			temp = temp -> next;
    		}
    		return exist;
  		}
		Node<T>* nodeExists(int k){
    		Node<T>* temp = NULL;
    		Node<T>* ptr = top;
    		while (ptr != NULL){
	      		if (ptr -> key == k){
    	    		temp = ptr;
      			}
				ptr = ptr -> next;
			}
		    return temp;
		}
  		void push(int k, int d){
  			Node<T>* n = new Node<T>(k,d);
    		if (top == NULL){
      			top = n;
    		}
			else if (checkIfNodeExist(n)){
    			cout << "Node already exist with this Key value." << "Enter different Key value" << endl;
			}
			else{
				n->next = top;
				top = n;
		    }
  		}

		Node<T>* pop() {
    		Node<T>* temp = NULL;
    		if (isEmpty()){
      			cout << "Stack underflow" << endl;
      			return temp;
    		}
			else {
				temp = top;
				top = top -> next;
				return temp;
			}
		}
		Node<T>* peek() {
    		if (isEmpty()){
				cout << "Stack underflow" << endl;
      			return NULL;
    		}
			else{
    			return top;
    		}
		}
		int count(){
			int count = 0;
    		Node<T> *temp = top;
    		while (temp != NULL){
    			count++;
      			temp = temp->next;
		    }
    		return count;
  		}
		void display(){
			cout << "Original:\n";
    		Node<T> *temp = top;
  			for(temp = top; temp != NULL; temp = temp -> next){
      			cout << "(" << temp -> key << "," << temp -> data << ")" << ", ";
    		}
    		cout << "\n\nReverse:\n";
    		Stack newstack;
    		for (temp = top; temp != NULL; temp = temp->next){
    			newstack.push(temp->key, temp->data);
			}
			for(temp = newstack.top; temp != NULL; temp = temp -> next){
      			cout << "(" << temp -> key << "," << temp -> data << ")" << ", ";
    		}
    		cout << "\n\n\n";
      	}
      	
};

int main() {
	Stack<int> stack;
	for (int i=0; i<10; i++){
		stack.push(i, i*2);
	}	
	stack.display();
	
	string s = "Oblivionaire";
	Stack<char> char_stack;
	for (int i=0; i<s.size(); i++){
		char_stack.push(i, s[i]);
	}
	char_stack.display();
	
	return 0;
}
