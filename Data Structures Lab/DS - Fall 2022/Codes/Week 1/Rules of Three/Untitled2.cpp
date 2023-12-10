#include<iostream>
using namespace std;
class Foo
{
	private:
	 	int* p; 
	 	int size;
	public:
	 Foo(int s, int f)
	 {
	 	size = s;
		p = new int[size];
		
		for(int i = 0; i < size; i++)
		 p[i] = f;
	 	
	 }

	~Foo() { delete [] p; }
 	// Copy constructor
    // Foo f(g) 
	Foo(const Foo& other){
	size = other.size;
	p = new int[size];

	for(int i = 0; i < size; i++)
		p[i] = other.p[i];
		
	}
	//copy assignment operator 
	// f = g;
	// f = g = h = i = j; 
	// j = j; 
	Foo& operator=(const Foo& other){
		if(this == &other)
			return *this;
		if(size >= other.size)
		{
			for(int i = 0; i < other.size; i++)
			p[i] = other.p[i];
		}
		else
		{
			for(int i = 0; i < size; i++)
			p[i] = other.p[i];
		}
		
		return *this;	
	}
	void print() const
	{
		for(int i = 0; i < size; i++)
			cout << p[i] << " ";
			cout << endl;
	}

};

int main(){

	Foo f(5, 9);
	f.print();
	// copy constructor 
	Foo g(f); 
	g.print();
	Foo h = g;
	h.print();
	Foo i(5, 1); 
	i.print(); 
	// copy assignment operator
	i=g;
	i.print();
}
