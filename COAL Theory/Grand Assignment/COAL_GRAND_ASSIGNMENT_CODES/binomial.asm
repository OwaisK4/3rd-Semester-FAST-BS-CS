TITLE BINOMIAL_COEFFICIENTS
INCLUDE Irvine32.inc
INCLUDE Macros.inc

Binomial PROTO, n:DWORD, k:DWORD

.data
nn DWORD 5
kk DWORD 0

.code
main PROC
mWrite "Binomial coefficents of 5: "
mov ecx, 6
L1:
	mov eax, 0
	INVOKE Binomial, nn, kk
	call WriteDec
	mWrite " "
	inc kk
	loop L1
exit
main ENDP

Binomial PROC, n:DWORD, k:DWORD
mov ebx, k
cmp n, ebx
JL ZERO
JE ONE
cmp k, 0
JE ONE

dec n
INVOKE Binomial, n, k
dec k
INVOKE Binomial, n, k
ret

ZERO:
	mov ebx, 0
	jmp BASE
ONE:
	mov ebx, 1
	jmp BASE
BASE:
	add eax, ebx
	ret
Binomial ENDP
END main