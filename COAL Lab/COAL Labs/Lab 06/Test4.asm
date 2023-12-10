INCLUDE Irvine32.inc

.data
var1 DWORD 5
var2 DWORD 6

.code
main PROC
call AddTwo
call writeint
call crlf
exit
main ENDP
AddTwo PROC
mov eax, var1
mov ebx, var2
add eax, var2
ret
AddTwo ENDP
END main