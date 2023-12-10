#include <iostream>
#include <cstring>
using namespace std;

void print_array(int *array, const char *message, int size=10){
	cout << message;
	for (int i=0; i<size; i++){
		cout << array[i] << " ";
	}
	cout << "\n";
}

int main(){
//	int *array = new int[10]{4,3,9,5,75,81,5,7,2,1};
	int *array = new int[10];
	for (int i=0; i<10; i++){
		cout << "Enter integer no." << i << ": ";
		cin >> array[i];
		while (cin.fail()){
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter integer no." << i << ": ";
			cin >> array[i];
		}
	}
	cout << "\n";
	int *ascending = new int[10];
	int *descending = new int[10];
	
	memcpy(ascending, array, sizeof(int)*10);
	memcpy(descending, array, sizeof(int)*10);
	
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			if (ascending[i] < ascending[j]){
				int temp = ascending[i];
				ascending[i] = ascending[j];
				ascending[j] = temp;
			}
			if (descending[i] > descending[j]){
				int temp = descending[i];
				descending[i] = descending[j];
				descending[j] = temp;
			}
		}
	}
	
	print_array(array, "Original array: ");
	print_array(ascending, "Ascending order: ");
	print_array(descending, "Descending order: ");
	
	delete [] array;
	delete [] ascending;
	delete [] descending;
	return 0;
}
