//C++ program to demonstrate working of capacity function
#include <iostream>
#include <vector> 
using namespace std; 
int main() 
{ 
   //Declaring vector ‘a’ of integer type 
   vector<int> a; 
   
   //Initializing vector ‘a’ with values from 1 to 5
    for (int i = 1; i <= 5; i++) 
        a.push_back(i); 
  
    //Printing size of the vector ‘a’
    cout << "Size : " << a.size(); 
   
    //Printing the Capacity of the vector ‘a’
    cout << "\nCapacity : " << a.capacity(); 
    
    //Printing the maximum size of the vector ‘a’
    cout << "\nMax_Size : " << a.max_size(); 
  
    // resizing  the vector ‘a’ to  size  4 
    a.resize(4); 
  
    // printing the vector ‘a’ size after resize() function
    cout << "\nSize : " << a.size(); 
  
    // checks if the vector is empty or not 
    if (a.empty() == false) 
        cout << "\nVector is not empty"; 
    else
        cout << "\nVector is empty"; 
  
  
    return 0; 
} 
