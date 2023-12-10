#include <iostream> 
#include <string> 
using namespace std;
int main(){
	// Rows 
	int* jagged[2];
// Allocate memory for clements in row 0 
	jagged[0] = new int[1];
// Allocate memory for elements in row 1 
	jagged[1] = new int[5];
//	Array to hold the size of cach row 
	int Size[2] = {1,5}, k = 0, number = 100;
//User enters the numbers
	 for (int i = 0;i < 2; i++){
	int* p=jagged[i];
	for (int j = 0; j < Size[k]; j++){
		*p = number++;
// move the pointer 
		p++;
	}
		k++;
}
		k = 0;
// Display elements in Jagged array 
		for (int i = 0; i < 2; i++) {
		int* p = jagged[i];
			 for (int j = 0; j < Size[k]; j++) {
				std::cout<< *p<<""<<endl;
			// move the pointer to the next element
			p++;
		}
			std::cout<<"\n";
			 k++; 
			 // move the pointer to the next row
jagged[i]++;
}
return 0;
}

