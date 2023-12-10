#include <iostream>
using namespace std;
void printSolution (int** solution, int n) {
	 for(int i=0;i<n; i++){ 
	 	for(int j=0; j<n; j++){
			cout << solution[i][j] << " ";
		}
	}
	cout<<endl;
}
bool mazeHelp(int** maze, int n, int** solution, int x, int y){
	if(x == n-1 && y == n-1){
		solution [x][y] =1; 
		printSolution (solution, n); 
		return true;
	}
	if(x>=n || x<0 || y>=n || y<0 || maze[x] [y] ==0 || solution [x][y] ==1) {
	return true;
	}
		
	
	solution [x][y] = 1; 
	mazeHelp (maze, n, solution, x-1,y); 
	mazeHelp (maze, n, solution, x+1,y); 
	mazeHelp (maze, n, solution,x,y-1); 
	mazeHelp (maze, n, solution, x, y+1); 
	solution [x][y] = 0;
	}
	
	
	
	int main(){
		int n;
		cin>>n;
	
		int** maze = new int*[n];
		for (int i=0;i<n;i++){
			maze[i]=new int[n];
		}
		
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
			cin>>maze[i][j];
			}
		}
			cout<<endl;
		int** solution = new int*[n];
		for (int i=0;i<n;i++){
			solution[i]=new int[n];
		}	
		
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				solution[i][j]=0;
			}
		}
		if(mazeHelp(maze,n,solution,0,0)){
			
			for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
			cout<<	solution[i][j]<<" ";
			}cout<<endl;
		}
		}
		return 0;
	}
