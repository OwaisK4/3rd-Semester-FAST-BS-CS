#include<iostream>
using namespace std;

class Queue{
    public:
        int rear, front ,arr[5];
    Queue(){
        rear=front=-1;
        for(int i=0; i<5; i++){
            arr[i]=0;
        }
    }
    bool IsEmpty(){
        if(rear==-1 && front==-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool QueueCapacity(){
        if(rear==4){
            return true;
        }
        else{
            return false;
        }
    }
    void ADDMember(int val){
        if(QueueCapacity()){
            cout << "\nQueue OverFlow\n";
        }
        else if(IsEmpty()){
            rear=front=0;
            arr[rear]=val;
        }
        else{
            rear++;
            arr[rear]=val;
        }
    }
    int RemoveMember(){
        int x=0;
        if(IsEmpty()){
            cout << "\nQueue Empty\n";
        }
        else if(rear==front){
            x = arr[rear];
            rear=front=-1;
            return x;
        }
        else{
            x = arr[front];
            front++;
            return x;
        }
    }
    int count(){
        return (rear-front+1);
    }
    void Display(){
        for(int i=0; i<5; i++){
            cout << arr[i] << " ";
        }
        cout << endl << endl;
    }
};

int main(){
    Queue S;
    int choice;
    A:
    cout << "\n\n1. Push\n2. Pop\n3. Display\n\n   Enter Choice: ";
    cin >> choice;
    
    switch(choice){
        case 1:
            cout << "\nEnter Value you want to Push: ";
            int val;
            cin >> val;
            S.ADDMember(val);
            goto A;
            break;
        case 2:
            cout << "\nPop value: " << S.RemoveMember() << endl << endl;
            goto A;
            break;
        case 3:
            S.Display();
            goto A;
            break;
        default: 
            cout << "\nWhat does it takes to be in your limits\n";
            goto A;
            break;
    };
}
