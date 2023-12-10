TITLE Question 05
Include Irvine32.inc

.data
array DWORD 10, 4, 7, 14, 50
space DWORD " "
swapCount DWORD 0
msg BYTE "Total number of swaps: ", 0

.code
main PROC
mov eax, 0
mov esi, 0
mov ecx, LENGTHOF array
PRINT:
	mov eax, array[esi]
	call WriteDec
	mov eax, space
	call WriteChar
	add esi, TYPE array
	loop PRINT
call Crlf

mov esi, 0
mov ecx, (LENGTHOF array - 1)
L1:
	mov eax, array[esi]
	cmp eax, array[esi + TYPE array]
	jg SWAP
	jmp endd
	SWAP:
		xchg eax, array[esi + TYPE array]
		inc swapCount
	ENDD:
		add esi, TYPE array
	loop L1

mov edx, OFFSET msg
call WriteString
mov eax, swapCount
call WriteDec
exit
main ENDP
END main