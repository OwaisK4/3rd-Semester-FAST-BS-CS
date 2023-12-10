#include <iostream>
using namespace std;
const int MAX = 6;
int count = 0;

template <typename T>
void escapeMaze(T array, int position, int size){
	if (position > size){
		return;
	}
	else if (position == size){
		count++;
		return;
	}
	escapeMaze(array, position + 1, size);
	escapeMaze(array, position + 2, size);
	escapeMaze(array, position + 4, size);
}

int CountPaths(int n, int TotalPaths){
	if ((n==0) || (n==1)) {
		return TotalPaths + 1;
	}
	else if (n==2){
		return (TotalPaths+2);
	}
	else if (n==3){
		return CountPaths(n-2,TotalPaths) + CountPaths(n-1,TotalPaths);
	}
	else {
		return CountPaths(n-4, TotalPaths) + CountPaths(n-2,TotalPaths) + CountPaths(n-1, TotalPaths);
	}
}

int main(){
	int array[MAX] = {0};
	escapeMaze(array, 0, MAX);
	cout << "There are " << count << " ways of escaping a maze of size = " << MAX << ".\n";
	cout << "There are " << CountPaths(MAX, 0) << " ways of escaping a maze of size = " << MAX << ".";
	return 0;
}
