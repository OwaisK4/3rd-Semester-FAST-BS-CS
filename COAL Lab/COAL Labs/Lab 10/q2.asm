TITLE Question 2
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
count DWORD 0
sum DWORD 0
value DWORD ?
divisor DWORD 10

.code
main PROC
call TakeInput
exit
main ENDP

TakeInput PROC
mWrite "Procedure: TakeInput"
call Crlf
mWrite "ESP = "
push eax
mov eax, esp
call WriteHex
call Crlf
call Crlf
pop eax
push ebp
mov ebp, esp
mWrite "Enter number to check for Armstrong: "
call ReadDec
mov value, eax
mov edx, 0
L1:
	mov edx, 0
	cmp eax, 0
	je L2
	add count, 1
	div divisor
	;mWrite "eax = "
	;call WriteDec
	;call Crlf
	;xchg eax, edx
	;mWrite "edx = "
	;call WriteDec
	;call Crlf
	;call Crlf
	;xchg eax, edx
	jmp L1
call Crlf
L2:
	mWrite "Count = "
	mov eax, count
	call WriteDec
	call Crlf
	call Crlf
	push value
	push count
	call Armstrong
	mov esp, ebp
	pop ebp
	ret
TakeInput ENDP

Armstrong PROC
call Crlf
mWrite "Procedure: Armstrong"
call Crlf
mWrite "ESP = "
push eax
mov eax, esp
call WriteHex
call Crlf
call Crlf
pop eax
push ebp
mov ebp, esp
mov ecx, [ebp + 8]
mov eax, [ebp + 12]
mov edx, 0
L3:
	mov edx, 0
	div divisor
	xchg eax, edx
	push ecx
	push edx
	push eax
	mov ebx, eax
	mov ecx, [ebp + 8]
	mov edx, 0
	mov eax, 1
	mWrite "Powers of "
	L4:
		mul ebx
		call WriteDec
		mWrite " "
		loop L4
	call Crlf
	add sum, eax
	pop eax
	pop edx
	pop ecx
	xchg eax, edx
	loop L3
mWrite "Sum = "
mov eax, sum
call WriteDec
call Crlf
call Crlf
push eax			; Calculated sum for Armstrong
push [ebp + 12]		; Original input value
call Display
mov esp, ebp
pop ebp
ret 8
Armstrong ENDP

Display PROC
call Crlf
mWrite "Procedure: Display"
call Crlf
mWrite "ESP = "
push eax
mov eax, esp
call WriteHex
call Crlf
call Crlf
pop eax
push ebp
mov ebp, esp
mov eax, [ebp + 8]
mov ebx, [ebp + 12]
cmp eax, ebx
jne NotArmstrong
mWrite "Given number is Armstrong Number."
call Crlf
jmp ENDD
NotArmstrong:
	mWrite "Given number is not Armstrong Number."
	call Crlf
ENDD:
mov esp, ebp
pop ebp
ret 8
Display ENDP

END main