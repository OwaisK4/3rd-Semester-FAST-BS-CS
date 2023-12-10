TITLE Question 1
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data

.code
main PROC
mov eax, 0
mWrite "Enter value to be multiplied by 21: "
call ReadInt
mov ebx, eax
mov ecx, eax
shl eax, 4
shl ebx, 2
shl ecx, 0
add eax, ebx
add eax, ecx
mWrite "Answer: "
call WriteInt
call Crlf

exit
main ENDP
END main