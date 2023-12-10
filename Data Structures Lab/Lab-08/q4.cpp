#include <iostream>
using namespace std;

bool isHeap(int array[], int size){
	for (int i=0; i<(size-1)/2; i++){
		if ((2*i)+1 < size){
			int left = array[(2*i)+1];
			if (array[i] > left)
				return false;
		}
		if ((2*i)+2 < size){
			int right = array[(2*i)+2];
			if (array[i] > right)
				return false;
		}
			
	}
	return true;
}

void checkHeap(int array[], int size){
	if (isHeap(array, size))
		cout << "Given array is a heap.\n";
	else
		cout << "Given array is not a heap.\n";
}

int main(){
	const int size = 10;
	int array_heap[size] = {5, 10, 8, 12, 11, 14, 13, 22, 43};
	int array_not_heap[size] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	checkHeap(array_heap, size);
	checkHeap(array_not_heap, size);
	return 0;
}
