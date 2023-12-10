Include Irvine32.inc

.code
main PROC
call Clrscr
mov dh, 24
mov dl, 79 ; bottom-right corner
call Gotoxy ; Move cursor there
mov al, '*'
call WriteChar ; Write '*' in bottom right
mov dh, 10
mov dl, 10
call Gotoxy
call WriteChar ; Output the character entered at 10,10
call CrLf ; Carriage return to line 11
call DumpRegs ; Output registers

; output a row of '&'s to the screen, minus first column
mov al, '&';
mov ecx, 79
mov dh, 5 ; row 5
L1:
	mov dl, cl
	call Gotoxy
	call WriteChar
	loop L1
call CrLf
exit
main ENDP
END main