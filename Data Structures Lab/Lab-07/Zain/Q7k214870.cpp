#include<iostream>
#include<string>
using namespace std;

class Stack {
  private:
    int top;
  char arr[10];

  public:
    Stack() 
	{
      top = -1;
      for(int i=0;i<10;i++)
      {
      	arr[i]=' ';
	  }
            
      }

  bool isEmpty() 
  {
    if (top == -1)
      return true;
    else
      return false;
  }
  bool isFull() 
  {
    if (top == 9)
      return true;
    else
      return false;
  }

  void push(char val) {
    if (isFull()) {
      cout << "stack overflow" << endl;
    } else 
	{
      top++; 
      arr[top] = val;
    }
  }

  char pop() 
  {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    } else {
      char popValue = arr[top];
      arr[top] = 0;
      top--;
      return popValue;
    }
  }

  int count() {
    return (top + 1);
  }
};

class Queue 
{
  private:
    int front;
  int rear;
  char arr[10];

  public:
    Queue() 
	{
      front = -1;
      rear = -1;
      for(int i=0;i<10;i++)
      {
       arr[i]=' ';     	
	  }      
          }
  bool isEmpty() {
    if (front == -1 && rear == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (rear == 10)
      return true;
    else
      return false;
  }
  void enqueue(char val) 
  {
    if (isFull()) {
      cout << "Queue full" << endl;
      return;
    } else if (isEmpty()) 
	{
      rear = 0;
      front = 0;
      arr[rear] = val;
    } else
	 {
      rear++;
      arr[rear] = val;
    }

  }

  char dequeue() {
    char x ;
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return x;
    } else if (rear == front) {
      x = arr[rear];
      arr[rear]=0;
      rear = -1;
      front = -1;
      return x;
    }
	 else 
	{
      cout << "front value: " << front << endl;
      x = arr[front];
      arr[front] = 0;
      front++;
      return x;
    }
  }

  int count() {
    return (rear - front + 1);
  }

  
};

int main()
{
Stack s1;
int flag=0;
  char value;
  Queue q1;
cout<<"\nWrite a string in stack\nLIMIT OF WORD: 10 CHARACTERS\n";
      cout << "Enter an item to push in the stack\nEnter 0 to exit\n" << endl;
      
	  do
      {
	  cin >> value;
      s1.push(value);
  }
  while(value!='0');
cout<<"\nWrite a string in Queue\nLIMIT OF WORD: 10 CHARACTERS\n";
      cout << "\nEnter an item to Enqueue in the Queue\nEnter 0 to exit\n" << endl;

      do
	  {
      cin >> value;
      q1.enqueue(value);
}
while(value!='0');

while(!s1.isEmpty()&&!q1.isEmpty())
{
	if(s1.pop()!=q1.dequeue())
	{
		flag=1;
		cout<<"Not Palindrome";
		break;
	}
}
if(flag!=1)
{
	cout<<"Palindrome";
}
}