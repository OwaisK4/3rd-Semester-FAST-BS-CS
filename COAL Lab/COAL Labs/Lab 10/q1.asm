TITLE Question 1
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
array DWORD 5,1,7,2,9,3,6,8
count = ($ - array) / TYPE array

.code
main PROC
push OFFSET array
push count
mWrite "Unsorted array: "
call print ; Before Sorting
push OFFSET array
push count
call BubbleSort ; Bubble Sorting
push OFFSET array
push count
mWrite "BubbleSorted array: "
call print ; After Sorting
exit
main ENDP

BubbleSort PROC
push ebp
mov ebp, esp
mov ecx, [ebp + 8]
mov esi, [ebp + 12]
L1:
	push esi
	push ecx
	mov ecx, [ebp + 8]
	dec ecx
	L2:
		mov eax, [esi]
		cmp eax, [esi + 4]
		jbe NotSwapped
		xchg eax, [esi + 4]
		mov [esi], eax
		NotSwapped:
			add esi, 4
		loop L2
	pop ecx
	pop esi
	loop L1
mov esp, ebp
pop ebp
ret 8
BubbleSort ENDP

print PROC
push ebp
mov ebp, esp
mov ecx, [ebp + 8]
mov esi, [ebp + 12]
L2:
	mov eax, [esi]
	call WriteDec
	mWrite " "
	add esi, TYPE array
	loop L2
call Crlf
mov esp, ebp
pop ebp
ret 8
print ENDP

END main