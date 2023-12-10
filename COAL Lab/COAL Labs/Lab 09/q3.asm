TITLE Question 3
INCLUDE Irvine32.inc

.data
timeStamp WORD 1110001110000111b ; Minutes = 011100 = +28
bMinutes BYTE ?

.code
main PROC
mov eax, 0
mov ax, timeStamp
shr eax, 5
AND al, 00111111b
mov bMinutes, al
movzx eax, bMinutes
call WriteInt
call Crlf
call WriteBin

exit
main ENDP
END main