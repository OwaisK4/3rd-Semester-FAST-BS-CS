TITLE FIBONACCI
INCLUDE Irvine32.inc
INCLUDE Macros.inc

Fibonacci PROTO, X:DWORD

.data
n DWORD 1

.code
main PROC
mWrite "Enter value of n: "
call ReadDec
;mov n, eax
mov ecx, eax
call Crlf
mWrite "N terms of Fibonacci sequence is: "
L1:
	mov eax, 0
	INVOKE Fibonacci, n
	;mWrite "Nth term of Fibonacci sequence is: "
	call WriteDec
	mWrite " "
	inc n
	loop L1
call Crlf

exit
main ENDP

Fibonacci PROC, X:DWORD
cmp X, 0
JE BASE
cmp X, 1
JE BASE
dec X
INVOKE FIBONACCI, X
dec X
INVOKE FIBONACCI, X
ret
BASE:
	add eax, X
	ret
Fibonacci ENDP

END main