TITLE QUESTION 3(iv.b)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
x DWORD 2
n DWORD 4

.code
main PROC
mWrite "Enter value of x: "
call ReadDec
mov x, eax
mWrite "Enter value of n: "
call ReadDec
mov n, eax
call Crlf
push n
push x
call Power
mWrite "Nth power of x is: "
call WriteDec
call Crlf

exit
main ENDP

Power PROC
push ebp
mov ebp, esp
sub esp, 8
mov eax, [ebp + 12]
cmp eax, 0
jne L1
mov eax, 1
jmp ENDD
L1:
	mov edx, [ebp + 12]
	sub edx, 1
	mov eax, [ebp + 8]
	mov [esp + 4], edx
	mov [esp], eax
	call Power
	mov edx, 0
	mul DWORD PTR [esp]
ENDD:
	add esp, 8
	pop ebp
	ret
Power ENDP

END main