#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(){
			data = 0;
			next = NULL;
		}
		Node(int d){
			data = d;
			next = NULL;
		}
};

class Queue_on_LL{
	public:
		Node* front;
		Node* rear;
		Queue_on_LL(){
			front = NULL;
			rear = NULL;
		}
		bool isEmpty(){
			if (front == NULL && rear == NULL)
				return true;
			return false;
		}
		void enqueue(int d){
			Node* temp = new Node(d);
			if (isEmpty()){
				front = temp;
				rear = temp;
			}
			else{
				rear->next = temp;
				rear = temp;
			}
		}
		Node* dequeue(){
			Node* temp = NULL;
			if (isEmpty()){
				cout << "Empty queue.\n";
				return temp;
			}
			else if (front == rear){
				temp = front;
				front = NULL;
				rear == NULL;
				return temp;
			}
			else{
				temp = front;
				front = front->next;
				return temp;
			}
		}
};

class Queue_on_array{
	public:
		const int size;
		int* array;
		int front, rear;
		Queue_on_array(): size(10){
			array = new int[size];
			front = -1;
			rear = -1;
		}
		Queue_on_array(int size): size(size){
			array = new int[size];
			front = -1;
			rear = -1;
		}
		bool isEmpty(){
			if (front == -1 && rear == -1)
				return true;
			return false;
		}
		bool isFull(){
			if (rear >= size-1)
				return true;
			return false;
		}
		void enqueue(int d){
			if (isFull()){
				cout << "Queue is Full.\n";
				return;
			}
			else if (isEmpty()){
				front = 0;
				rear = 0;
				array[rear] = d;
			}
			else{
				rear++;
				array[rear] = d;
			}
		}
		int dequeue(){
			if (isEmpty()){
				cout << "Queue is Empty.\n";
				return -1;
			}
			else if (front == rear){
				int d = array[front];
				front = -1;
				rear = -1;				
				return d;
			}
			else{				
				int d = array[front];
				array[front] = 0;
				front++;
				return d;
			}
		}
};

int main(){
	Queue_on_LL queueLL;
	for (int i=0; i<10; i++){
		queueLL.enqueue(i);
	}
	for (int i=0; i<10; i++){
		cout << queueLL.dequeue()->data << " ";
	}
	cout << "\n\n";
	
	Queue_on_array queueA;
	for (int i=0; i<10; i++){
		queueA.enqueue(i);
	}
	for (int i=0; i<10; i++){
		cout << queueA.dequeue() << " ";
	}
	return 0;
}
