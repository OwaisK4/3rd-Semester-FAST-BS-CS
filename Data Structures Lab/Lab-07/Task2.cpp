#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        string temp;
        char str[100];
        Node* next;
    
    Node(){data=0;
        next=NULL;
    }
    Node(int d){
        data=d;
        next=NULL;
    }
    Node(string s){
        temp = s;
        for(int i=0; i<s.length(); i++){
            str[i] = s[i];
        }
        next = NULL;
    }

};

class Stack{
    public:
        Node* top;

    Stack(){top=NULL;}

    bool IsEmpty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
    }    

    bool CheckNode(Node* n){
        Node* temp = top;
        bool exist = false;
        while(temp!=NULL){
            if(temp->data==n->data){
                exist = true;
                break;
            }
            temp = temp->next;
        }
        return exist;
    }

    void Push(Node* n){
        if(top==NULL){
            top=n;
        }
        else if(CheckNode(n)){
            cout << "\nAlreay Exists\n";
        }
        else{
            top=n;
            n->next=top;
        }
    }

    Node* Pop(){
        Node* temp = NULL;
        if(IsEmpty()){
            cout << "\nEmpty\n";
            return temp;
        }
        else{
            temp = top;
            top = top->next;
            cout << "Value: " << temp->data << endl << endl;
            return temp;
        }
    }

    void Display(){
        Node* temp = top;
        while(temp!=NULL){
            cout << temp->data << "  ";
            temp = temp->next;
        }
    }

    void DisplayString(){
        Node* temp;
        for(int i=0; i<temp->temp.length(); i++){
            cout << temp->str[i] << " ";
        }
        cout << endl << endl;
    }
    void DisplayStringReverse(){
        Node* temp;
        int n = temp->temp.length();
        for (int i = temp->temp.length() - 1; i >= 0; i--)
        cout << temp->str[i];
        cout << endl << endl;
    }
};

int main(){
    Stack S;
    Node* n;
    int choice;
    string s;
    A:
    cout << "\n\n1. Push\n2. Pop\n3. Display\n4. String\n\n   Enter Choice: ";
    cin >> choice;
    
    switch(choice){
        case 1:
            cout << "\nEnter Value you want to Push: ";
            int val;
            cin >> val;
            n = new Node(val);
            S.Push(n);
            goto A;
            break;
        case 2:
            cout << "\nPop value: " << S.Pop() << endl << endl;
            goto A;
            break;
        case 3:
            S.Display();
            goto A;
            break;
        case 4:
            cout << "Enter String: ";
            cin >> s;
            n = new Node(s);
            S.DisplayString();
            goto A;
            break;
        default: 
            cout << "\nWhat does it takes to be in your limits\n";
            goto A;
            break;
    };
}