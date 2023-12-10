#include <iostream>
using namespace std;

const int number_of_airlines = 5;

int main(){
	int **airline = new int*[number_of_airlines];
	int Size[number_of_airlines];
	int Sum[number_of_airlines]{0};
	char *airlines[5] = {"British Airways", "Eastern Airways", "Easy Jet", "FlyBe", "Ryanair"};
	char *cities[5] = {"Moscow", "Chicago", "Astana", "Edinburgh", "Helsinki"};
	
	for (int i=0; i<number_of_airlines; i++){
		cout << "Enter number of cities visited by " << airlines[i] << ": ";
		cin >> Size[i];
		*(airline + i) = new int[Size[i]];
	}
	cout << "\n";
	for (int i=0; i<number_of_airlines; i++){
		for (int j=0; j<Size[i]; j++){
			cout << "Enter kilometers distance to " << cities[j] << ": ";
			cin >> *(*(airline+i)+j);
			while (*(*(airline+i)+j) > 400){
				cout << "Maximum distance can be 400 km.\n";
				cout << "Enter kilometers distance to " << cities[j] << ": ";
				cin >> *(*(airline+i)+j);
			}
		}
		cout << "\n";
	}
	for (int i=0; i<number_of_airlines; i++){
		for (int j=0; j<Size[i]; j++){
			Sum[i] += *(*(airline+i)+j);
		}
		cout << airlines[i] << " travelled a total of " << Sum[i] << " kilometers.\n";
		delete [] *(airline + i);
	}
	delete [] airline;
	
	return 0;
}
