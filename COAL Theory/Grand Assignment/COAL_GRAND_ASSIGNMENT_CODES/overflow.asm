TITLE FIBONACCI
INCLUDE Irvine32.inc
INCLUDE Macros.inc

Factorial PROTO, X:DWORD

.data
n DWORD 1

.code
main PROC
mov eax, 0
;mov al, 10111111b
;add al, 10101010b
mov al, 10111111b
add al, 10001010b
call DumpRegs
exit
main ENDP

END main