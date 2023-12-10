TITLE QUESTION 3(v)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
n DWORD 1

.code
main PROC
mWrite "Enter value of n: "
call ReadDec
mov n, eax
call Crlf
push n
call Fibonacci
mWrite "Nth term of Fibonacci sequence is: "
call WriteDec
call Crlf

exit
main ENDP

Fibonacci PROC
push ebp
mov ebp, esp
push ebx
sub esp, 4
mov eax, [ebp + 8]
cmp eax, 0
jne NEXT
mov eax, 0
jmp ENDD
NEXT:
	cmp eax, 1
	jne L1
	mov eax, 1
	jmp ENDD
L1:
	mov eax, [ebp + 8]
	sub eax, 1
	mov [esp], eax
	call Fibonacci
	mov ebx, eax
	mov eax, [ebp + 8]
	sub eax, 2
	mov [esp], eax
	call Fibonacci
	add eax, ebx

ENDD:
	add esp, 4
	pop ebx
	pop ebp
	ret
Fibonacci ENDP

END main