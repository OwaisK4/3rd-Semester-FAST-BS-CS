TITLE Question 3
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
intArray BYTE 60, 4, 17, 45, 7, 69, 21, 33, 96, 81
count DWORD 10

.code
main PROC
mWrite "Enter 10 single-digit integer values:"
call Crlf
mov esi, OFFSET intArray
mov ecx, count
mov ebx, 0
INPUT:
	mWrite "Enter single-digit integer "
	mov eax, ebx
	call WriteDec
	mWrite ": "
	call ReadDec
	cmp eax, 10
	jl GOOD_INPUT
	mWrite "Invalid number of digits. Try Again."
	call Crlf
	jmp INPUT
	GOOD_INPUT:
		mov [esi], al
		add esi, 1
		add ebx, 1
		loop INPUT
mWrite "Array values: "
mov eax, 0
mov ecx, count
mov esi, OFFSET intArray
PRINT:
	mov al, [esi]
	call WriteInt
	mWrite " "
	add esi, 1
	loop PRINT
call Crlf
call Crlf
mov ebx, count
mov esi, OFFSET intArray
call Bubble
mWrite "After Bubble: "
mov ecx, count
mov esi, OFFSET intArray
PRINT2:
	mov al, [esi]
	call WriteInt
	mWrite " "
	add esi, 1
	loop PRINT2
call Crlf
exit
main ENDP

Bubble PROC
mov ecx, ebx
mov eax, 0
mov ebx, 0
L1:
	push ecx
	push esi
	L2:
		cmp ecx, 1
		JBE END_LOOP2
		mov edi, esi
		add edi, 1
		mov al, [esi]
		mov bl, [edi]
		cmp al, bl
		JBE NotSwapped
		push edi
		push esi
		call SWAP
		pop esi
		pop edi
		NotSwapped:
			add esi, 1
			add edi, 1
			loop L2
	END_LOOP2:
		pop esi
		pop ecx
		loop L1
ret
Bubble ENDP

SWAP PROC
push ebp
mov ebp, esp
mov esi, [ebp + 8]
mov edi, [ebp + 12]
mov al, [esi]
mov bl, [edi]

xchg al, bl
mov [esi], al
mov [edi], bl
mov [ebp + 8], esi
mov [ebp + 12], edi

mov esp, ebp
pop ebp
ret
SWAP ENDP

END main