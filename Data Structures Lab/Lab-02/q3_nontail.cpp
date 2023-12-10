#include <iostream>
using namespace std;

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
	int numbers[10] = {12, 11, 13, 5, 6, 7, 9, 1, 3, 2};
	cout << "Original array: ";
	for (int i=0; i<10; i++){
		cout << numbers[i] << " ";
	}
	cout << "\nSorted array: ";
	sort(numbers, 0, 10);
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
