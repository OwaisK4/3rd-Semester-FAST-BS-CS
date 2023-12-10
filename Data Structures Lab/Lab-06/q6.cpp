#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sort{
	private:
		int *array;
		int size;
		string choice;
		int swaps, comparisions;
		int techniques[4];
		string technique_name[4] = {"Bubble", "Modified Bubble", "Selection", "Insertion"};
	public:
		int BubbleSort(int array[], int size){
			swaps = 0;
			comparisions = 0;
			int i, j;
			for (i=0; i<size-1; i++){
				for (j=0; j<size-i-1; j++){
					comparisions++;
					if (array[j] > array[j+1]){
						swap(array[j], array[j+1]);
						swaps++;
					}
				}
			}
		}
		int Modified_BubbleSort(int array[], int size){
			swaps = 0;
			comparisions = 0;
			int i, j;
			bool swapped;
			for (i=0; i<size-1; i++){
				swapped = false;
				for (j=0; j<size-i-1; j++){
					comparisions++;
					if (array[j] > array[j+1]){
						swap(array[j], array[j+1]);
						swapped = true;
						swaps++;
					}
				}
				if (!swapped)
					return 0;
			}
		}
		int InsertionSort(int array[], int size){
			swaps = 0;
			comparisions = 0;
			int i, j, temp;
			for (int i=1; i<size; i++){
				temp = array[i];
				j = i-1;
				while (j >= 0 && array[j] > temp){
					comparisions++;
					array[j+1] = array[j];
					j = j - 1;
				}
				array[j+1] = temp;
				swaps++;
			}
		}
		int SelectionSort(int array[], int size){
			swaps = 0;
			comparisions = 0;
			for (int i=0; i<size-1; i++){
				int min_index = i;
				for (int j=i+1; j<size; j++){
					comparisions++;
					if (array[j] < array[min_index]){
						min_index = j;
					}
				}
				if (min_index != i){
					swap(array[i], array[min_index]);
					swaps++;
				}
			}
		}
		Sort(int arr[], int length, string type = "NULL"){
			size = length;
			array = new int[size];
			memcpy(array, arr, size * sizeof(int));
			choice = type;
		}
		void sort(string str = "NULL"){
			if (str != "NULL")
				choice = str;
			if (choice == "bubble")
				BubbleSort(array, size);
			else if (choice == "modified")
				Modified_BubbleSort(array, size);
			else if (choice == "insertion")
				InsertionSort(array, size);
			else if (choice == "selection")
				SelectionSort(array, size);
			else
				cout << "Invalid sorting technique specified.\n";
		}
		void print(){
			for (int i=0; i<size; i++){
				cout << array[i] << " ";
			}
			cout << "\n";
		}
		void print(int arr[], int length){
			for (int i=0; i<length; i++){
				cout << arr[i] << " ";
			}
			cout << "\n";
		}
		void analysis(int length){
			int random_array[length];
			for (int i=0; i<length; i++){
				random_array[i] = rand() % 50;
			}
			int *temp = new int[length];
			memcpy(temp, random_array, length * sizeof(int));
			cout << "\nRandom array: ";
			print(temp, length);
			
			BubbleSort(temp, length);
			cout << "Bubble sort analysis:";
			cout << "\nComparisons: " << comparisions;
			cout << "\nSwaps: " << swaps;
			techniques[0] = comparisions;
			
			memcpy(temp, random_array, length * sizeof(int));
			Modified_BubbleSort(temp, length);
			cout << "\n\nModified Bubble sort analysis:";
			cout << "\nComparisons: " << comparisions;
			cout << "\nSwaps: " << swaps;
			techniques[1] = comparisions;
			
			memcpy(temp, random_array, length * sizeof(int));
			SelectionSort(temp, length);
			cout << "\n\nSelection sort analysis:";
			cout << "\nComparisons: " << comparisions;
			cout << "\nSwaps: " << swaps;
			techniques[2] = comparisions;
			
			memcpy(temp, random_array, length * sizeof(int));
			InsertionSort(temp, length);
			cout << "\n\nInsertion sort analysis:";
			cout << "\nComparisons: " << comparisions;
			cout << "\nSwaps: " << swaps;
			techniques[3] = comparisions;
			
//			int max = techniques[0];
//			int min = techniques[0];
			int max_index = 0;
			int min_index = 0;
			for (int i=0; i<4; i++){
				if (techniques[max_index] < techniques[i])
					max_index = i;
				if (techniques[min_index] > techniques[i])
					min_index = i;
			}
			cout << "\n\nBest technique is " << technique_name[min_index] << " with " << techniques[min_index] << " comparisons.";
			cout << "\nWorst technique is " << technique_name[max_index] << " with " << techniques[max_index] << " comparisons.\n";
		}
};

int main(){
	srand(time(0));
	int array[] = {1,5,2,7,4,8,9,0,3,6};
	int n = 10;
	Sort first(array, n);
	cout << "Unsorted array: ";
	first.print();
//	first.sort("selection");
//	first.sort("bubble");
//	first.sort("modified");
	first.sort("insertion");
	cout << "Sorted array: ";
	first.print();
	
	first.analysis(10);
	return 0;
}
