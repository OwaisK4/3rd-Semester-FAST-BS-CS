TITLE Question 1
INCLUDE Irvine32.inc

.data
val1 SDWORD 8000h

.code
main PROC
mov eax, val1
add eax, 1
call DumpRegs

exit
main ENDP
END main