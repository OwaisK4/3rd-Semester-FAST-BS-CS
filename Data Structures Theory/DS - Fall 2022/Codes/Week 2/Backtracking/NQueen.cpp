#include<iostream>
using namespace std;

bool isSafe(int** arr, int ROW, int COl, int n) {
	
	
	// to check each row of column received in COL
	for(int row=0; row<ROW; row++){ 	
		if(arr[row][COl]==1){
			return false;
		}	
	}
	
	
	// to check in the direction of upward-left direction 
	int row=ROW; 
	int col=COl; 
	while(row>=0 && col>=0){ 
		if(arr[row][col]==1) {
			return false;
		}
		row--; 
		col--;
	}
	
	// to check in the direction of upward-Right direction 
	row=ROW; 
	col=COl; 
	
		while(row>=0 && col<n){ 
		if(arr[row][col]==1) {
			return false;
		}
		row--; 
		col++;
	}
	return true;
}
bool nQueen ( int** arr, int Row, int n){
	if(Row>=n){
		return true;
	}
	for(int col=0; col<n; col++){ 
	
		if(isSafe(arr,Row,col,n)) {
			
			arr[Row] [col]=1;
			
			if(nQueen (arr,Row+1,n)){
				return true;
			}
			arr[Row] [col]=0; //backtracking
		}
	}
	return false;
}


	int main (){
		int n;
		cin>>n;
	
		int** arr = new int*[n];
		for (int i=0;i<n;i++){
			arr[i]=new int[n];
		}
		
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
			arr[i][j]=0;
			}
		}
		
		if(nQueen (arr, 0,  n)){
			
			for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
			cout<<	arr[i][j]<<" ";
			}cout<<endl;
		}
		}
		 
	}
