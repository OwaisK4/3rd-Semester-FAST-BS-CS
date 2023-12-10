TITLE Question 2
INCLUDE Irvine32.inc

.DATA
val1 SDWORD -2147483648

.CODE
main PROC
mov eax, val1

call DumpRegs ; display registers
exit

main ENDP
END main