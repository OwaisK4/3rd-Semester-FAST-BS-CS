//C++ code to visualize the Modifiers function in vectors
#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 
  
int main() 
{ 
    // Declaring Vector ‘a’ of integer type
    vector<int> a; 
  
    // filling vector ‘a’ with 7 in repetition of 4 times
    a.assign(4, 7); 
    
    //Printing the vector ‘a’ contents
    cout << "The vector contains: "; 
    for (int i = 0; i < a.size(); i++) 
        cout << a[i] << " "; 
  
    // inserting 10 to the last position of vector ‘a’
    a.push_back(10); 
    int n = a.size(); 
    cout << "\nThe last element is: " << a[n - 1]; 
  
    // removing the last element from vector ‘a’
    a.pop_back(); 
  
    // printing the vector ‘a’ contents
    cout << "\nThe vector contains: "; 
    for (int i = 0; i < a.size(); i++) 
        cout << a[i] << " "; 
  
    // inserting 3 at the beginning of vector ‘a’
    a.insert(a.begin(), 3); 
   
   //Printing the first element of vector ‘a’
    cout << "\nThe first element is: " << a[0]; 
  
    // removing the first element 
    a.erase(a.begin()); 
    
   //Printing the new first element of vector ‘a’
    cout << "\nThe first element is: " << a[0]; 
  
   
    // erasing the vector 
    a.clear(); 
   
    //printing the vector ‘a’ after erasing it
    cout << "\nVector size after erase(): " << a.size(); 
  
    // Creating two vectors ‘a1’ and ‘a2’ of integer type
    vector<int> a1, a2; 
   

    //Pushing values in vector ‘a1’ and ‘a2’
    a1.push_back(3); 
    a1.push_back(4); 
    a2.push_back(5); 
    a2.push_back(6); 
  
   //printing vector ‘a1’
    cout << "\n\nVector 1 is: "; 
    for (int i = 0; i < a1.size(); i++) 
        cout << a1[i] << " "; 
  
    //printing vector ‘a2’
    cout << "\nVector 2 is: "; 
    for (int i = 0; i < a2.size(); i++) 
        cout << a2[i] << " "; 
  
    // Swaping vectors ‘a1’ and ‘a2’ 
    a1.swap(a2); 
  
   //Printing vector ‘a1’ after swapping with ‘a2’
    cout << "\nAfter Swap \nVector 1 is: "; 
    for (int i = 0; i < a1.size(); i++) 
        cout << a1[i] << " "; 
  
    //printing vector ‘a2’ after swapping with ‘a1’
    cout << "\nVector 2 is: "; 
    for (int i = 0; i < a2.size(); i++) 
        cout << a2[i] << " "; 
    return 0;
} 
