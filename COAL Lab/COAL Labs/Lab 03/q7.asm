TITLE Question 7
INCLUDE Irvine32.inc

.DATA
Imm8 equ 20
data1 WORD 8
data2 WORD 15
data3 WORD 20

.CODE
main PROC
mov eax, 0
add al, imm8
add ax, data1
sub ax, data3
add al, imm8
add ax, data2


call DumpRegs ; display registers

exit
main ENDP
END main

;Eax = imm8 + data1 – data3 + imm8 + data2