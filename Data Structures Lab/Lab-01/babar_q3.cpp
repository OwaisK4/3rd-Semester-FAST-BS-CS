#include <iostream>
using namespace std;

void swap(int &A, int &B){
	int temp = A;
	A = B;
	B = temp;
}

void sort(int array[], int start, int end){
	if (start >= end){
		return;
	}
	for (int i=start; i<end-1; i++){
		if (array[i] > array[i+1])
			swap(array[i], array[i+1]);
	}
	sort(array, start, end-1);
}

int main(){
	int numbers[6] = {12, 11, 13, 5, 6, 7};
	cout << "Original array: ";
	for (int i=0; i<6; i++){
		cout << numbers[i] << " ";
	}
	sort(numbers, 0, 6);
	cout << "\nSorted array: ";
	for (int i=0; i<6; i++){
		cout << numbers[i] << " ";
	}
	return 0;
}
