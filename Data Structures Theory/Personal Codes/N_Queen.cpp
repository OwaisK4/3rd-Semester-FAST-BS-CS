#include <iostream>
#define N 5
using namespace std;

void printMatrix(int array[N][N], int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool isSafe(int array[N][N], int row, int col, int n){
	for (int i=0; i<row; i++){
		if (array[i][col] == 1)
			return false;
	}
	for (int i=row, j=col; i>=0, j>=0; i--, j--){
		if (array[i][j] == 1)
			return false;
	}
	for (int i=row, j=col; i>=0, j<n; i--, j++){
		if (array[i][j] == 1)
			return false;
	}
	return true;
}

bool nQueen(int array[N][N], int row, int n){
	if (row >= n){
		printMatrix(array, n);
//		return true;
		return false;
	}
	for (int col=0; col<n; col++){
		if (isSafe(array, row, col, n)){
			array[row][col] = 1;
			if (nQueen(array, row+1, n)){
				return true;
			}
			array[row][col] = 0;
		}
	}
	return false;
}

int main(){
	int array[N][N] = {};
	if (nQueen(array, 0, N))
		printMatrix(array, N);
	return 0;
}