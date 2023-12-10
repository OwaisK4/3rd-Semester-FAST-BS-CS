#include <iostream>
#include "DSA.h"
using namespace std;

class Person{
	public:
		string first_name;
		string last_name;
		struct {
			int year, month, date;
		} birth;
	public:
		Person(){
			first_name = "";
			last_name = "";
			birth.year = 0;
			birth.month = 0;
			birth.date = 0;
		}
		Person(string fn, string ln, int by, int bm, int bd){
			first_name = fn;
			last_name = ln;
			birth.year = by;
			birth.month = bm;
			birth.date = bd;
		}
		void input(){
			cout << "\nEnter first name: ";
			cin.ignore(256, '\n');
			cin.clear();
			getline(cin, first_name);
			cout << "Enter last name: ";
//			cin.ignore(256, '\n');
//			cin.clear();
			getline(cin, last_name);
			cout << "Enter birth year: ";
			cin >> birth.year;
			cout << "Enter birth month: ";
			cin >> birth.month;
			cout << "Enter birth date: ";
			cin >> birth.date;
		}
		void print(){
			cout << "\nFirst name: " << first_name;
			cout << "\nLast name: " << last_name;
			cout << "\nBirth year: " << birth.year;
			cout << "\nBirth month: " << birth.month;
			cout << "\nBirth date: " << birth.date;
			cout << "\n";
		}
};

void SelectionSort(Person array[], int size){
	for (int i=0; i<size-1; i++){
		int min_index = i;
		for (int j=i+1; j<size; j++){
			if (array[j].birth.year < array[min_index].birth.year){
				min_index = j;
			}
			else if (array[j].birth.year == array[min_index].birth.year){
				if (array[j].birth.month < array[min_index].birth.month)
					min_index = j;
				else if (array[j].birth.month == array[min_index].birth.month){
					if (array[j].birth.date < array[min_index].birth.date)
						min_index = j;
				}
			}
		}
		if (min_index != i)
			swap<Person>(array[min_index], array[i]);
	}
}

int main(){

	int n = 5;
//	cout << "Enter number of persons: ";
//	cin >> n;
	Person person[n] = {};
	person[0] = Person("Owais Ali", "Khan", 2003, 5, 15);
	person[1] = Person("Ashar Ali", "Khan", 1998, 10, 22);
	person[2] = Person("Shazia", "Shaikh", 1974, 9, 7);
	person[3] = Person("Anwar", "Khan", 1970, 7, 4);
	person[4] = Person("X", "Y", 2003, 5, 14);
//	for (int i=0; i<n; i++){
//		person[i].input();
//	}
	
//	cout << "Before sorting:\n";
//	for (int i=0; i<n; i++){
//		person[i].print();
//	}
	SelectionSort(person, n);
	
	cout << "\nAfter sorting:\n";
	for (int i=0; i<n; i++){
		person[i].print();
	}
	return 0;
}	
