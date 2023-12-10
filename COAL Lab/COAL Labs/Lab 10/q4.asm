TITLE Question 4
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data

.code
main PROC
call LocalSquare
exit
main ENDP

LocalSquare PROC
ENTER 4, 0
mWrite "Enter value: "
call ReadInt
call Crlf
mWrite "Original value: "
call WriteInt
call Crlf
mov [ebp - 4], eax
imul eax, [ebp - 4]
mWrite "Squared value: "
call WriteDec
call Crlf

LEAVE
ret
LocalSquare ENDP

END main