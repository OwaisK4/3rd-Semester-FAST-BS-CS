TITLE Question 9
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data

.code
main PROC
push 20
push 5
call GCD
mov eax, ecx
mWrite "The GCD of 5 and 20 is: "
call WriteDec
call Crlf

push 18
push 24
call GCD
mov eax, ecx
mWrite "The GCD of 24 and 18 is: "
call WriteDec
call Crlf

push 226
push 432
call GCD
mov eax, ecx
mWrite "The GCD of 432 and 226 is: "
call WriteDec
call Crlf

exit
main ENDP

GCD PROC ; Stores values of A and B in eax and ebx respectively. Returns answer in ecx
push ebp
mov ebp, esp
mov eax, [ebp + 8]
mov ebx, [ebp + 12]
CASE_A:
	cmp eax, 0
	JNE CASE_B
	mov ecx, ebx
	mov esp, ebp
	pop ebp
	ret 8
CASE_B:
	cmp ebx, 0
	JNE CASE_A_EQUALS_B
	mov ecx, eax
	mov esp, ebp
	pop ebp
	ret 8
CASE_A_EQUALS_B:
	cmp eax, ebx
	JNE CASE_A_GREATER_THAN_B
	mov ecx, eax
	mov esp, ebp
	pop ebp
	ret 8
CASE_A_GREATER_THAN_B:
	cmp eax, ebx
	JBE CASE_A_LESS_THAN_B
	sub eax, ebx
	push ebx
	push eax
	call GCD
	jmp ENDD
CASE_A_LESS_THAN_B:
	sub ebx, eax
	push ebx
	push eax
	call GCD
ENDD:
mov esp, ebp
pop ebp
ret 8
GCD ENDP
END main