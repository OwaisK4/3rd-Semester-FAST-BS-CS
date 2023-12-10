#include <iostream>
using namespace std;

int func_ab(int number, int counter, int n){
	if (n <= 0){
		cout << "\n";
		return 0;
	}
	cout << number << " ";
	func_ab(number+counter, counter+1, n-1);
}

int main(){
	func_ab(1, 2, 10);
	func_ab(1, 0, 10);
}