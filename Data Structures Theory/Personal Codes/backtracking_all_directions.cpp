#include <iostream>
#include <fstream>
#define N 5
using namespace std;

template <typename T>
void print_array(T array){
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

template <typename T>
void print_array_to_file(T array){
	fstream fout("rim_solutions.txt", ios::out | ios::trunc);
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			fout << array[i][j] << " ";
		}
		fout << endl;
	}
	fout << endl;
	fout.close();
}

bool isSafe(int array[][N], int x, int y, int n){
	if ((x < n) && (y < n) && (x >= 0) && (y >= 0) && array[x][y] == 1)
		return true;
	else
		return false;
}

fstream fstack("rim_stack.txt", ios::out | ios::trunc);
bool rat_in_a_maze(int input[][N], int x, int y, int n, char solution[][N]){
	print_array_to_file(solution);
//	print_array(solution);
	
	if ((x == n-1) && (y == n-1)){
		solution[x][y] = '1';
		fstack << "\n(" << x << ", " << y << ", " << n << ")\n";
		return true;
	}
	if (solution[x][y] == '1'){
		return false;
	}
	if (isSafe(input, x, y, n)){
		solution[x][y] = '1';
		fstack << "\n(" << x << ", " << y << ", " << n << ")";
		
		if (rat_in_a_maze(input, x+1, y, n, solution))
			return true;
		else if (rat_in_a_maze(input, x, y+1, n, solution))
			return true;
		else if (rat_in_a_maze(input, x-1, y, n, solution))
			return true;
		else if (rat_in_a_maze(input, x, y-1, n, solution))
			return true;
		else{
			solution[x][y] = '0';
			fstack << " X";
			return false;
		}
	}
	else{
//		solution[x][y] = '0';
		return false;
	}
	fstack.close();
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
	if (rat_in_a_maze(inputArray, 2, 1, 5, solution)){
		cout << "True\n\n";
	}
	else
		cout << "False\n\n";
	
	cout << "Input Array:\n";
	print_array(inputArray);
	cout << "Solution Array:\n";
	print_array(solution);
	return 0;
}