TITLE Question 02
Include Irvine32.inc

.data
intArr SWORD 0, 0, 0, 0, 1, 20, 35, -12, 66, 4, 0
message BYTE "The first non-zero value in given array is: ", 0

.code
main PROC
mov esi, OFFSET intArr
mov eax, 0
mov ecx, LENGTHOF intArr
L1:
	mov ax, SWORD PTR [esi]
	cmp ax, 0
	jg FOUND
	add esi, TYPE intArr
	loop L1
jmp ENDD

FOUND:
	mov edx, OFFSET message
	call WriteString
	call WriteInt
	call Crlf

ENDD:
exit
main ENDP
END main