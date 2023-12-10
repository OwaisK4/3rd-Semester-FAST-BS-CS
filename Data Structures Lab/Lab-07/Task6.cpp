#include<iostream>
using namespace std;

class circularQueue
{
	public:
		int rear, front, itemCount, array[5];
		
		circularQueue(){
			rear = -1;
			front = -1;
			itemCount = 0;
			
			for(int i=0; i<5; i++){
				array[i] = 0;
			}
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
			if((rear + 1) % 5 == front){
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
				rear = (rear + 1) % 5;
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
				front = (front + 1) % 5;
				itemCount--;
				return x;
			}
		}
		
		int count(){
			return itemCount;
		}
		
		void display(){
			for(int i = 0; i < 5; i++){
				cout << array[i] << " ";
			}
            cout << endl << endl;
		}
		
};

int main()
{
	int choice, value;
	circularQueue Q;
	
	do{
	    cout<<"\n\n0. Exit\n1. Enqueue \n2. Dequeue \n3. Count \n4. Display \n\n   Enter Your Choice: ";
		cin>>choice;
        switch (choice) {
            case 0:
                break;  
            case 1:
                cout << "\nEnter an item to Enqueue in the Queue" << endl;
                cin >> value;
                Q.enqueue(value);
                break;
            case 2:
                cout << "\nDequeued Value : " << Q.dequeue() << endl;
                break;
            case 3:
                cout << "\nCount of items in Queue : " << Q.count() << endl;
                break;
            case 4:
                Q.display();
                break;
            default:
                cout << "\nWhat does it takes to be in your limits\n";
            }
        } while (choice != 0);
}