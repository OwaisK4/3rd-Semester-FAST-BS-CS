#include<iostream>
#define N 8
using namespace std;

void print(int **array,int n){
cout<<"\n";
for(int i=0;i<n;i++){
cout<<"\n";
for(int j=0;j<n;j++){
cout<<array[i][j]<<" ";
}
}
}

bool issafe(int **array,int ROW,int COL,int n){
for(int row=0;row<ROW;row++){
if(array[row][COL]==1)
return false;
}
int row=ROW;
int col=COL;
while(row>=0 && col>=0){
if(array[row][col]==1)
return false;
row--;
col--;
}
row=ROW;
col=COL;
while(row>=0 && col<n){
if(array[row][col]==1)
return false;
row--;
col++;
}
return true;
}
bool nqueen(int **array,int Row,int n){
if(Row>=n){
//print(array,n);
return true;
}
for(int Col=0;Col<n;Col++){
if(issafe(array,Row,Col,n)){
array[Row][Col]=1;
if(nqueen(array,Row+1,n)){
print(array,n);
}
array[Row][Col]=0;
}
}
return false;
}
int main()
{
int **array = new int *[N];
for(int i=0;i<N;i++){
array[i]=new int[N];
for(int j=0;j<N;j++){
array[i][j]=0;
}
}

if(nqueen(array,0,N)){
//for(int i=0;i<4;i++){
//cout<<endl;
//for(int j=0;j<4;j++){
//cout<<array[i][j]<<" ";
//}
//}
}
return 0;
}