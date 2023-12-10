
// C++ Code for Comb Sort 
#include <iostream>
using namespace std;
// function to update gap value
int updateGap(int gap)
{ 
// Shrink gap by the shrink factor 
  gap = (gap) / 1.3;
  if (gap < 1)
    return 1;
  else
    return gap;
}
// Function to sort arr[] using Comb Sort 
void combSort(int arr[], int n) 
{
  // initialize gap 
  int gap = n;
  // Initialize swapped as true to make sure that the loop runs 
  bool swapped = true;
  while (gap > 1 || swapped == true)
  {
    // Update gap value
    gap = updateGap(gap);
    swapped = false;
    // Compare all elements with current gap 
    for (int i = 0; i < (n - gap); i++)
    {
      int temp;
      if (arr[i] > arr[i + gap])
      {
        // Swap arr[i] and arr[i+gap] 
        temp = arr[i];
        arr[i] = arr[i + gap];
        arr[i + gap] = temp;
        swapped = true;
      }
    }
  }
}
// Driver function
int main() {
  int arr[10] = {7, 5, 1, 50, 3, -20, 25, -4, 30, 0};
  int n = 10;
  combSort(arr, n);
  cout << "Sorted array" << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}        
