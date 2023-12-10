#include <iostream>
using namespace std;

int sum(int num){
	if (num > 0){
		return num + sum(num-1);
//		return sum(num + num-1);
	}
	else
		return num;
}

int main(){
	cout << sum(10);
	return 0;
}
