#include <iostream>
using namespace std;

int sum = 0;
void factors_recursive(int i, int a);
void factors(int a){
	int factor = 0;
	for (int i=1; i<=a; i++){
		if (a % i == 0){
			factor = i;
			cout << factor << "\n";
		}
	}
	return;
}

int get_sum(int a){
	for (int i=1; i<=a; i++){
		if (a % i == 0){
			sum += i;
		}
	}
	return sum;
}

int main(){
	int a;
	cout << "Enter positive integer: ";
	cin >> a;
	if (a == -1)
		return 0;
	cout << "\nFactors:\n";
	factors_recursive(1, a);
	cout << "\nSum: " << get_sum(a);
	return 0;
}



void factors_recursive(int i, int a){
	if (i >= a)
		return;
	int factor = 0;
	if (a % i == 0){
		factor = i;
	}
	factors_recursive(i+1, a);
	if (factor != 0)
		cout << factor << "\n";
}