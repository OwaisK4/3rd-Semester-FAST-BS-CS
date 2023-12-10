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

class Stack{
    public:
        Node* top;
        Stack(){
            top = NULL;
        }
        bool isEmpty(){
            return (top == NULL);
        }
        void push(int data){
            Node* newNode = new Node(data);
            if (top == NULL){
                top = newNode;
            }
            else{
                newNode->next = top;
                top = newNode;
            }
        }
        int pop(){
            if (top == NULL){
                cout << "Stack is empty.\n";
                return -1;
            }
            else{
                Node *temp = top;
                int x = top->data;
                top = top->next;
                delete temp;
                return x;
            }
        }
};

class Queue{
    public:
        Stack s1, s2;
        Queue(){}
        bool isEmpty(){
            if (s1.isEmpty())
                return true;
            return false;
        }
        void enqueue(int data){
            // Node* newNode = new Node(data);
            while (!s1.isEmpty()){
                s2.push(s1.pop());
            }
            s1.push(data);
            while (!s2.isEmpty()){
                s1.push(s2.pop());
            }
        }
        int dequeue(){
            return s1.pop();
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