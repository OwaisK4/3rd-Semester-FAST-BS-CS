#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include "SinglyLinkedList.h"
using namespace std;

bool isOperand(char a){
    if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z'){
        return true;
    }
    return false;
}

string PostfixToInfix(string postfix){
    stack<string> s;
    for (char i : postfix){
        if (isOperand(i)){
            string op = string(1, i);
            s.push(op);
        }
        else{
            string op = string(1, i);
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push(op2 + op + op1);
        }
    }
    return s.top();
}

SLL<char> PostfixToInfix(SLL<char> list){
    SLL<char> s;
    for (Node<char>* current = list.front; current != NULL; current = current->next){
        if (isOperand(current->data)){
    }
         else{

        }
    }  
    // return s;
}

int main(){
    string postfix = "ABC+-";
    string infix = PostfixToInfix(postfix);
    cout << postfix << "\n" << infix << "\n";
    return 0;
}