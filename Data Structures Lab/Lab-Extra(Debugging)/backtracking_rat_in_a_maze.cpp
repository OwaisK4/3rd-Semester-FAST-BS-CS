#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
void print_array(T array[][5]){
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool isSafe(int array[][5], int x, int y, int n){
	if ((x < n) && (y < n) && (x >= 0) && (y >= 0) && array[x][y] == 1)
		return true;
	else
		return false;
}

bool rat_in_a_maze(int input[][5], int x, int y, int n, char solution[][5]){
	print_array(solution);
	if ((x == n-1) && (y == n-1)){
		solution[x][y] = '1';
		return true;
	}
	if (isSafe(input, x, y, n)){
		solution[x][y] = '1';
				
		if (rat_in_a_maze(input, x+1, y, n, solution))
			return true;
		else if (rat_in_a_maze(input, x, y+1, n, solution))
			return true;
		else if (rat_in_a_maze(input, x-1, y, n, solution))
			return true;
//		else if (rat_in_a_maze(input, x, y-1, n, solution))
//			return true;
		else{
			solution[x][y] = '0';
			return false;
		}
	}
	else{
//		solution[x][y] = '0';
		return false;
	}
	
}

int main(){
	int inputArray[5][5] = {{1, 0, 1, 0, 1},
							{1, 1, 1, 1, 1},
							{0, 1, 0, 1, 0},
							{1, 0, 0, 1, 1},
							{1, 1, 1, 0, 1}};
	char solution[5][5];
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			solution[i][j] = 'x';
		}
	}
	if (rat_in_a_maze(inputArray, 0, 0, 5, solution)){
		cout << "True\n\n";
	}
	else
		cout << "False\n\n";
	
	cout << "Input Array:\n";
	print_array<int>(inputArray);
	cout << "Solution Array:\n";
	print_array<char>(solution);
	return 0;
}
