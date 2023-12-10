TITLE Question 2
INCLUDE Irvine32.inc

.data

.code
main PROC
mov eax, 0
mov ax, -128
call WriteInt
call Crlf
sal eax, 16
sar eax, 16
call WriteInt

exit
main ENDP
END main