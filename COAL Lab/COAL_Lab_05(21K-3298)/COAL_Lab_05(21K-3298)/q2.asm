INCLUDE Irvine32.inc

.data
array DWORD 8,5,1,2,6

.code
main PROC
mov esi, 0
mov ecx, LENGTHOF array
PRINT1:
	mov eax, array[esi]
	add esi, TYPE array
	call writeInt
	loop PRINT1
call Crlf

mov eax, 0
mov ebx, 0
mov ecx, LENGTHOF array - 1
L1:
	mov esi, 0
	L2:
		cmp esi, (SIZEOF array - (2 * TYPE array))
		jg L3
		mov eax, array[esi]
		mov edx, array[esi + 4]
		cmp eax, edx
		jg swap
		add esi, TYPE array
		jmp L2
	L3:
	loop L1

cmp ecx, 0
je ENDD

swap:
	mov eax, array[esi]
	xchg eax, array[esi + 4]
	mov array[esi], eax
	add esi, TYPE array
	jmp L2

ENDD:
	mov esi, 0
	mov ecx, LENGTHOF array
	PRINT2:
		mov eax, array[esi]
		add esi, TYPE array
		call writeInt
		loop PRINT2
exit
main ENDP
END main