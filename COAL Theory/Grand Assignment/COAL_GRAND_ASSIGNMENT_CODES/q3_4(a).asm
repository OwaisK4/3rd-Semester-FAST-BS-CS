TITLE QUESTION 3(iv)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
n DWORD 5
k DWORD 2

.code
main PROC
mWrite "Enter value of n: "
call ReadDec
mov n, eax
mWrite "Enter value of k: "
call ReadDec
mov k, eax
call Crlf
push k
push n
call Binomial
mWrite "Binomial coefficient is: "
call WriteDec
call Crlf

exit
main ENDP

Binomial PROC
push ebp
mov	ebp, esp
push ebx
sub	esp, 8
mov	eax, DWORD PTR [ebp+12]
cmp	eax, DWORD PTR [ebp+8]
jle	L2
mov	eax, 0
jmp	L3
L2:
	cmp	DWORD PTR [ebp+12], 0
	je	L4
	mov	eax, DWORD PTR [ebp+12]
	cmp	eax, DWORD PTR [ebp+8]
	jne	L5
L4:
	mov	eax, 1
	jmp	L3
L5:
	mov edx, DWORD PTR [ebp+12]
	sub edx, 1
	mov	eax, DWORD PTR [ebp+8]
	sub	eax, 1
	mov	DWORD PTR [esp+4], edx
	mov	DWORD PTR [esp], eax
	call Binomial
	mov	ebx, eax
	mov edx, DWORD PTR [ebp+8]
	sub edx, 1
	mov	eax, DWORD PTR [ebp+12]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], edx
	call Binomial
	add	eax, ebx
L3:
	add	esp, 8
	pop	ebx
	pop	ebp
	ret

Binomial ENDP

END main