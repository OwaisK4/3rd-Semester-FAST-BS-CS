.686 ;Target processor. Use instructions for Pentium class machines
.MODEL FLAT, C ;Use the flat memory model. Use C calling conventions
.STACK 2048 ;Define a stack segment of 1KB (Not required for this example)
.DATA ;Create a near data segment. Local variables are declared after

;this directive (Not required for this example)

var_1 dword 10
str_1 byte 50,100,34,5,6,78,12,45,67
str_2 byte 5000 dup(?)

.CODE ;Indicates the start of a code segment.
clear PROC
xor eax, eax
xor ebx, ebx
ret
clear ENDP

ThreeProd PROC C, num1:DWORD, num2:DWORD, num3:DWORD
mov eax, num1
mul num2
mul num3

ret
ThreeProd ENDP
END