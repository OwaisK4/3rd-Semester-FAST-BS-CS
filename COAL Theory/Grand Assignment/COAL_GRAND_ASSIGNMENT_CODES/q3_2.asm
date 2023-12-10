TITLE QUESTION 3(ii)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
X DWORD 21
Y DWORD 33
Z DWORD 61

.code
main PROC
mov eax, X
mov ebx, Y
mov ecx, Z
call MINIMUM
mWrite "Minimum value is: "
call WriteDec
call Crlf
exit
main ENDP

MINIMUM PROC ; takes arguments in eax, ebx and ecx. Returns minimum value in eax.
cmp eax, ebx
jle NEXT
mov eax, ebx
NEXT:
	cmp eax, ecx
	jle ENDD
	mov eax, ecx
ENDD:
	ret
MINIMUM ENDP

END main