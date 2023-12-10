TITLE Question 5
INCLUDE Irvine32.inc

.code
main PROC

mov eax, 0Ah
mov ebx, 65o
mov ecx, 73d
mov edx, 0
sub edx, eax
mov eax, edx

add eax, 1
add eax, ebx
;add eax, edx
sub eax, ecx
add eax, 0Ah
sub eax, ebx
add eax, ecx
mov edx, eax

call DumpRegs
exit
main ENDP
END main

;edx = ­-eax + 1 + ebx + edx – ecx + 0Ah - 65o + 73d