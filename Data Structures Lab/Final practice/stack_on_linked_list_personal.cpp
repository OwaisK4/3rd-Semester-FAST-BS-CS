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