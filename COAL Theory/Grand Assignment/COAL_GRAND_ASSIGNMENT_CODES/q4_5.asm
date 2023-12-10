TITLE QUESTION 4(v)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
intArray SDWORD 60, 4, 17, 45, 7, 69, 21, 33, 96, 81
count DWORD 10
integer SDWORD ?
;SEARCH_RECURSE PROTO, array:PTR SDWORD, arrayLength:DWORD, value:SDWORD
;INVOKE SEARCH_RECURSE, ADDR intArray, count, integer

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
mWrite "Enter integer value to search: "
call ReadInt
mov integer, eax
push integer
push count
push OFFSET intArray
call SEARCH_RECURSE
cmp eax, -1
je NOT_FOUND
mWrite "Given value: "
xchg eax, integer
call WriteDec
xchg eax, integer
mWrite " found at index: "
call WriteDec
call Crlf
jmp ENDD
NOT_FOUND:
	mWrite "Given value not found in array."
	call Crlf
ENDD:
	exit
main ENDP

;SEARCH_RECURSE PROC, array:PTR SDWORD, arrayLength:DWORD, value:SDWORD
SEARCH_RECURSE PROC
push ebp
mov ebp, esp
sub esp, 12
mov ecx, [ebp + 12]
cmp ecx, 0
jle ENDD
mov esi, [ebp + 8]
mov eax, [esi]
cmp eax, [ebp + 16]
je FOUND
mov eax, -1
mov esi, [ebp + 8]
add esi, 4
mov ecx, [ebp + 12]
dec ecx
mov edx, [ebp + 16]

mov [esp + 8], edx
mov [esp + 4], ecx
mov [esp], esi
call SEARCH_RECURSE
jmp ENDD
FOUND:
	mov eax, 10
	sub eax, [ebp + 12]
	add esp, 12
	pop ebp
	ret
ENDD:
	add esp, 12
	pop ebp
	ret
SEARCH_RECURSE ENDP

END main