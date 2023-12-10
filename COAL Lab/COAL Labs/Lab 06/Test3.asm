Include Irvine32.inc

.data
msg byte "Generating 50 random numbers:",0

.code
main PROC
mov edx,offset msg
call WriteString
call Crlf
mov ecx,50
L1:
	mov eax, 99
	call RandomRange
	sub eax, 50
	js invert
continue:
	call writeDec
	call Crlf
	loop L1
exit

invert:
	neg eax
	push eax
	mov al, '-'
	call WriteChar
	pop eax
	jmp continue

main ENDP
END main