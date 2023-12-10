TITLE Question 4
INCLUDE Irvine32.inc

.DATA
varA DWORD 10h
varB DWORD 15h
varC DWORD 20h
varD DWORD 30h

.CODE
main PROC

mov eax, varA
mov ebx, varA
mov ecx, varC
mov edx, varD

add eax, varB
sub ebx, varB
sub eax, ebx
add eax, ecx
add eax, edx
mov ebx, eax

call DumpRegs ; display registers

exit
main ENDP
END main


;ebx = { (a+b) – (a-b) + c } +d