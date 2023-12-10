#include <iostream>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

template <typename T>
void InsertionSort(T array[], int size){
	for (int i=0; i<size-1; i++){
		int j = i + 1;
		int key = array[j];
		while (j >= 0 && array[j-1] > key){
			array[j] = array[j-1];
			j = j - 1;
		}
		array[j] = key;
	}
}

template <typename T>
void InsertionSort2(T array[], int size){
	for (int i=1; i<size; i++){
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key){
			array[j+1] = array[j];
			j = j - 1;
		}
		array[j+1] = key;
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
	InsertionSort2(array, size);
	printArray(array, size);
	return 0;
}
