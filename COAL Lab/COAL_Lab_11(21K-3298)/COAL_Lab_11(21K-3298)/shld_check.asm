TITLE SHLD_CHECK
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data

.code
main PROC
mov eax, 0FFh
mov edx, 0EEh
call DumpRegs
shld eax, edx
call DumpRegs

exit
main ENDP
END main