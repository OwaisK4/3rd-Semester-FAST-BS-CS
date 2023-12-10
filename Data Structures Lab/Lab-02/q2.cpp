#include <iostream>
using namespace std;

void even(int num);

void odd(int num){
	if (num > 10){
		return;
	}
	cout << num + 1 << " ";
	even(num+1);
	
}
void even(int num){
	if (num > 10){
		return;
	}
	cout << num - 1 << " ";
	odd(num+1);
}

int main(){
	odd(1);
	return 0;
}
