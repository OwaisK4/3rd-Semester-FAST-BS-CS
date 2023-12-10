TITLE Question 1
; This program adds and subtracts 32-bit integers.
INCLUDE Irvine32.inc

.DATA
val1 SWORD ?
val2 SBYTE -10

.CODE
main PROC
mov ax, val1
mov bl, val2

call DumpRegs ; display registers
exit

main ENDP
END main