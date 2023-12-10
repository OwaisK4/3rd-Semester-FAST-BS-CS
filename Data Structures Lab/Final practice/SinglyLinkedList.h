#include <iostream>
using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node* next;
        Node(){
            data = 0;
            next = NULL;
        }
        Node(T d){
            data = d;
            next = NULL;
        }
};

template <typename T>
class SLL{
    public:
        Node<T> *front, *rear;
        SLL(){
            front = NULL;
            rear = NULL;
        }
        Node<T>* top(){
            return front;
        }
        void push(T data){
            Node<T>* newNode = new Node<T>(data);
            if (front == NULL){
                front = newNode;
            }
            else{
                newNode->next = front;
                front = newNode;
            }
        }
        T pop(){
            if (front == NULL){
                cout << "Stack is empty.\n";
                return -1;
            }
            else{
                Node<T> *temp = front;
                T x = front->data;
                front = front->next;
                delete temp;
                return x;
            }
        }
        void enqueue(T data){
            Node<T>* newNode = new Node<T>(data);
            if (front == NULL || rear == NULL){
                front = rear = newNode;
            }
            else{
                rear->next = newNode;
                rear = rear->next;
            }
        }
        T dequeue(){
            if (front == NULL || rear == NULL){
                cout << "Queue is already empty.\n";
                return -1;
            }
            else if(front == rear){
                T x = front->data;
                delete front;
                front = NULL;
                rear = NULL;
                return x;
            }
            else{
                Node<T>* temp = front;
                T x = front->data;
                front = front->next;
                delete temp;
                return x;
            }
        }
};