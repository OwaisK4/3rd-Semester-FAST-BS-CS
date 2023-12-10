TITLE Question 03
Include Irvine32.inc

.data
values DWORD 4 DUP(0)
msgEqual BYTE "The given four values are all equal.", 0
msgNotEqual BYTE "The given four values are not equal.", 0
msg BYTE "Enter value: ", 0

.code
main PROC
mov eax, 0
mov esi, 0
mov edx, OFFSET msg
mov ecx, LENGTHOF values
L1:
	call WriteString
	call ReadInt
	mov values[esi], eax
	add esi, TYPE values
	loop L1

mov esi, 0
mov ecx, 3
L2:
	mov eax, values[esi]
	cmp eax, values[esi + TYPE values]
	jne L3
	add esi, TYPE values
	loop L2
mov edx, OFFSET msgEqual
call WriteString
call Crlf
jmp ENDD

L3:
	mov edx, OFFSET msgNotEqual
	call WriteString
	call Crlf

ENDD:
exit
main ENDP
END main