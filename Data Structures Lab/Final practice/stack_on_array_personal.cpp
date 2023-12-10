#include <iostream>
using namespace std;

class Stack{
    public:
        int top;
        int size;
        int *array;
        Stack(int s = 5){
            size = s;
            array = new int[size];
            top = -1;
        }
        bool isEmpty(){
            return (top == -1);
        }
        bool isFull(){
            return (top >= size-1);
        }
        void push(int data){
            if (isFull()){
                cout << "Stack is already full.\n";
            }
            else{
                array[++top] = data;
            }
        }
        int pop(){
            if (isEmpty()){
                cout << "Stack is already empty.\n";
                return -1;
            }
            else{
                int temp = array[top];
                array[top] = 0;
                top--;
                return temp;
            }
        }
};

int main(){
    Stack stack(10);
    for (int i=0; i<10; i++){
        stack.push(i*2);
    }
    cout << "Stack values: ";
    for (int i=0; i<10; i++){
        cout << stack.pop() << " ";
    }
}