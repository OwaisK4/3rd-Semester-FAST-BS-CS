#include <iostream>
using namespace std;
const int SIZE = 10;

template <typename Container>
void printContainer(const Container& array, int size){
	for (int i=0; i<size; i++){
		cout << array[i] << " ";
	}
	cout << "\n";
}

void leftRotateK(int array[], int n, int k){
	if (k > n)
		k = k % n;
	for (int i=0, j=0; j<k; j++){
		int temp = array[0];
		for (i=0; i<n-1; i++){
			array[i] = array[i+1];
		}
		array[i] = temp;
	}
}

int main(){
	int array[10] = {0,1,2,3,4,5,6,7,8,9};
	printContainer(array, 10);
	leftRotateK(array, 10, 3);
	printContainer(array, 10);
	return 0;
}
