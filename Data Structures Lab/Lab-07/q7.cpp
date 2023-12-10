#include <iostream>
#include <cstring>
using namespace std;
const int SIZE = 10;

template <typename T>
class Stack{
	private:
		int top;
	public:
		T array[SIZE];
		Stack(){
			top = -1;
		}
		bool isEmpty(){
			return top < 0;
		}
		bool push(T value){
			if (top >= (SIZE - 1)){
				cout << "Stack overflow\n";
				return false;
			}
			else{
				array[++top] = value;
				return true;
			}
		}
		T pop(){
			if (isEmpty()){
				cout << "Stack underflow\n";
				return -1;
			}
			else{
				T x = array[top];
				top--;
				return x;
			}
		}
		T peek(){
			if (isEmpty()){
				cout << "Empty stack\n";
				return -1;
			}
			else{
				return array[top];
			}
		}
		int getTop(){
			return top;
		}
};

template <typename T>
class CircularQueue{
	public:
		int rear, front, itemCount;
		T array[10];
		CircularQueue(){
			rear = -1;
			front = -1;
			itemCount = 0;
			memset(array, 0, sizeof(T) * 10);
		}
		bool isEmpty(){
			if(rear == -1 && front == -1){
				return true;	
			}	
			else{
				return false;
			}
		}
		bool isFull(){
			if((rear + 1) % 10 == front){
				return true;
			}
			else{
				return false;
			}
		}
		void enqueue(T value){
			if(isFull()){
				cout << "\nStack OverFlow\n" << endl;
			}
			else if(isEmpty()){
				rear = 0;
				front = 0;
				array[rear] = value;
			}
			else{
				rear = (rear + 1) % 10;
				array[rear] = value;
			}
			itemCount++;
		}
		int dequeue(){
			T x = 0;
			if(isEmpty()){
				cout << "\nStack UnderFlow\n" << endl;
				return x;
			}
			else if(rear == front){
				x = array[rear];
				rear = -1;
				front = -1;
				return x;
			}
			else{
				x = array[front];
				array[front] = 0;
				front = (front + 1) % 10;
				itemCount--;
				return x;
			}
		}
		void display(){
			for(int i = 0; i < 10; i++){
				cout << array[i] << " ";
			}
            cout << endl << endl;
		}
		
};

template <typename T>
bool isPalindrome(Stack<T> stack, CircularQueue<T> queue){
	while (!stack.isEmpty() || !queue.isEmpty()){
		if (stack.pop() != queue.dequeue()){
			return false;
		}
	}
	if (stack.isEmpty() && queue.isEmpty()){
		return true;
	}
}

int main(){
	Stack<char> stack;
	CircularQueue<char> queue;
	string s;
	cout << "Enter string: ";
	getline(cin, s);
	for (auto it = s.begin(); it != s.end(); it++){
		stack.push(*it);
		queue.enqueue(*it);
	}
	if (isPalindrome(stack, queue)){
		cout << "\nTrue. Given string " << s << " is a palindrome.";
	}
	else{
		cout << "\nFalse. Given string " << s << " is not a palindrome.";
	}
	return 0;
}
