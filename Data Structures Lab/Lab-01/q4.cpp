#include <iostream>
#define SIZE 10
using namespace std;

void print_array(int *array, const char *message, int size=10){
	cout << message;
	for (int i=0; i<size; i++){
		cout << array[i] << " ";
	}
	cout << "\n";
}

int main(){
	int *sorted = new int[10]{0,1,2,3,4,5,6,7,8,9};
	int *auxiliary = new int[10]{0};
	int i = 0, j = 0;
	while (i < 5){
		auxiliary[j++] = sorted[SIZE - i - 1];
		auxiliary[j++] = sorted[i];
		i++;
	}
	print_array(sorted, "Original array: ");
	print_array(auxiliary, "Transformed array: ");
	
	delete [] sorted;
	delete [] auxiliary;
	return 0;
}
