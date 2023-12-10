TITLE Question 3
INCLUDE Irvine32.inc

.data
loopCounter DWORD 4

.code
main PROC
mov eax, 1
mov ecx, loopCounter
L1:
	mov edx, ecx
	mov ecx, loopCounter
	sub ecx, edx
	add ecx, 1
	L2:
		call writeDec
		loop L2
	mov ecx, edx
	call Crlf
	loop L1

call Crlf
mov ecx, loopCounter
L4:
	mov edx, ecx
	L5:
		call writeDec
		loop L5
	call Crlf
	mov ecx, edx
	loop L4

call Crlf
mov ecx, loopCounter
L6:
	mov edx, ecx
	mov eax, 4
	L7:
		call writeDec
		dec eax
		loop L7
	call Crlf
	mov ecx, edx
	loop L6

call Crlf
mov ecx, loopCounter
L8:
	mov edx, ecx
	mov eax, 1
	L9:
		call writeDec
		inc eax
		loop L9
	call Crlf
	mov ecx, edx
	loop L8

exit
main ENDP
END main