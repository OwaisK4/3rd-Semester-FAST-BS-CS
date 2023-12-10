#include<iostream> 
#include<stack> 
using namespace std; 
main() {
// syntax stack<datatype>name; 
stack <int>st; 
st.push(10); 
st.push(20); 
st.push(30); 
st.push(40); 
cout<<"Number of item in stak is:"<<st.size() <<endl; 
cout<<"Top element of stack is:"<<st.top()«<endl; 
while(!st.empty(){
cout<<st.top() <<endl; 
st.pop();
}
}
