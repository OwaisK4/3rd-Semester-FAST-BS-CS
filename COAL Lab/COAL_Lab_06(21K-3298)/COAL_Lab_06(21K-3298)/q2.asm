Include Irvine32.inc

.data
char BYTE '*'
timingDelay DWORD 100
loopCount DWORD 100

.code
main PROC
call Randomize

mov eax, 0
mov edx, 0
call GetMaxXY
and eax, 000000FFh
mov dh, al
;call writeDec
;call Crlf
;movzx eax, dl
;call writeDec
sub dh, 11
sub dl, 1

mov ecx, loopCount
L1:
	push dx
	movzx eax, dh
	call RandomRange
	mov dh, al

	movzx eax, dl
	call RandomRange
	mov dl, al

	call GotoXY
	movzx eax, char
	call writeChar
	mov eax, timingDelay
	call Delay
	pop dx
	loop L1

exit
main ENDP
END main