TITLE Question 3(vii)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
intArray DWORD 60, 4, 17, 45, 7
count DWORD 5

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
push count
push OFFSET intArray
call SelectSort
mWrite "After SelectSort: "
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

SelectSort PROC, array:PTR DWORD, array_size:DWORD
mov esi, array
mov ecx, array_size
mov eax, 0
L1:
	push ecx
	push esi
	mov eax, [esi]
	mov edi, array
	L2:
		mov ebx, [edi]
		cmp eax, ebx
		JAE NotSwapped
		mov eax, ebx
		mov esi, edi
		NotSwapped:
			add edi, 4
			loop L2
	sub edi, 4
	push edi
	push esi
	call SWAP
	pop esi
	pop ecx
	loop L1
ret
SelectSort ENDP

SWAP PROC
push ebp
mov ebp, esp
mov esi, [ebp + 8]
mov edi, [ebp + 12]
mov eax, [esi]
mov ebx, [edi]

xchg eax, ebx
mov [esi], eax
mov [edi], ebx
mov [ebp + 8], esi
mov [ebp + 12], edi

mov esp, ebp
pop ebp
ret 8
SWAP ENDP

END main