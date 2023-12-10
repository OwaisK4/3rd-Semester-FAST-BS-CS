TITLE Question 4
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
N DWORD 5

.code
main PROC
mWrite "Enter a positive integer: "
call ReadDec
mov N, eax
call Crlf

mWrite "N = "
mov eax, N
call WriteDec
call Crlf
mov ecx, N
call FACTORIAL
mWrite "Factorial of N = "
call WriteDec
call Crlf
exit
main ENDP

FACTORIAL PROC		; receives N in ecx and returns N! in eax
mov eax, 1
mov edx, 0
cmp ecx, 0
JBE END_LOOP
L1:	
	mov edx, 0
	mul ecx
	loop L1
END_LOOP:
	ret
FACTORIAL ENDP

END main