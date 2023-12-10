#include <iostream>
#include <cstring>
#define SIZE 3
using namespace std;

template<typename T>
bool checkMatrix(const T& matrix){
	if (matrix[0][0] == 1){
		for (int i=0; i<SIZE; i++){
			for (int j=0; j<SIZE; j++){
				if (i == j){
					if (matrix[i][j] != 1)
						return false;
					else
						continue;
				}
				if (matrix[i][j] != 0)
					return false;
			}
		}
		return true;
	}
	else if (matrix[0][SIZE-1] == 1){
		for (int i=0; i<SIZE; i++){
			for (int j=0; j<SIZE; j++){
				if (i+j == 2){
					if (matrix[i][j] != 1)
						return false;
					else
						continue;
				}
				if (matrix[i][j] != 0)
					return false;
			}
		}
		return true;
	}
	else
		return false;
}

template<typename T>
void print_matrix(const T& matrix, int size=SIZE){
	for (int i=0; i<size; i++){
		for (int j=0; j<size; j++){
			cout << *(*(matrix + i) + j) << " ";
		}
		cout << "\n";
	}
}

int main(){
	int Matrix[3][3] = { {0, 0, 1},
						 {0, 1, 0},
						 {1, 0, 0} };
	int **matrixPtr = new int*[SIZE];
	for (int i=0; i<SIZE; i++){
		matrixPtr[i] = new int[SIZE];
	}
	matrixPtr[0][0] = 0;
	matrixPtr[0][1] = 1;
	matrixPtr[0][2] = 2;
	matrixPtr[1][0] = 3;
	matrixPtr[1][1] = 4;
	matrixPtr[1][2] = 5;
	matrixPtr[2][0] = 6;
	matrixPtr[2][1] = 7;
	matrixPtr[2][2] = 8;
	
	print_matrix<int [3][3]>(Matrix);
	if (checkMatrix(Matrix))
		cout << "Success! Given matrix is an identity matrix.\n";
	else
		cout << "Failure! Given matrix is not an identity matrix.\n";

	cout << "\n";
	print_matrix<int **>(matrixPtr);
	if (checkMatrix(matrixPtr))
		cout << "Success! Given matrix is an identity matrix.\n";
	else
		cout << "Failure! Given matrix is not an identity matrix.\n";
	
	for (int i=0; i<SIZE; i++){
		delete [] matrixPtr[i];
	}
	delete [] matrixPtr;
	return 0;
}
