#include <iostream>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

template <typename T>
void SelectionSort(T array[], int size){
	int step, min_index;
	for (step = 0; step < size-1; step++){
		min_index = step;
		for (int i = step; i < size; i++){
			if (array[i] < array[min_index])
				min_index = i;
		}
		swap(array[step], array[min_index]);
	}
}

template <typename T>
void printArray(T array[], int size){
	for (int i=0; i<size; i++){
		cout << array[i] << " ";
	}
	cout << "\n";
}

int main(){
	const int size = 10;
	int array[size] = {5,6,7,2,4,1,3,9,8,0};
	printArray(array, size);
	SelectionSort(array, size);
	printArray(array, size);
	return 0;
}
