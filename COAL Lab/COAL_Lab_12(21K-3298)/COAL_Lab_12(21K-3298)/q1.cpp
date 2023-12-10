#include <iostream>

//extern "C" void clear();
extern "C" int ThreeProd(int a, int b, int c);

int main() {
	int a, b, c, prod;
	std::cout << "Enter three integers: ";
	std::cin >> a >> b >> c;
	int product = ThreeProd(a, b, c);
	/*
	_asm {
		mov eax, a
		mul b
		mul c
		mov prod, eax
	}
	*/
	//std::cout << "Product is: " << prod << "\n";
	std::cout << "Product is: " << product << "\n";
	return 0;
}