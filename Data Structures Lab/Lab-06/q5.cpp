#include <iostream>
using namespace std;

template <typename T>
void BubbleSort(T array[], int size){
	int i, j;
	for (i=0; i<size-1; i++){
		for (j=0; j<size-i-1; j++){
			if (array[j] > array[j+1]){
				swap(array[j], array[j+1]);
			}
		}
	}
}

void maxToys(int array[], int n, int k){
	BubbleSort(array, n);
	int sum = 0;
	for (int i=0; i<n; i++){
		sum += array[i];
	}
	if (sum <= k){
		cout << "You can buy all toys.\n";
	}
	else{
		sum = 0;
		cout <<  "The costs of the toys you can buy are ";
		for (int i=0; i<n; i++){
			sum += array[i];
			if (sum > k)
				break;
			cout << array[i] << " ";
		}
		cout << ".\n";
	}
}

int main(){
	int n = 7;
	int k = 50;
	int arr[n] = {1, 12, 5, 111, 200, 1000, 10};
	maxToys(arr, n, k);
	
	n = 3;
	k = 100;
	int arr2[n] = {20, 30, 50};
	maxToys(arr2, n, k);
	return 0;
}
