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
        bool isEmpty(){
            return (front == NULL);
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

class Stack{
    public:
        Queue q1, q2;
        bool isEmpty(){
            if (q1.isEmpty())
                return true;
            return false;
        }
        void push(int data){
            while (!q1.isEmpty()){
                q2.enqueue(q1.dequeue());
            }
            q1.enqueue(data);
            while (!q2.isEmpty()){
                q1.enqueue(q2.dequeue());
            }
        }
        int pop(){
            return q1.dequeue();
        }
};

int main(){
    Stack stack;
    for (int i=0; i<10; i++){
        stack.push(i*2);
    }
    cout << "Stack values: ";
    for (int i=0; i<10; i++){
        cout << stack.pop() << " ";
    }
    return 0;
}