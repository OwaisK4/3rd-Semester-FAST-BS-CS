#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int array[], int left, int right, int key){
	if (left > right)
		return -1;
	else{
		int middle = (left + right) / 2;
		if (array[middle] == key)
			return middle;
		else if (array[middle] > key)
			return BinarySearch(array, left, middle-1, key);
		else
			return BinarySearch(array, middle+1, right, key);
	}
}

int main(){
	const int size = 10;
	int array[size] = {0,1,2,3,4,5,6,7,8,9};
	transform(array, array + size, array, [](int x){return x*2;});
	
	int num, output;
	cout << "Please enter an element to search" << endl;
	cin >> num;
	
	output = BinarySearch(array, 0, 9, num);
	
	if (output == -1){
		cout << "No Match Found" << endl;
	}
	else{
		cout << "Match found at position: " << output << endl;
	}
	return 0;
}