#include <iostream>
using namespace std;

int main(){
	int a;
	cout << "Enter positive integer: ";
	cin >> a;
	if (a == -1)
		return 0;
	int factor = 0;
	int sum = 0;
	cout << "\nFactors:\n";
	for (int i=1; i<=a; i++){
		if (a % i == 0){
			factor = i;
			sum += factor;
			cout << factor << endl;
		}
	}
	cout << "\nSum: " << sum;
	return 0;
}