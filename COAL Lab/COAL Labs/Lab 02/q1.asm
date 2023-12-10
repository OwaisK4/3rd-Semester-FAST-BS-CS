TITLE Question 1
INCLUDE Irvine32.inc

.DATA
A1 equ 47d
A2 equ 39d
A3 equ 60d
A4 equ 85d
A5 equ 64d
A6 equ 54o
A7 equ 0Ah

.CODE
main PROC
mov eax, A1
add eax, A2
add eax, A3
add eax, A4
add eax, A5
add eax, A6
sub eax, A7
call DumpRegs
exit
main ENDP
END main

;47 + 39 + 60 + 85 + 64 + 54o - 0Ah