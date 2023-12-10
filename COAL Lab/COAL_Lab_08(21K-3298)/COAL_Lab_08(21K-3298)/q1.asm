TITLE Question 1
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
source WORD 0,1,2,3,4,5,6,7,8,9
target WORD 10 DUP(0)

.code
main PROC
mov eax, 0
mov esi, 0
mov ecx, LENGTHOF source
mWrite "Source array: "
L1:
	mov ax, source[esi]
	push ax
	call WriteDec
	mWrite " "
	add esi, TYPE source
	loop L1

mov esi, 0
mov ecx, LENGTHOF target
call Crlf
mWrite "Target array: "
L2:
	pop ax
	mov target[esi], ax
	call WriteDec
	mWrite " "
	add esi, TYPE source
	loop L2
call Crlf

exit
main ENDP
END main