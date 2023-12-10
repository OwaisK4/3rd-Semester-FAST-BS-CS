TITLE Question 5
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
val1 SDWORD 100
val2 SDWORD 10
val3 SDWORD 5

.code
main PROC
mov eax, val2
cdq
idiv val3
mov ebx, eax
call WriteInt
call Crlf

mov eax, val1
cdq
idiv val2
call WriteInt
call Crlf
call Crlf

imul ebx
xchg eax, edx
mWrite "EDX: "
call WriteInt
xchg eax, edx
mWrite " EAX: "
call WriteInt
call Crlf

exit
main ENDP
END main