TITLE Question 01
Include Irvine32.inc

.data
var DWORD ?

.code
main PROC
mov var, 5
mov ecx, 4
cmp var, ecx
jl IFF
mov var, 1
jmp ENDIFF
IFF:
	mov var, 0
ENDIFF:
	mov eax, var
	call DumpRegs

exit
main ENDP
END main