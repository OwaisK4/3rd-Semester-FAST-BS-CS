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
		int front, rear;
		int capacity = 0;
		int *array;
		Queue(int c = 5){
			capacity = c;
			array = new int[capacity];
			front = rear = -1;
		}
		bool IsEmpty(){
			if(rear == -1 && front == -1){
				return true;
			}
			else{
				return false;
			}
		}
		bool QueueCapacity(){
			if(rear == capacity){
				return true;
			}
			else{
				return false;
			}
		}
		void ADDMember(int val){
			if (QueueCapacity()){
				cout << "\nQueue OverFlow\n";
			}
			else if (IsEmpty()){
				rear = front = 0;
				array[rear] = val;
			}
			else{
				rear++;
				array[rear] = val;
			}
    	}
		int RemoveMember(){
			int x = 0;
			if(IsEmpty()){
				cout << "\nQueue Empty\n";
			}
			else if(rear == front){
				x = array[rear];
				rear = front = -1;
				return x;
			}
			else{
				x = array[front];
				front++;
				return x;
			}
    	}
};

int main(){
	Queue queue(10);
	for (int i=0; i<10; i++){
		queue.ADDMember(i);
	}
	for (int i=0; i<10; i++){
		cout << queue.RemoveMember() << " ";
	}
	return 0;
}
