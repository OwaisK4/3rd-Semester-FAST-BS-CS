#include <iostream>
#include <cstring>
using namespace std;

void Merge(int array[], int l, int m, int r){
	int i, j, k;
	i = l;
	j = m + 1;
	k = l;
	int temp[r+l-1];
	// int temp[10];
	
	while (i <= m && j <= r){
		if (array[i] <= array[j]){
			temp[k] = array[i];
			i++;
			k++;
		}
		else{
			temp[k] = array[j];
			j++;
			k++;
		}
	}
	
	while (i <= m){
		temp[k] = array[i];
		i++;
		k++;
	}
	while (j <= r){
		temp[k] = array[j];
		j++;
		k++;
	}
	for (int i=l; i<=r; i++){
		array[i] = temp[i];
	}
	// memcpy(array, temp, r+1);
}

void MergeSort(int array[], int l, int r){
	if (l < r){
		int m = (l+r)/2;
		MergeSort(array, l, m);
		MergeSort(array, m+1, r);
		Merge(array, l, m, r);
	}
}

void printArray(int array[], int size){
	for (int i=0; i<size; i++){
		cout << array[i] << " ";
	}
	cout << "\n";
}

int main(){
	const int size = 10;
	int array[size] = {5,6,7,2,4,1,3,9,8,0};
	printArray(array, size);
	MergeSort(array, 0, size-1);
	printArray(array, size);
	return 0;
}
