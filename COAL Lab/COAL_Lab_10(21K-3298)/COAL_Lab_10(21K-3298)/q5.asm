TITLE Question 5
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
n DWORD ?

.code
main PROC
mWrite "Enter number to calculate factorial: "
AGAIN:
	call ReadInt
cmp eax, 0
jg CONTINUE
mWrite "Enter number greater than 0: "
jmp AGAIN
CONTINUE:
	call Crlf
	mWrite "Original = "
	call WriteDec
	call Crlf
	mov n, eax
	call Fact
	mov eax, n
	mWrite "Factorial = "
	call WriteDec
	call Crlf
exit
main ENDP

Fact PROC
push ebp
mov ebp, esp

cmp eax, 1
jg RECURSE
mov esp, ebp
pop ebp
ret

RECURSE:
	mov edx, 0
	dec eax
	push eax
	call Fact
	mov eax, n
	pop ebx
	mul ebx
	mov n, eax

mov esp, ebp
pop ebp
ret
Fact ENDP

END main