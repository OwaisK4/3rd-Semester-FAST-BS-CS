#include <iostream>
#include <cstring>
using namespace std;

class Animal{
	private:
		int ID;
		string name;
	public:
		Animal(){}
		Animal(int i, string n): ID(i), name(n){}
		void print(){
			cout << "Animal ID is: " << ID;
			cout << "\nAnimal name is: " << name << "\n";
		}
		void set_ID(int i){
			ID = i;
		}
		void set_name(string n){
			name = n;
		}
		const char *get_name(){
			return name.c_str();
		}
};

int main(){
	Animal *animal = new Animal[5];
	animal[0].set_ID(3);
	animal[0].set_name("Cat");
	animal[1].set_ID(5);
	animal[1].set_name("Elephant");
	animal[2].set_ID(2);
	animal[2].set_name("Bear");
	animal[3].set_ID(4);
	animal[3].set_name("Deer");
	animal[4].set_ID(1);
	animal[4].set_name("Ant");
	
	for (int i=0; i<5; i++){
		animal[i].print();
	}
	cout << "\n";
	
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			Animal temp;
			if (strcmp(animal[i].get_name(), animal[j].get_name()) < 0){
				temp = animal[j];
				animal[j] = animal[i];
				animal[i] = temp;
			}
		}
	}

	for (int i=0; i<5; i++){
		animal[i].print();
	}
	
	delete [] animal;
	return 0;
}
