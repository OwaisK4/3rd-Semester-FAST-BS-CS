Include Irvine32.inc

.data
msg_1 BYTE "Generating 10 random unsigned numbers (0 to 4,294,967,294):", 0
msg_2 BYTE "Generating 10 random signed numbers: (-50 to +49)", 0
space DWORD " "
startRange = -50
endRange = +49

.code
main PROC
call Randomize
mov edx, OFFSET msg_1
call WriteString
call Crlf

mov ecx, 10
L1:
	call Random32
	call WriteDec
	mov eax, space
	call WriteChar
	loop L1

call Crlf
call Crlf
mov edx, OFFSET msg_2
call WriteString
call Crlf

mov eax, startRange
neg eax
add eax, endRange
mov ecx, 10
L2:
	push eax
	call RandomRange
	add eax, startRange
	call WriteInt
	mov eax, space
	call WriteChar
	pop eax
	loop L2

exit
main ENDP
END main