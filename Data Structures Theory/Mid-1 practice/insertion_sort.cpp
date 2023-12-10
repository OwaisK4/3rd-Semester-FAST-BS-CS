#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;
const int SIZE = 10;

template <typename Container>
void insertionSort(Container& array, int size){
	int i, j;
	int key;
	for (i=1; i<size; i++){
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}
template <>
void insertionSort(map<int, int>& array, int size){
	int i, j;
	int key;
	for (i=1; i<size; i++){
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}

template <typename Container>
void printContainer(const Container& array){
	for (auto it = begin(array); it != end(array); it++)
		cout << *it << " ";
	cout << "\n";
}
template <>
void printContainer(const map<int, int>& array){
	for (auto it = begin(array); it != end(array); it++)
		cout << "(" << it->first << ", " << it->second << "), ";
	cout << "\n";
}

int main(){
//	int *array = new array[SIZE];
	srand(time(0));
	int array[SIZE];
	map<int, int> values;
	for (int i=0; i<SIZE; i++){
		array[i] = rand() * SIZE / RAND_MAX;
		values.insert(pair<int, int>(i, rand() * SIZE / RAND_MAX));
	}
	printContainer(array);
	printContainer(values);
	insertionSort<int[SIZE]>(array, SIZE);
	insertionSort<map<int, int> >(values, SIZE);
	printContainer(array);
	printContainer(values);
	return 0;
}
