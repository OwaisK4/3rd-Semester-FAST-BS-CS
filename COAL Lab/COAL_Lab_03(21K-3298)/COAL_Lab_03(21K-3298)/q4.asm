TITLE Question 4
INCLUDE Irvine32.inc

.DATA
color BYTE "Orange", 0
varA WORD 12
varB WORD 2
varC WORD 13
varD WORD 8
varE WORD 14

.CODE
main PROC

mov ax, varA
mov bx, varB
mov cx, varC
mov dx, varD
mov si, varE
call DumpRegs ; display registers
mov edx,offset color
call writestring


exit
main ENDP
END main
