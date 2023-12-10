TITLE Question 6
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
numbers DWORD 0,0,0,0
count = ($ - numbers) / TYPE numbers

.code
main PROC
mov eax, 0
mov esi, 0
mov ecx, count
INPUT:
	mWrite "Enter number: "
	call ReadDec
	mov numbers[esi], eax
	add esi, TYPE numbers
	loop INPUT
push DWORD PTR [numbers]
call CheckPrime
jnc NotPrime
push DWORD PTR [numbers + 4]
call CheckPrime
jnc NotPrime
push DWORD PTR [numbers + 8]
call CheckPrime
jnc NotPrime
push DWORD PTR [numbers + 12]
call CheckPrime
jnc NotPrime

call Crlf
mWrite "All numbers are prime."
call Crlf
push OFFSET numbers
call LargestPrime
jmp ENDD

NotPRIME:
	call Crlf
	mWrite "All numbers are not prime."
ENDD:
	call Crlf
	exit
main ENDP

CheckPrime PROC ; Returns bool value in Carry Flag (1 for prime, 0 for non-prime)
push ebp
mov ebp, esp
mov eax, [ebp + 8]
cmp eax, 2
jl PRIME_FALSE
mov ecx, eax
sub ecx, 1
Check:
	push eax
	mov edx, 0
	cmp ecx, 1
	jle PRIME_TRUE
	div ecx
	cmp edx, 0
	je PRIME_FALSE
	pop eax
	loop Check
PRIME_FALSE:
	clc
	pushfd
	jmp ENDD
	
PRIME_TRUE:
	stc
	pushfd

ENDD:
	popfd
	mov esp, ebp
	pop ebp
	ret 4
CheckPrime ENDP

LargestPrime PROC
push ebp
mov ebp, esp
mov esi, [ebp + 8]
mov eax, [esi]
mov ecx, count - 1
Iterate:
	add esi, 4
	cmp eax, [esi]
	jge CONTINUE
	mov eax, [esi]
	CONTINUE:
		loop Iterate
mWrite "Largest prime is: "
call WriteDec
mov esp, ebp
pop ebp
ret 4
LargestPrime ENDP

END main