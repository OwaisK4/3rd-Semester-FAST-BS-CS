#include <iostream>
using namespace std;

class Queue{
    public:
        int size;
        int *array;
        int front, rear;
        Queue(int s = 5){
            size = s;
            array = new int[size];
            front = -1;
            rear = -1;
        }
        bool isFull(){
            if (rear >= size - 1)
                return true;
            return false;
        }
        bool isEmpty(){
            if (front == -1 || rear == -1)
                return true;
            return false;
        }
        void enqueue(int data){
            if (isFull()){
                cout << "Queue is already full.\n";
            }
            else if (isEmpty()){
                front = 0;
                rear = 0;
                array[rear] = data;
            }
            else{
                rear++;
                array[rear] = data;
            }
        }
        int dequeue(){
            if (isEmpty()){
                cout << "Queue is already empty.\n";
            }
            else if (front == rear){
                int temp = array[front];
                array[front] = 0;
                front = -1;
                rear = -1;
                return temp;
            }
            else{
                int temp = array[front];
                array[front] = 0;
                front++;
                return temp;
            }
        }
        void display(){
            cout << "Queue: ";
            for (int i=0; i<size; i++){
                cout << array[i] << " ";
            }
            cout << "\n";
        }
};

int main(){
    Queue queue(10);
    for (int i=0; i<=10; i++){
        queue.enqueue(i*2);
    }
    queue.display();
    for (int i=0; i<=10; i++){
        queue.dequeue();
    }
    return 0;
}