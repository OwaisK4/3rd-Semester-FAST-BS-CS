#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d = 0){
            data = d;
            next = NULL;
        }
};

class Queue{
    public:
        Node* front;
        Node* rear;
        Queue(){
            front = NULL;
            rear = NULL;
        }
        void enqueue(int data){
            Node* newNode = new Node(data);
            if (front == NULL || rear == NULL){
                front = rear = newNode;
            }
            else{
                rear->next = newNode;
                rear = rear->next;
            }
        }
        int dequeue(){
            if (front == NULL || rear == NULL){
                cout << "Queue is already empty.\n";
                return -1;
            }
            else if(front == rear){
                int x = front->data;
                delete front;
                front = NULL;
                rear = NULL;
                return x;
            }
            else{
                Node* temp = front;
                int x = front->data;
                front = front->next;
                delete temp;
                return x;
            }
        }
};

int main(){
    Queue queue;
    for (int i=0; i<10; i++){
        queue.enqueue(i*2);
    }
    for (int i=0; i<10; i++){
        cout << queue.dequeue() << " ";
    }
    return 0;
}