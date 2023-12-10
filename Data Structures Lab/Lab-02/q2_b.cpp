#include <iostream>
using namespace std;

void recurse2(int num, int counter, int n);

void recurse1(int num, int counter, int n){
	if (n >= 10)
		return;
	cout << num << " ";
	recurse2(num+counter, counter+1, n+1);
}
void recurse2(int num, int counter, int n){
	if (n >= 10)
		return;
	cout << num << " ";
	recurse1(num+counter, counter+1, n+1);
}

int main(){
	recurse1(1,0,0);
	return 0;
}
