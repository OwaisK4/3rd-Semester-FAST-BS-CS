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

class Stack_LL{
	private:
		Node *top;
	public:
		Stack_LL(){
			top = NULL;
		}
		Stack_LL(Node *newNode){
			top = newNode;
		}
		void push(int data){
			Node *temp = new Node(data);
			if (top == NULL){
				top = temp;
			}
			else{
				temp->next = top;
				top = temp;
			}
		}
		int peek(){
			if (top == NULL){
				cout << "Already empty stack.\n";
				return -1;
			}
			else{
				return top->data;
			}
		}
		int pop(){
			if (top == NULL){
				cout << "Already empty stack.\n";
				return -1;
			}
			else{
				Node *temp = top;
				int value = temp->data;
				top = top->next;
				delete temp;
				return value;
			}
		}
};

int main(){
	Stack_LL stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	cout << stack.pop() << "\n";
	cout << stack.pop() << "\n";
	cout << stack.pop() << "\n";
	cout << stack.pop() << "\n";
	cout << stack.pop() << "\n";
	cout << stack.pop() << "\n";
	cout << stack.pop() << "\n";
	return 0;
}
