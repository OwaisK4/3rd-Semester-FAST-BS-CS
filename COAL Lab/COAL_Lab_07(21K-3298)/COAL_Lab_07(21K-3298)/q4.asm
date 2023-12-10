TITLE Question 04
Include Irvine32.inc

.data
arr WORD 10, 4, 7, 14, 299, 156, 3, 19, 29, 300, 20
msg BYTE "Enter key to search for: ", 0
msg2 BYTE "Key found: ", 0
msg3 BYTE "Key not found.", 0
msg4 BYTE " at index: ", 0

.code
main PROC

mov eax, 0
mov edx, OFFSET msg
call WriteString
call ReadInt
movzx ebx, ax

mov esi, 0
mov ecx, LENGTHOF arr
L1:
	mov ax, arr[esi * TYPE arr]
	cmp ax, bx
	je FOUND
	inc esi
	loop L1

mov edx, OFFSET msg3
call WriteString
call Crlf
jmp ENDD


FOUND:
	mov edx, OFFSET msg2
	call WriteString
	call WriteInt
	mov edx, OFFSET msg4
	call WriteString
	mov eax, esi
	call WriteDec
	call Crlf

ENDD:
exit
main ENDP
END main