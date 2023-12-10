#include <iostream>
using namespace std;
// declaring functions
void foo1(int n);

// defining recursive functions
void foo1(int n) 
{ 
  if (n <= 20) 
  { 
     cout<<n<<" ";  // prints n
     // increments n by 1
    foo1(++n);       // calls foo2()   its also tail recursion because there is nothing  to evaluate after the function call
   
  } 
  else
    return; 
} 


// Driver Program 
int main(void) 
{ 
  foo1(1); 
  return 0; 
} 
