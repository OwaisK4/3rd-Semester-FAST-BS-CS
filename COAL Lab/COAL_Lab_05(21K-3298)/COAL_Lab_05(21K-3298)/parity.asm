INCLUDE Irvine32.inc

.data
val BYTE 01110101b
MSG1 BYTE "Even Parity!",0
MSG2 BYTE "Odd Parity!",0

.code
main PROC
mov eax, 0
mov al, val
call Dumpregs
exit
main ENDP
END main