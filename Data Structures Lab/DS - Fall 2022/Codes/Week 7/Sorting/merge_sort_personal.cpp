#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

template<typename T>
void printArray(T array, int start, int end, ostream& fout){
//	for (int i=0; i<gap; i++)
//		fout << ' ';
	for (int i=start; i<=end; i++){
		fout << array[i] << " ";
	}
}

void merge(int arr[], int l, int m, int r) {
  int i = l;
  int j = m + 1;
  int k = l;

  /* create temp array */
  int temp[10];

  while (i <= m && j <= r) {
    if (arr[i] <= arr[j]) {
      temp[k] = arr[i];
      i++;
      k++;
    } else {
      temp[k] = arr[j];
      j++;
      k++;
    }

  }

  /* Copy the remaining elements of first half, if there are any */
  while (i <= m) {
    temp[k] = arr[i];
    i++;
    k++;

  }

  /* Copy the remaining elements of second half, if there are any */
  while (j <= r) {
    temp[k] = arr[j];
    j++;
    k++;
  }

  /* Copy the temp array to original array */
  for (int p = l; p <= r; p++) {
    arr[p] = temp[p];
  }
}

/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
fstream fstack("merge_sort_stack.txt", ios::out | ios::trunc);
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // find midpoint
    int m = (l + r) / 2;

    // recurcive mergesort first and second halves
    fstack << "\n\n" << setfill(' ') << right << setw(0) << "(" << "l=" << l << ", " << "m=" << m << ", " << "r=" << r << ")";
	fstack << "\nLeft array: ";
    printArray(arr, l, m, fstack);
    fstack << "\nRight array: ";
    printArray(arr, m+1, r, fstack);
    mergeSort(arr, l, m);
    
    fstack << "\n\n" << setfill(' ') << right << setw(8) << "(" << "l=" << l << ", " << "m=" << m << ", " << "r=" << r << ")";
    fstack << "\n";
    for (int i=0; i<8; i++) { fstack << ' '; }
	fstack << "Left array: ";
    printArray(arr, l, m, fstack);
    fstack << "\n";
    for (int i=0; i<8; i++) { fstack << ' '; }
    fstack << "Right array: ";
    printArray(arr, m+1, r, fstack);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
  else{
	fstack << "\n\n" << setfill(' ') << right << setw(0) << "(" << "l=" << l << ", " << "r=" << r << ")";
	fstack << " X";
  }
}

//fstack << "\n" << setfill(' ') << right << setw(8) << "(" << l << ", " << m << ", " << r << ")";

int main() {
  const int size = 11;
  int myarray[size] = {5,4,6,3,9,1,2,8,15,0,7};
//  int myarray[size] = {5,4,9,6,3,7,0,8,2,7};
//  int myarray[size] = {2, 3, 1, 4, 0, 7};

  fstack << "\nStarting array: ";
  printArray(myarray, 0, size-1, fstack);
  cout << "\nBefore Sorting" << endl;
  for (int i = 0; i < size; i++) {
    cout << myarray[i] << " ";
  }
  cout << endl;
  mergeSort(myarray, 0, (size - 1)); // mergesort(arr,left,right) called
  
  fstack << "\n\nFinal array: ";
  printArray(myarray, 0, size-1, fstack);
  cout << "After Sorting" << endl;
  for (int i = 0; i < size; i++) {
    cout << myarray[i] << " ";
  }

  return 0;
}
