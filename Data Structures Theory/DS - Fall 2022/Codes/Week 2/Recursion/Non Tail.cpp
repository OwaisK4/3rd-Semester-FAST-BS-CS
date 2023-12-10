#include <iostream>
using namespace std;
// declaring functions
void foo1(int n);

// defining recursive functions
void foo1(int n) 
{ 
  if (n <= 20) 
  { 
    
     // increments n by 1
    foo1(++n);       // calls foo2()   its not  tail because there is something  to evaluate after the function call
    cout<<n<<" ";  // prints n
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
