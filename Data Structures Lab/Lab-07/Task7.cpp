#include<iostream>
using namespace std;

class Stack{
    public:
        int top;
        char arr[10];
    
    Stack(string s){
        top=-1;
        for(int i=0; i<s.length(); i++){
            arr[i]=s[i];
            top++;
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

    void push(char val){
        if(IsFull()){
            cout << "\nStack Overflow\n";
        }
        else{
            top++;
            arr[top]=val;
        }
    }

    char pop(){
        if(IsEmpty()){
            cout << "\nStack Empty\n";
        }
        else{
            char val = arr[top];
            arr[top]='0';
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
};

class Queue{
    public:
        int rear, front;
        char arr[10];
    
    Queue(string s){
        rear=front=-1;
        for(int i=0; i<s.length(); i++){
            arr[i]=s[i];
            front=0;
            rear++;
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
        if(rear==9){
            return true;
        }
        else{
            return false;
        }
    }

    void push(char val){
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

    char pop(){
        char x;
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
        for(int i=0; i<10; i++){
            cout << arr[i] << " ";
        }
        cout << endl << endl;
    }
};

void Palindrome(Stack S, Queue Q, string s){
    int n = s.length(), count=0;

    char temp1[n], temp2[n];

    for(int i=0; i<n; i++){
        temp1[i] = S.pop();
        temp2[i] = Q.pop();
    }

    for(int i=0; i<n; i++){
        if(temp1[i]==temp2[i]){
            count++;
        }
    }
    
    if(count==n){
        cout << "\nPalindrome\n";
    }
    else{
        cout << "\nNot Palindrome\n";
    }
}

int main(){
    string s;
    cout << "Enter a string to check Palindrome: ";
    cin >> s;

    Stack S(s);
    Queue Q(s);
    Palindrome(S,Q,s);  

}