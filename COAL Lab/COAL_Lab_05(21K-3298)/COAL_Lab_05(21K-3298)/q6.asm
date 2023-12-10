TITLE Question 3
INCLUDE Irvine32.inc

.data
array DWORD 0,1,2,3,4,5,6,7,8,9

.code
main PROC
mov eax, 0
mov esi, 0
mov ecx, LENGTHOF array
PRINT1:
	mov eax, array[esi]
	call writeDec
	add esi, TYPE array
	loop PRINT1
call Crlf

mov esi, 0
mov edi, SIZEOF array - 4
mov ecx, LENGTHOF array / 2
Reverse:
	mov eax, array[esi]
	xchg eax, array[edi]
	mov array[esi], eax
	add esi, TYPE array
	sub edi, TYPE array
	cmp esi, edi
	jge ENDD
	loop Reverse

ENDD:
mov eax, 0
mov esi, 0
mov ecx, LENGTHOF array
PRINT2:
	mov eax, array[esi]
	call writeDec
	add esi, TYPE array
	loop PRINT2
call Crlf
exit
main ENDP
END main