TITLE Question 5
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
n DWORD ?

.code
main PROC
mWrite "Enter value of n: "
call ReadDec
mov n, eax
call Sum
mWrite "Sum of integers from 1 to n is: "
call WriteDec
call Crlf
exit
main ENDP

Sum PROC ; takes argument from variable "n" and returns value in eax
mov eax, 0
mov ecx, n
L1:
	add eax, ecx
	loop L1
ret
Sum ENDP

END main