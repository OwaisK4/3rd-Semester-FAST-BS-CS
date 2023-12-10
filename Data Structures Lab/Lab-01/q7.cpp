#include <iostream>
using namespace std;

// No copy constructor in order to understand how pointer copying works.

class Numbers{
	private:
		int size;
		int *pointer;
	public:
		Numbers(){
			pointer = new int;
		}
		Numbers(int s, int* p){
			size = s;
			pointer = p;
			pointer = new int;
			*pointer = *p;
		}
		void set_size(int s){
			size = s;
		}
		void set_pointer(int *p){
			*pointer = *p;
		}
		void print(){
			cout << "Size = " << size << "\n";
			cout << "Pointer = " << *pointer << "\n";
		}
		~Numbers(){
			delete pointer;
		}
};

int main(){
	int s = 5;
	int p = 7;
	
	Numbers num1(s, &p);
	Numbers num2(num1);
	num1.print();
	num2.print();
	
	s = 10;
	p = 12;
	
	num1.set_size(s);
	num1.set_pointer(&p);
	num1.print();
	num2.print();	// Size is different, yet pointer is same. Because copy constructor directly copies value of size and pointer(which is an address to the real value).
	
	return 0;
}
