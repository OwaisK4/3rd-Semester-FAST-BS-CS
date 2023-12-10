// COAL_Lab_12(21K-XXXX).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
// extern "C" instruct the compiler to use C calling conventions
extern "C" void clear();
int main() {
    clear();
    // define variables
    unsigned short src_opnd, dst_opnd, src_rslt, dst_rslt;
    printf("Enter two 4-digit hex numbers - src, dst: \n");
    scanf_s("%hX %hX", &src_opnd, &dst_opnd); // in scanf_s it is necessary to
    // specifiy length
    // switch to assembly
    _asm {
		MOV AX, src_opnd
		MOV BX, dst_opnd
		SHRD BX, AX, 10; shift AX : BX right 10 bits
		MOV src_rslt, AX
		MOV dst_rslt, BX
    }
    printf("\nSource result = %X\n Destination result = %X\n\n", src_rslt, dst_rslt);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file