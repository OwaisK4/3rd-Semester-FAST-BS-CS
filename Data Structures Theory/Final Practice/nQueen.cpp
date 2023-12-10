#include <iostream>
using namespace std;
const int N = 4;

void printArray(int array[][N], int size){
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isSafe(int array[][N], int row, int col, int n){
    for (int i=0; i<row; i++){
        if (array[i][col] == 1)
            return false;
    }
    for (int i=0, j=0; i<row, j<col; i++, j++){
        if (array[i][j] == 1)
            return false;
    }
    for (int i=0, j=n-1; i<row, j>=col-1; i++, j--){
        if (array[i][j] == 1)
            return false;
    }
    return true;
}

bool nQueen(int array[][N], int row, int n){
    if (row >= n){
        return true;
    }
    for (int col=0; col<n; col++){
        if (isSafe(array, row, col, n)){
            array[row][col] = 1;
            if (nQueen(array, row+1, n))
                return true;
            array[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int array[N][N] = {};
    printArray(array, N);
    if (nQueen(array, 0, N)){
        cout << "True\n";
        printArray(array, N);
    }
    else{
        cout << "False";
    }
    return 0;
}