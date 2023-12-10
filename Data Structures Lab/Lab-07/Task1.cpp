#include<iostream>
using namespace std;

class Stack{
    public:
        int top, arr[10];
    
    Stack(){
        top=-1;
        for(int i=0; i<10; i++){
            arr[i]=0;
        }
    }

    bool IsEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool IsFull(){
        if(top==9){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int val){
        if(IsFull()){
            cout << "\nStack Overflow\n";
        }
        else{
            top++;
            arr[top]=val;
        }
    }

    int pop(){
        if(IsEmpty()){
            cout << "\nStack Empty\n";
        }
        else{
            int val = arr[top];
            arr[top]=0;
            top--;
            return val;
        }
    }

    void Display(){
        cout << "\nStack:\n";
        for(int i=9; i>=0; i--){
            cout << arr[i] << " ";
        }
        cout << endl << endl;
    }

    void DisplayWithPop(){
        cout << "\nStack:\n";
        for(int i=0; i<10; i++){
            cout << pop() << " ";
        }
        cout << endl << endl;
    }
};

int main(){
    Stack S;
    int choice;
    A:
    cout << "\n\n1. Push\n2. Pop\n3. Display\n4. Display With Pop\n\n   Enter Choice: ";
    cin >> choice;
    
    switch(choice){
        case 1:
            cout << "\nEnter Value you want to Push: ";
            int val;
            cin >> val;
            S.push(val);
            goto A;
            break;
        case 2:
            cout << "\nPop value: " << S.pop() << endl << endl;
            goto A;
            break;
        case 3:
            S.Display();
            goto A;
            break;
        case 4:
            S.DisplayWithPop();
            goto A;
            break;
        default: 
            cout << "\nWhat does it takes to be in your limits\n";
            goto A;
            break;
    };
}