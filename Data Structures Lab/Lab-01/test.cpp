#include <iostream>
#include <cstring>
#define SIZE 3
using namespace std;

bool checkMatrix(int **matrix){
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

void print_matrix();

int main(){
	int Matrix[3][3] = { {1, 0, 0},
						 {0, 1, 0},
						 {0, 0, 1} };
	int **matrixPtr = new int*[SIZE];
	for (int i=0; i<SIZE; i++){
		matrixPtr[i] = new int[SIZE];
	}
	matrixPtr[0][0] = 1;
	matrixPtr[0][1] = 1;
	matrixPtr[0][2] = 1;
	matrixPtr[1][0] = 1;
	matrixPtr[1][1] = 1;
	matrixPtr[1][2] = 1;
	matrixPtr[2][0] = 1;
	matrixPtr[2][1] = 1;
	matrixPtr[2][2] = 1;

	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			cout << matrixPtr[i][j] << " ";
		}
		cout << "\n";
	}
	
	if (checkMatrix(Matrix))
		cout << "Success! Given matrix is an identity matrix.";
	else
		cout << "Failure! Given matrix is not an identity matrix.";

	if (checkMatrix(matrixPtr))
		cout << "Success! Given matrix is an identity matrix.";
	else
		cout << "Failure! Given matrix is not an identity matrix.";
		
	return 0;
}
