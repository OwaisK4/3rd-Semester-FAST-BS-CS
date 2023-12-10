TITLE Question 5
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
int_array DWORD 10 DUP(5)
int_array2 DWORD 10 DUP(0)
count DWORD 10

.code
main PROC
mWrite "Original arrays: "
call Crlf
push count
push OFFSET int_array
call PRINT_ARRAY
push count
call Crlf
push OFFSET int_array2
call PRINT_ARRAY

call Crlf
call Crlf
push count
push OFFSET int_array2
push OFFSET int_array
call Load

mWrite "Loaded arrays: "
call Crlf
push count
push OFFSET int_array
call PRINT_ARRAY
call Crlf
push count
push OFFSET int_array2
call PRINT_ARRAY
call Crlf
exit
main ENDP

Load PROC
push ebp
mov ebp, esp
mov esi, [ebp + 8]
mov edi, [ebp + 12]
mov ecx, [ebp + 16]
cld
L1:
	lodsd
	stosd
	loop L1

mov esp, ebp
pop ebp
ret 12
Load ENDP

PRINT_ARRAY PROC, array:DWORD, a_length:DWORD
mov esi, array
mov ecx, a_length
L1:
	mov eax, [esi]
	call WriteDec
	mWrite " "
	add esi, 4
	loop L1
ret
PRINT_ARRAY ENDP
END main