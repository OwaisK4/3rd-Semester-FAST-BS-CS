#include <iostream>
#include <cstring>
using namespace std;

class SafeArray{
	private:
		int *data;
		static int size;
		static int count;
	public:
		SafeArray(){
			data = new int[1];
			data[0] = 0;
			size = 1;
			count = 0;
		}
		SafeArray(int d){
			data = new int[1];
			data[0] = d;
			size = 1;
			count = 1;
		}
		SafeArray(const SafeArray& copy){
			count = copy.count;
			size = copy.size;
			data = new int[size];
			memcpy(data, copy.data, sizeof(int) * size);
		}
		int getCount(){
			return count;
		}
		int getSize(){
			return size;
		}
		void resize(){
			if (count >= size){
				int *temp = new int[size*2];
				memcpy(temp, data, sizeof(int) * size);
				size = size * 2;
				delete data;
				data = temp;
			}			
		}
		bool isSafe(int index){
			if (index > count)
				return false;
			else
				return true;
		}
		void prepend(int value){
			resize();
			int i;
			for (i = count; i > 0; i--){
				data[i] = data[i-1];
			}
			data[i] = value;
			count++;
		}
		void append(int value){
			resize();
			data[count] = value;
			count++;
		}
		void insertAt(int index, int value){
			if (isSafe(index)){
				data[index] = value;
			}
		}
		int get(int index){
			if (isSafe(index)){
				return data[index];
			}
			else
				return -999;
		}
		void print(const char* message = ""){
			cout << message << "[";
			for (int i=0; i<count; i++){
				cout << data[i];
				if (i < count-1)
					cout << ", ";
			}
			cout << "]\n";
		}
		void BubbleSort(){
			int i, j;
			for (i=0; i<count-1; i++){
				for (j=0; j<count-i-1; j++){
					if (data[j] > data[j+1]){
						swap(data[j], data[j+1]);
					}
				}
			}
		}
		void Modified_BubbleSort(){
			int i, j;
			bool swapped;
			for (i=0; i<count-1; i++){
				swapped = false;
				for (j=0; j<count-i-1; j++){
					if (data[j] > data[j+1]){
						swap(data[j], data[j+1]);
						swapped = true;
					}
				}
				if (!swapped)
					return;
			}
		}
		void InsertionSort(){
			int i, j, temp;
			for (int i=1; i<count; i++){
				temp = data[i];
				j = i-1;
				while (j >= 0 && data[j] > temp){
					data[j+1] = data[j];
					j = j - 1;
				}
				data[j+1] = temp;
			}
		}
};

void merge(SafeArray& array, int l, int m, int r){
	int i, j, k;
	i = l;
	j = m + 1;
	k = l;
	SafeArray temp(array);
	
	while (i <= m && j <= r){
		if (array.get(i) < 0){
			temp.insertAt(k, array.get(i));
			array.insertAt(i, -999);
			i++;
			k++;
		}
		else if (array.get(j) < 0){
			temp.insertAt(k, array.get(j));
			array.insertAt(j, -999);
			j++;
			k++;
		}
		else{
			i++;
			j++;
		}
		
	}
	i = l;
	j = m + 1;
	while (i <= m){
		if (array.get(i) != -999){
			temp.insertAt(k, array.get(i));
			k++;
		}
		i++;
	}
	while (j <= r){
		if (array.get(j) != -999){
			temp.insertAt(k, array.get(j));
			k++;
		}
		j++;
	}
	array = temp;
}

void mergeSort(SafeArray& array, int l, int r){
	if (l < r){
		int m = (l+r) / 2;
		mergeSort(array, l, m);
		mergeSort(array, m+1, r);
		merge(array, l, m ,r);
	}
}

int SafeArray::size = 0;
int SafeArray::count = 0;