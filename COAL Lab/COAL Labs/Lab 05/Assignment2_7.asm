TITLE Question 7
INCLUDE Irvine32.inc

.data
loopCounter DWORD 8
msg BYTE "Enter number: ", 0

.code
main PROC
mov edx, OFFSET msg
call WriteString
call ReadInt
mov loopCounter, eax

call Crlf
mov ecx, loopCounter
L6:
	push ecx
	mov eax, loopCounter
	L7:
		call writeDec
		dec eax
		loop L7
	call Crlf
	pop ecx
	loop L6

exit
main ENDP
END main