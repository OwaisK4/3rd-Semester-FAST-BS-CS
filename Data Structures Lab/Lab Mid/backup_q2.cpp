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
		
		void print(const char* message){
			cout << message;
			for (int i=0; i<count; i++){
				cout << data[i];
				if (i < count-1)
					cout << ", ";
			}
			cout << "\n";
		}
};

void merge(SafeArray& array, int l, int m, int r){
	int i, j, k;
	i = l;
	j = m + 1;
	k = l;
	SafeArray temp(array);
	
	while (i <= m && j <= r){
		if (array.get(i) < array.get(j)){
			temp.insertAt(k, array.get(i));
			i++;
			k++;
		}
		else{
			temp.insertAt(k, array.get(j));
			j++;
			k++;
		}
	}
	while (i <= m){
		temp.insertAt(k, array.get(i));
		i++;
		k++;
	}
	while (j <= r){
		temp.insertAt(k, array.get(j));
		j++;
		k++;
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

int main(){
	SafeArray array;
	array.append(9);
	array.append(-3);
	array.append(5);
	array.append(-2);
	array.append(-8);
	array.append(-6);
	array.append(1);
	array.append(3);
	array.print("Input: ");
	cout << array.getCount();
	mergeSort(array, 0, array.getCount());
	array.print("Output: ");
	return 0;
}
