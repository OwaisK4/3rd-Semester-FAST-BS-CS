#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
   //Declaring vector ‘a’ of integer type 
   vector<int> a; 
    
    //pushing values fn vector ‘a’ from 10 to 100
    for (int i = 1; i <= 10; i++) 
        a.push_back(i * 10); 
  
   //Using reference operator to print vector ‘a’ third element
    cout << "\nReference operator [g] : a[2] = " << a[2]; 
   
   //printing element at index 4 of the vector ‘a’
    cout << "\nat : a.at(4) = " << a.at(4); 
   
   //printing the front element of vector ‘a’
    cout << "\nfront() : a.front() = " << a.front(); 
  
   //printing the back element of vector ‘a’
    cout << "\nback() : a.back() = " << a.back(); 
  
    // pointer to the first element 
    int* pos = a.data(); 
    
   //printing the first element of vector using pointer ‘pos’
    cout << "\nThe first element is " << *pos; 
    return 0; 
} 
