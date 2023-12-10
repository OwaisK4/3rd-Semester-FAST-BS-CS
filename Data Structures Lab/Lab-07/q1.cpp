#include <iostream>
using namespace std;
const int SIZE = 5;

class Stack{
	private:
		int top;
	public:
		int array[SIZE];
		Stack(){
			top = -1;
		}
		bool push(int value);
		int pop();
		int peek();
		bool isEmpty();
		int getTop(){
			return top;
		}
};

bool Stack::push(int value){
	if (top >= (SIZE-1)){
		cout << "Stack overflow\n";
		return false;
	}
	else{
		array[++top] = value;
		return true;
	}
}
int Stack::pop(){
	if (isEmpty()){
		cout << "Stack underflow\n";
		return -1;
	}
	else{
		int x = array[top];
		top--;
		return x;
	}
}
int Stack::peek(){
	if (isEmpty()){
		cout << "Empty stack\n";
		return -1;
	}
	else{
		return array[top];
	}
}
bool Stack::isEmpty(){
	return top < 0;
}

int main(){
	Stack stack;
	stack.push(5);
	stack.push(1);
	stack.push(3);
	stack.push(6);
	stack.push(7);
	stack.push(8);
	stack.push(54);
	cout << "Top of stack: " << stack.peek() << endl;
	return 0;
}
