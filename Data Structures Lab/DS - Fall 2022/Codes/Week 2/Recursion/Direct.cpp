#include <iostream>
using namespace std;
int n=0;
// declaring functions
void foo1(void);

// defining recursive functions
void foo1() 
{ 
  if (n <= 20) 
  { 
    cout<<n<<" ";  // prints n
    n++;           // increments n by 1
    foo1();       // calls foo2() 
  } 
  else
    return; 
} 


// Driver Program 
int main(void) 
{ 
  foo1(); 
  return 0; 
} 
