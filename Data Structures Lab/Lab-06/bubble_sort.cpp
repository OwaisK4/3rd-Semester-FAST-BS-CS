#include <iostream>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

template <typename T>
void BubbleSort(T array[], int size){
	for (int i = 0; i < size-1; i++){
		bool swapped = false;
		for (int j = 0; j < size-i-1; j++){
			if (array[j] > array[j+1]){
				swap(array[j], array[j+1]);
				swapped = true;
			}
		}
		if (!swapped)
			return;
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
	BubbleSort(array, size);
	printArray(array, size);
	return 0;
}
