TITLE QUESTION 3(i)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
OP1 SDWORD ?
OP2 SDWORD ?
OP3 SDWORD ?
X DWORD 0
Y DWORD 0
VAL1 SDWORD ?
VAL2 SDWORD ?
VAL3 SDWORD ?

.code
main PROC
WHILE:
	mov eax, OP1
	cmp eax, OP2
	jge END_WHILE
	mov eax, OP3
	cmp eax, OP2
	jne ELSE
	mov ebx, Y
	add ebx, 2
	mov X, ebx
	ELSE:
		mov ebx, Y
		add ebx, 10
		mov X, ebx
	jmp WHILE

exit
main ENDP

main PROC
mov eax, VAL1
mov ebx, VAL2
mov ecx, VAL3
cmp eax, ebx
jle ENDD
cmp ebx, ecx
jle ENDD
mov x, 10
ENDD:
	mov x, 20
exit
main ENDP
END main