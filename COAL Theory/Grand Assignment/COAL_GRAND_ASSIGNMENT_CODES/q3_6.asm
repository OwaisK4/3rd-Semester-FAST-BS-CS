TITLE QUESTION 3(vi)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
intArray DWORD 60, 4, 17, 45, 7, 69, 21, 33, 96, 81
count DWORD 10

.code
main PROC
mWrite "Array values: "
mov ecx, count
mov esi, OFFSET intArray
PRINT:
	mov eax, [esi]
	call WriteInt
	mWrite " "
	add esi, 4
	loop PRINT
call Crlf
call Crlf
mov ecx, count
mov esi, OFFSET intArray
call Exchange
mWrite "After Exchange Sort: "
mov ecx, count
mov esi, OFFSET intArray
PRINT2:
	mov eax, [esi]
	call WriteInt
	mWrite " "
	add esi, 4
	loop PRINT2
call Crlf
exit
main ENDP

Exchange PROC
mov eax, 0
mov ebx, 0
L1:
	cmp ecx, 1
	JBE END_LOOP1
	push ecx
	lea edi, [esi+4]
	L2:
		cmp ecx, 1
		JBE END_LOOP2
		mov eax, [esi]
		mov ebx, [edi]
		cmp eax, ebx
		JBE NotSwapped
		push edi
		push esi
		call SWAP
		pop esi
		pop edi
		NotSwapped:
			add edi, 4
			loop L2
	END_LOOP2:
		add esi, 4
		pop ecx
		loop L1
END_LOOP1:
	ret
Exchange ENDP

SWAP PROC
push ebp
mov ebp, esp
mov esi, [ebp + 8]
mov edi, [ebp + 12]
mov eax, [esi]
mov ebx, [edi]

xchg eax, ebx
mov [esi], al
mov [edi], bl
mov [ebp + 8], esi
mov [ebp + 12], edi

mov esp, ebp
pop ebp
ret
SWAP ENDP

END main