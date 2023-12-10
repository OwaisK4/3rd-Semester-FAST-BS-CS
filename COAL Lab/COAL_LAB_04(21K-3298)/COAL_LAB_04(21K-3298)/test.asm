INCLUDE Irvine32.inc

.data
val BYTE 10, 20, 30, 40, 50

.code
main PROC
mov eax, 0
mov al, LENGTHOF val
call DumpRegs

exit
main ENDP
END main