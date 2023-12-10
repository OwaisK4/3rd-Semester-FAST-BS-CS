Include Irvine32.inc

.data
msg byte "Generating 20 random numbers between 0 and 990:", 0

.code
main PROC
call Clrscr
call Randomize
mov edx, offset msg
call WriteString
call Crlf

mov dh, 1 ; row 1
mov dl, 0
mov ecx, 20
L1:
	mov eax, 990
	call RandomRange
	call GotoXY
	call writeDec
	add dh, 1
	add dl, 2
	mov eax, 50
	call Delay
	loop L1
exit
main ENDP
END main