#include <iostream>
using namespace std;

void swap(int &A, int &B){
	int temp = A;
	A = B;
	B = temp;
}

void sort(int array[], int start, int end){
	if (start >= end-1){
		return;
	}
	if (array[start] > array[start+1])
		swap(array[start], array[start+1]);
	sort(array, start+1, end);
	sort(array, start, end-1);
}

int main(){
	int numbers[10] = {12, 11, 13, 5, 6, 7, 9, 1, 3, 2};
	cout << "Original array: ";
	for (int i=0; i<10; i++){
		cout << numbers[i] << " ";
	}
	cout << "\nSorted array: ";
	sort(numbers, 0, 10);
	for (int i=0; i<10; i++){
		cout << numbers[i] << " ";
	}
	return 0;
}
