#include <iostream>
using namespace std;

int main(){
	int *ptr1 = new int(5);
	int *ptr2 = new int[5]{5};
	int *array1{ new int[10] };
	int *array2{ new int[10]{0,1,2,3,4,5,6,7,8,9} };
	
	cout << *ptr1 << "\n";
	cout << *ptr2 << "\n";
	
	for (int i=0; i<5; i++)
		cout << ptr2[i] << " ";
	cout << "\n";
	for (int i=0; i<10; i++)
		cout << array1[i] << " ";
	cout << "\n";
	for (int i=0; i<10; i++)
		cout << array2[i] << " ";
	return 0;
}
