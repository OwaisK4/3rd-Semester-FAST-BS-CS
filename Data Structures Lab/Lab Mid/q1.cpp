#include <iostream>
#include <cstring>
using namespace std;

void map(int numbers[], int size, int charCount1 = 0, int charCount2 = 0){
	string array[10] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", ""};
	
	if (size < 2){
		if ((charCount1 >= array[numbers[0]].length())) // && (charCount2 >= array[numbers[1]].length())){
			return;
		cout << array[numbers[0]][charCount1] << " ";
		map(numbers, size, charCount1 + 1, charCount2);
		return;
	}
	if (charCount2 >= array[numbers[1]].length()){
		charCount1++;
		charCount2 = 0;
	}
	if ((charCount1 >= array[numbers[0]].length())) // && (charCount2 >= array[numbers[1]].length())){
		return;
		
	cout << array[numbers[0]][charCount1] << array[numbers[1]][charCount2];
	cout << " ";
	
	map(numbers, size, charCount1, charCount2 + 1);
}

int main(){
	int numbers[10] = {};
	int size;
	cout << "How many numbers are required: ";
	cin >> size;
	cout << "Enter " << size << " numbers separated by spaces: ";
	for (int i=0; i<size; i++){
		cin >> numbers[i];
		numbers[i] -= 1;
	}
	map(numbers, size);
	return 0;
}
