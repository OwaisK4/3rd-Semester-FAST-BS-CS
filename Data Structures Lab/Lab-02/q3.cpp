#include <iostream>
using namespace std;

//void swap(int &A, int &B){
//	int temp = A;
//	A = B;
//	B = temp;
//}

void sort(int array[], int start, int end){
	if (start >= end){
		return;
	}
	int max = -1;
	int index = 0;
	for (int i=0; i < end; i++){
		if (array[i] > max){
			max = array[i];
			index = i;
		}
	}
	array[index] = 0;
	sort(array, start+1, end);
	cout << max << " ";
}

int main(){
	int numbers[6] = {12, 11, 13, 5, 6, 7};
	cout << "Original array: ";
	for (int i=0; i<6; i++){
		cout << numbers[i] << " ";
	}
	cout << "\nSorted array: ";
	sort(numbers, 0, 6);
	return 0;
}

/*
void sort(int array[], int start, int end){
	if (start == end){
	}
	else if (array[start] > array[start+1]){
		int temp = array[start];
		array[start] = array[start+1];
		array[start+1] = temp;
		sort(array, start+1, end);
	}
}
*/
