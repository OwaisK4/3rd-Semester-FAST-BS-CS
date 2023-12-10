#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class MinHeap{
	public:
		int *harr;
		int capacity;
		int heap_size;

	MinHeap(int cap){
		heap_size = 0;
		capacity = cap;
		harr = new int[cap];
	}
	int parent(int i){
		return (i-1) / 2;
	}
	int left(int i){
		return (2*i + 1);
	}
	int right(int i){
		return (2*i + 2);
	}
	int getMin() {
		return harr[0];
	}
	void insertKey(int k){
		if (heap_size == capacity){
			cout << "\nOverflow: Could not insert Key\n";
			return;	
		}
		heap_size++;
		int i = heap_size - 1;
		harr[i] = k;
		while (i != 0 && harr[parent(i)] > harr[i]){
			swap(harr[i], harr[parent(i)]);
			i = parent(i);
		}
	}
	void decreaseKey(int i, int new_val){
		harr[i] = new_val;
		while (i != 0 && harr[parent(i)] > harr[i]){
			swap<int>(harr[i], harr[parent(i)]);
			i = parent(i);
		}
	}
	void deleteKey(int i){
		decreaseKey(i, INT_MIN);
		extractMin();
	}
	void linearSearch(int val){
		for (int i = 0; i < heap_size; i++){
			if (harr[i] == val){
				cout << "Value Found!";
				return;
			}
		}
    	cout << "Value NOT Found!";
	}
	int extractMin(){
		if (heap_size <= 0)
			return INT_MAX;
		if (heap_size == 1){
			heap_size--;
			return harr[0];
		}
    // Store the minimum value, and remove it from heap
		int root = harr[0];
		harr[0] = harr[heap_size - 1];
    	heap_size--;
		MinHeapify(0);
    	return root;
	}

  // A recursive method to heapify a subtree with the root at given index
  // This method assumes that the subtrees are already heapified
	void MinHeapify(int i){
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < heap_size && harr[l] < harr[i])
			smallest = l;
		if (r < heap_size && harr[r] < harr[smallest])
			smallest = r;
		if (smallest != i){
			swap<int>(harr[i], harr[smallest]);
			MinHeapify(smallest);
		}
	}

	void printArray() {
		for (int i = 0; i < heap_size; i++)
			cout << harr[i] << " ";
		cout << endl;
	}
};

class MaxHeap{
	public:
		int *harr;
		int capacity;
		int heap_size;

	MaxHeap(int cap){
		heap_size = 0;
		capacity = cap;
		harr = new int[cap];
	}
	int parent(int i){
		return (i-1) / 2;
	}
	int left(int i){
		return (2*i + 1);
	}
	int right(int i){
		return (2*i + 2);
	}
	int getMin() {
		return harr[0];
	}
	void insertKey(int k){
		if (heap_size == capacity){
			cout << "\nOverflow: Could not insert Key\n";
			return;	
		}
		heap_size++;
		int i = heap_size - 1;
		harr[i] = k;
		while (i != 0 && harr[parent(i)] < harr[i]){
			swap(harr[i], harr[parent(i)]);
			i = parent(i);
		}
	}
	void decreaseKey(int i, int new_val){
		harr[i] = new_val;
		while (i != 0 && harr[parent(i)] > harr[i]){
			swap<int>(harr[i], harr[parent(i)]);
			i = parent(i);
		}
	}
	void deleteKey(int i){
		decreaseKey(i, INT_MAX);
		extractMax();
	}
	void linearSearch(int val){
		for (int i = 0; i < heap_size; i++){
			if (harr[i] == val){
				cout << "Value Found!";
				return;
			}
		}
    	cout << "Value NOT Found!";
	}
	int extractMax(){
		if (heap_size <= 0)
			return INT_MIN;
		if (heap_size == 1){
			heap_size--;
			return harr[0];
	}
    // Store the minimum value, and remove it from heap
		int root = harr[0];
		harr[0] = harr[heap_size - 1];
    	heap_size--;
		MaxHeapify(0);
    	return root;
	}

  // A recursive method to heapify a subtree with the root at given index
  // This method assumes that the subtrees are already heapified
	void MaxHeapify(int i){
		int l = left(i);
		int r = right(i);
		int largest = i;
		if (l < heap_size && harr[l] > harr[largest])
			largest = l;
		if (r < heap_size && harr[r] > harr[largest])
			largest = r;
		if (largest != i){
			swap<int>(harr[i], harr[largest]);
			MaxHeapify(largest);
		}
	}

	void printArray() {
		for (int i = 0; i < heap_size; i++)
			cout << harr[i] << " ";
		cout << endl;
	}
};

int main(){
	const int size = 10;
	int array[size] = {8, 9, 11, 12, 10, 7, 4, 3, 5, 1};
	
	MinHeap min(size);
	MaxHeap max(size);
	cout << "Unsorted array: ";
	for (int i=0; i<size; i++){
		cout << array[i] << " ";
		min.insertKey(array[i]);
		max.insertKey(array[i]);
	}
	cout << "\n\nMinimum heap: ";
	min.printArray();
	cout << "Maximum heap: ";
	max.printArray();
}