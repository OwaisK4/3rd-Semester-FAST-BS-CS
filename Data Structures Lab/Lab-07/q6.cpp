#include <iostream>
#include <cstring>
using namespace std;

class CircularQueue{
	public:
		int rear, front, itemCount, array[10];
		CircularQueue(){
			rear = -1;
			front = -1;
			itemCount = 0;
			memset(array, 0, sizeof(int) * 10);
//			for(int i=0; i<10; i++){
//				array[i] = 0;
//			}
		}		
		bool isEmpty(){
			if(rear == -1 && front == -1){
				return true;	
			}	
			else{
				return false;
			}
		}
		bool isFull(){
			if((rear + 1) % 10 == front){
				return true;
			}
			else{
				return false;
			}
		}
		void enqueue(int value){
			if(isFull()){
				cout << "\nStack OverFlow\n" << endl;
			}
			else if(isEmpty()){
				rear = 0;
				front = 0;
				array[rear] = value;
			}
			else{
				rear = (rear + 1) % 10;
				array[rear] = value;
			}
			itemCount++;
		}
		int dequeue(){
			int x = 0;
			if(isEmpty()){
				cout << "\nStack UnderFlow\n" << endl;
				return x;
			}
			else if(rear == front){
				x = array[rear];
				rear = -1;
				front = -1;
				return x;
			}
			else{
				x = array[front];
				array[front] = 0;
				front = (front + 1) % 10;
				itemCount--;
				return x;
			}
		}
		void display(){
			for(int i = 0; i < 10; i++){
				cout << array[i] << " ";
			}
            cout << endl << endl;
		}
		
};

int main(){
	CircularQueue queue;
	for (int i=0; i<10; i++){
		queue.enqueue(i);
	}
	for (int i=0; i<10; i++){
		cout << queue.dequeue() << " ";
	}
	return 0;
}
