TITLE Question 4(ii)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
X DWORD 0

.code
main PROC
mWrite "Enter value of X: "
call ReadInt
mov X, eax
mov ebx, X
mov ecx, X
mov edx, X
shl eax, 0
shl ebx, 1
shl ecx, 2
shl edx, 4
add eax, ebx
add eax, ecx
add eax, edx
call Crlf
mWrite "X multiplied by 23 is: "
call WriteInt
call Crlf

exit
main ENDP
END main