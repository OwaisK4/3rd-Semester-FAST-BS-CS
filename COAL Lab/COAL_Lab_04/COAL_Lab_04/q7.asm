TITLE Question 7
INCLUDE Irvine32.inc

.data
arrayB BYTE 60, 70, 80
arrayW WORD 150, 250, 350
arrayD DWORD 600, 1200, 1800

.code
main PROC
movzx eax, arrayB
add al, arrayB[2 * TYPE BYTE]

movzx ebx, arrayW
add bx, arrayW[2 * TYPE WORD]

mov ecx, arrayD
add ecx, arrayD[2 * TYPE DWORD]

call DumpRegs
exit
main ENDP
END main