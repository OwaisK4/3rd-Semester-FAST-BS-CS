#include <iostream>

static int count = 0;

template <typename T>
void printArray(T array, int size){
	for (int i=0; i<size; i++){
		std::cout << array[i] << " ";
	}
	std::cout << "\n";
}

template <typename T>
void swap(T& A, T& B){
	T temp = A;
	A = B;
	B = temp;
}

int *sort(int *array, int start, int end){
	if (start >= end-1)
		return array;
	if (array[start] > array[start+1]){
		swap(array[start], array[start+1]);
	}
	printArray(array, 10);
	count++;
	return sort(sort(array, start+1, end), start+1, end);
}

int main(){
	int *array = new int[10]{9, 0, 8, 1, 7, 2, 6, 3, 5, 4};
	int *sorted;
//	printArray(array, 10);
	sorted = sort(array, 0, 10);
//	printArray(sorted, 10);
	std::cout << "\n\nCount = " << count;
	delete [] array;
	return 0;
}
