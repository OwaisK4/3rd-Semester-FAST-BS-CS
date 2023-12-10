#include<iostream>
#include<algorithm>
using namespace std;

class Stack{
    public:
        int t;
        char arr[100];
    
    Stack(){
        t=-1;
        for(int i=0; i<100; i++){
            arr[i]='0';
        }
    }

    bool empty(){
        if(t==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool IsFull(){
        if(t==99){
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
            t++;
            arr[t]=val;
        }
    }

    char pop(){
        if(empty()){
            cout << "\nStack Empty\n";
        }
        else{
            char val = arr[t];
            arr[t]='0';
            t--;
            return val;
        }
    }

    char top(){
        if(empty()){
            cout << "\nStack Empty\n";
        }
        else{
            return arr[t];
        }
    }

    bool IsOperator(char c){
        if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
            return true;
        }
        else{
            return false;
        }
    }

    int Precedence(char c){
        if(c=='^')
        return 3;
        else if(c=='*' || c=='/')
        return 2;
        else if(c=='+' || c=='-')
        return 1;
        else
        return -1;
    }

    string InfixToPrefix(Stack s, string Infix){
        string Prefix;
        reverse(Infix.begin(), Infix.end());

        for(int i=0; i<Infix.length(); i++){
            if(Infix[i]=='('){
                Infix[i] = ')';
            }
            else if(Infix[i]==')'){
                Infix[i] = '(';
            }
        }

        for(int i=0; i<Infix.length(); i++){
            if((Infix[i]>='a' && Infix[i]<='z') || (Infix[i]>='A' && Infix[i]<='Z')){
                Prefix+=Infix[i];
            }
            else if(Infix[i]=='('){
                s.push(Infix[i]);
            }
            else if(Infix[i]==')'){
                while((s.top()!='(') && (!s.empty())){
                    Prefix+=s.top();
                    s.pop();
                }
                if(s.top()=='('){
                    s.pop();
                }
            }
            else if(IsOperator(Infix[i])){
                if(s.empty()){
                    s.push(Infix[i]);
                }
                else{
                    if(Precedence(Infix[i])>Precedence(s.top())){
                        s.push(Infix[i]);
                    }
                    else if(Precedence(Infix[i])==Precedence(s.top()) && (Infix[i]=='^')){
                        while(Precedence(Infix[i])==Precedence(s.top()) && (Infix[i]=='^')){
                            Prefix+=s.top();
                            s.pop();
                        }
                        s.push(Infix[i]);
                    }
                    else if(Precedence(Infix[i])==Precedence(s.top())){
                        s.push(Infix[i]);
                    }
                    else{
                        while((!s.empty())&&(Precedence(Infix[i])<Precedence(s.top()))){
                            Prefix+=s.top();
                            s.pop();
                        }
                        s.push(Infix[i]);
                    }
                }
            }
        }
        while(!s.empty()){
            Prefix+=s.top();
            s.pop();
        }

        reverse(Prefix.begin(), Prefix.end());
        return Prefix; 
    }
};

int main(){
    Stack S;
    string Infix;
    cout << "Enter Infix: ";
    cin >> Infix;
    cout << endl << "Infix To Prefix: " << S.InfixToPrefix(S,Infix);
}
