TITLE Question 2
INCLUDE Irvine32.inc

.DATA
A1 equ 30
A2 equ 9
A3 equ 186
A4 equ 150

.CODE
main PROC
mov eax, A1
sub eax, A2
add eax, A3
sub eax, A4
call DumpRegs
exit

main ENDP
END main