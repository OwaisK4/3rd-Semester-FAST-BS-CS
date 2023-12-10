TITLE Question 4
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
character BYTE "A",0
columns DWORD 5

.code
main PROC
mWrite "Enter number of columns: "
call ReadDec
mov columns, eax
call Pattern
exit
main ENDP

Pattern PROC ; takes argument from variable "columns" and "character"
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
		mov edx, OFFSET character
		call WriteString
		inc character
		loop L3
	add esi, 1
	pop ecx
	call Crlf
	loop L1
ret
Pattern ENDP

END main