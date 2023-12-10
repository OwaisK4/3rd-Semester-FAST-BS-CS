TITLE Question 4
INCLUDE Irvine32.inc
INCLUDE Macros.inc

AddNum PROTO, n1:BYTE, n2:BYTE

.data
num1 BYTE 10
num2 BYTE 20

.code
main PROC
INVOKE AddNum, num1, num2

exit
main ENDP

AddNum PROC, n1:BYTE, n2:BYTE
;enter 0,0
mov eax, 0
mov al, n1
add al, n2
call WriteDec
;leave
ret
AddNum ENDP

END main