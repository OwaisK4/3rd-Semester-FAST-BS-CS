TITLE Add and Subtract (AddSub.asm)
; This program adds and subtracts 32-bit integers.
INCLUDE Irvine32.inc

.DATA
a BYTE 0
b BYTE 'A'
c1 SBYTE -7


.CODE
main PROC
mov eax,10000h ; EAX = 10000h
sub eax,2000h ; EAX = 30000h
call DumpRegs ; display registers
exit

main ENDP
END main