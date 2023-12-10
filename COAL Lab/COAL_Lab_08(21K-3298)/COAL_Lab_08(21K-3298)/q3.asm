TITLE Question 3
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
columns DWORD 5

.code
main PROC
mWrite "Enter number of columns: "
call ReadDec
mov columns, eax
call Pattern
exit
main ENDP

Pattern PROC ; takes argument from variable "columns"
mov eax, 0
mov esi, 1
mov ecx, columns
L1:
	push ecx
	L2:
		mWrite " "
		loop L2
	mov ecx, esi
	L3:
		mWrite "*"
		loop L3
	add esi, 1
	pop ecx
	call Crlf
	loop L1
ret
Pattern ENDP

END main