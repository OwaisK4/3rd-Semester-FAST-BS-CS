#include <iostream>
#include "DSA.h"
using namespace std;

int main(){
	SafeArray array;
	array.append(5);
	array.append(6);
	array.append(7);
	array.append(8);
	array.prepend(9);
	array.print("Unsorted array: ");
	array.Modified_BubbleSort();
	array.print("Bubble sorted array: ");
	return 0;
}
