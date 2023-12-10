#include <iostream>
using namespace std;
class point 
{ 
	public:
		point ();
		~point ();
		point& operator= (const point& rhs); 
		void SetPoint (const int _x, const int _y);
		void PrintPoint(); 
	private:
		int* x; int* y;
		
};
point::point() 
{
		this->x = new int;
		*(this->x) = 0;
		this->y = new int; 
		*(this->y) = 0;
		return;
}
point& point::operator=(const point& rhs){
	cout << "Copy assignment op called." << endl; 
	(*this->x) = (*rhs.x); 
	(*this->y) = (*rhs.y); 
	 return *this;
}

void point::SetPoint (const int _x, const int _y){
	*(this->x) = _x; 
	*(this->y) = _y; 
	return;
}

void point::PrintPoint() 
{ 
	cout << " " << *(this->x);
	cout << ", " <<*(this->y);
	cout << ")" << endl; 
	return;
}
point::~point() 
{ 
	if(this->x != 0 ) 
	{
		delete this->x;
	}
	if( this->y != 0 ) 
	{
		delete this->y;
	}
	return;
}

int main() {
	point pi, p2;
	pi.SetPoint(1,2); 
	p2 = pi;
	pi.SetPoint (4,4);
	pi.PrintPoint(); 
	p2.PrintPoint();
return 0;
}

