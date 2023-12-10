#include <iostream>

int main() {
	int num1, num2, gcd = 1;
	std::cout << "Enter two numbers: ";
	std::cin >> num1 >> num2;

	_asm {
		mov ecx, 1		// Iterator variable
		GCD:
			cmp ecx, num1
			jg ENDD
			cmp ecx, num2
			jg ENDD
			mov edx, 0
			mov eax, num1
			div ecx
			cmp edx, 0
			jne LOOP_GCD
			mov edx, 0
			mov eax, num2
			div ecx
			cmp edx, 0
			jne LOOP_GCD
			mov gcd, ecx
			LOOP_GCD:
				add ecx, 1
				jmp GCD				
		ENDD:
	}
	std::cout << "GCD is: " << gcd << "\n";

	return 0;
}